#include <stdio.h>
#include <sys/stat.h>
#include "picopng/picopng.h"

int main(int argc, char **argv)
{
    char *fname = (argc > 1) ? argv[1] : "test.png";
    PNG_info_t *info;
    struct stat statbuf;
    uint32_t insize, outsize;
    FILE *infp, *outfp;
    uint8_t *inbuf;
    uint32_t n;
    
    if (stat(fname, &statbuf) != 0) {
        perror("stat");
        return 1;
    } else if (!statbuf.st_size) {
        printf("file empty\n");
        return 1;
    }
    insize = (uint32_t) statbuf.st_size;
    inbuf = malloc(insize);
    infp = fopen(fname, "rb");
    if (!infp) {
        perror("fopen");
        free(inbuf);
        return 1;
    } else if (fread(inbuf, 1, insize, infp) != insize) {
        perror("fread");
        free(inbuf);
        fclose(infp);
        return 1;
    }
    fclose(infp);
    
    printf("input file: %s (size: %d)\n", fname, insize);
    
    info = PNG_decode(inbuf, insize);
    free(inbuf);
    printf("PNG_error: %d\n", PNG_error);
    if (PNG_error != 0)
        return 1;
    
    printf("width: %d, height: %d\nfirst 16 bytes: ", info->width, info->height);
    for (n = 0; n < 16; n++)
        printf("%02x ", info->image->data[n]);
    printf("\n");
    
    outsize = info->width * info->height * 4;
    printf("image size: %d\n", outsize);
    if (outsize != info->image->size) {
        printf("error: image size doesn't match dimensions\n");
        return 1;
    }
    outfp = fopen("out.bin", "wb");
    if (!outfp) {
        perror("fopen");
        return 1;
    } else if (fwrite(info->image->data, 1, outsize, outfp) != outsize) {
        perror("fwrite");
        fclose(outfp);
        return 1;
    }
    fclose(outfp);
    
#ifdef ALLOC_DEBUG
    png_alloc_node_t *node;
    for (node = png_alloc_head, n = 1; node; node = node->next, n++)
        printf("node %d (%p) addr = %p, size = %zu\n", n, node, node->addr, node->size);
#endif
    png_alloc_free_all(); // also frees info and image data from PNG_decode
    
    return 0;
}

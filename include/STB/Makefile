# Makefile: Create and test a shared library. 
# 
# Usage: make test 
# 
CC = cc
LD = cc
CFLAGS = -O -fno-common
all: libstb.dylib

# Create the shared library. 
# 
stb_image.o: stb_image.c
	$(CC) $(CFLAGS) -c stb_image.c

stb_math.o: stb_math.c
	$(CC) $(CFLAGS) -c stb_math.c
	
stb_truetype.o: stb_truetype.c
	$(CC) $(CFLAGS) -c stb_truetype.c

libstb.dylib: stb_image.o stb_math.o stb_truetype.o
	$(LD) -dynamiclib -install_name libstb.dylib \
	-o libstb.dylib stb_image.o stb_math.o stb_truetype.o

clean: 
	rm -f *.o libstb.dylib
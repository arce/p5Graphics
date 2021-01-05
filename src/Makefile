CC = cc
LD = cc
CFLAGS = -O -fno-common
LDFLAGS = -framework Carbon -framework OpenGL -lglfw -lOpenVG

all: libp5graphics.dylib
	
p5Color.o: p5Color.c
	$(CC) $(CFLAGS) -c p5Color.c -I../include

p5Transform.o: p5Transform.c
	$(CC) $(CFLAGS) -c p5Transform.c -I../include
	
p5Math.o: p5Math.c
	$(CC) $(CFLAGS) -c p5Math.c -I../include

p5Image.o: p5Image.c 
	$(CC) $(CFLAGS) -c p5Image.c -I../include

p5Structure.o: p5Structure.c
	$(CC) $(CFLAGS) -c p5Structure.c -I../include

shFont.o: shFont.c
	$(CC) $(CFLAGS) -c shFont.c -I../include

p5Typography.o: p5Typography.c
	$(CC) $(CFLAGS) -c p5Typography.c -I../include
	
p5Shapes.o: p5Shapes.c
	$(CC) $(CFLAGS) -c p5Shapes.c -I../include

libp5graphics.dylib: p5Color.o p5Transform.o p5Image.o p5Math.o p5Structure.o shFont.o p5Typography.o p5Shapes.o
	$(LD) -dynamiclib -install_name libp5graphics.dylib -o libp5graphics.dylib -lOpenVG p5Color.o p5Transform.o p5Math.o p5Image.o p5Structure.o shFont.o p5Typography.o p5Shapes.o -L.
	
clean:
	rm -f *.o
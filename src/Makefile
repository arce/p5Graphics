CC = gcc

all: libp5graphics.a

p5Environment.o: p5Environment.c
	gcc -fcommon -O -c p5Environment.c -I../include
	
p5Color.o: p5Color.c
	gcc -fcommon -O -c p5Color.c -I../include

p5Transform.o: p5Transform.c
	gcc -fcommon -O -c p5Transform.c -I../include
	
p5Math.o: p5Math.c
	gcc -fcommon -O -c p5Math.c -I../include

p5Image.o: p5Image.c 
	gcc -fcommon -O -c p5Image.c -I../include

p5Structure.o: p5Structure.c
	gcc -fcommon -O -c p5Structure.c -I../include

shFont.o: shFont.c
	gcc -fcommon -O -c shFont.c -I../include

p5Typography.o: p5Typography.c
	gcc -fcommon -O -c p5Typography.c -I../include
	
p5Shapes.o: p5Shapes.c
	gcc -fcommon -O -c p5Shapes.c -I../include

libp5graphics.a: p5Environment.o p5Color.o p5Transform.o p5Image.o p5Structure.o shFont.o p5Typography.o p5Shapes.o
	ar rcs libp5graphics.a p5Environment.o p5Color.o p5Transform.o p5Image.o p5Structure.o shFont.o p5Typography.o p5Shapes.o

libs: libp5graphics.a
	
clean:
	rm -f *.o
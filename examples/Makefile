CC = gcc
# Linux (default)
LDFLAGS = -lGL -lGLU -lglut -lm
CFLAGS = -Wall -std=c99

RM = rm -f

UNAME := $(shell uname)

OS = Windows_NT
# Windows (cygwin)
ifeq "$(OS)" Windows_NT
  LDFLAGS = -lopengl32 -lglu32 -lglut32
  CFLAGS += -D_WIN32
endif

# OS X
ifeq "$(UNAME)" "Darwin"
  LDFLAGS = -framework Carbon -framework OpenGL -framework GLUT
  CFLAGS += -D__APPLE__
endif

all : example1_1 example1_2 example1_3 example1_4 example1_5 example2_1 example3_1 example3_1 example3_2 example3_3 example3_4 example3_5 example3_6 example3_7 example4_1 example4_2 example4_3 example4_4 example4_5 example4_6 example4_7 example4_8 example5_1 example5_2 example5_3 example5_4 example5_5 example5_6 example5_7 example5_8 example5_9 example5_10 example6_1 example6_2 example14_1 example14_2 example14_3 example14_5 example14_6 example14_7 example14_8 example14_9 example14_11 example14_12 example14_13 example14_14 example14_16 example14_17 example17_1 example17_2 example17_3 example17_4 example17_7 example17_8 reference_arc reference_spline reference_curve

example1_1 : example1_1.c
	$(CC) $(CFLAGS) $(LDFLAGS) example1_1.c -o example1_1

example1_2 : example1_2.c
	$(CC) $(CFLAGS) $(LDFLAGS) example1_2.c -o example1_2

example1_3 : example1_3.c
	$(CC) $(CFLAGS) $(LDFLAGS) example1_3.c -o example1_3
	
example1_4 : example1_4.c
	$(CC) $(CFLAGS) $(LDFLAGS) example1_4.c -o example1_4
	
example1_5 : example1_5.c
	$(CC) $(CFLAGS) $(LDFLAGS) example1_5.c -o example1_5
	
example2_1 : example2_1.c
	$(CC) $(CFLAGS) $(LDFLAGS) example2_1.c -o example2_1
	
example3_1 : example3_1.c
	$(CC) $(CFLAGS) $(LDFLAGS) example3_1.c -o example3_1
	
example3_2 : example3_2.c
	$(CC) $(CFLAGS) $(LDFLAGS) example3_2.c -o example3_2
	
example3_3 : example3_3.c
	$(CC) $(CFLAGS) $(LDFLAGS) example3_3.c -o example3_3
	
example3_4 : example3_4.c
	$(CC) $(CFLAGS) $(LDFLAGS) example3_4.c -o example3_4

example3_5 : example3_5.c
	$(CC) $(CFLAGS) $(LDFLAGS) example3_5.c -o example3_5

example3_6 : example3_6.c
	$(CC) $(CFLAGS) $(LDFLAGS) example3_6.c -o example3_6

example3_7 : example3_7.c
	$(CC) $(CFLAGS) $(LDFLAGS) example3_7.c -o example3_7
		
example4_1 : example4_1.c
	$(CC) $(CFLAGS) $(LDFLAGS) example4_1.c -o example4_1
	
example4_2 : example4_2.c
	$(CC) $(CFLAGS) $(LDFLAGS) example4_2.c -o example4_2
	
example4_3 : example4_3.c
	$(CC) $(CFLAGS) $(LDFLAGS) example4_3.c -o example4_3
	
example4_4 : example4_4.c
	$(CC) $(CFLAGS) $(LDFLAGS) example4_4.c -o example4_4
	
example4_5 : example4_5.c
	$(CC) $(CFLAGS) $(LDFLAGS) example4_5.c -o example4_5
	
example4_6 : example4_6.c
	$(CC) $(CFLAGS) $(LDFLAGS) example4_6.c -o example4_6

example4_7 : example4_7.c
	$(CC) $(CFLAGS) $(LDFLAGS) example4_7.c -o example4_7
	
example4_8 : example4_8.c
	$(CC) $(CFLAGS) $(LDFLAGS) example4_8.c -o example4_8
	
example5_1 : example5_1.c
	$(CC) $(CFLAGS) $(LDFLAGS) example5_1.c -o example5_1
	
example5_2 : example5_2.c
	$(CC) $(CFLAGS) $(LDFLAGS) example5_2.c -o example5_2
	
example5_3 : example5_3.c
	$(CC) $(CFLAGS) $(LDFLAGS) example5_3.c -o example5_3

example5_4 : example5_4.c
	$(CC) $(CFLAGS) $(LDFLAGS) example5_4.c -o example5_4
	
example5_5 : example5_5.c
	$(CC) $(CFLAGS) $(LDFLAGS) example5_5.c -o example5_5
	
example5_6 : example5_6.c
	$(CC) $(CFLAGS) $(LDFLAGS) example5_6.c -o example5_6

example5_7 : example5_7.c
	$(CC) $(CFLAGS) $(LDFLAGS) example5_7.c -o example5_7
	
example5_8 : example5_8.c
	$(CC) $(CFLAGS) $(LDFLAGS) example5_8.c -o example5_8

example5_9 : example5_9.c
	$(CC) $(CFLAGS) $(LDFLAGS) example5_9.c -o example5_9
	
example5_10 : example5_10.c
	$(CC) $(CFLAGS) $(LDFLAGS) example5_10.c -o example5_10
	
example6_1 : example6_1.c
	$(CC) $(CFLAGS) $(LDFLAGS) example6_1.c -o example6_1

example6_2 : example6_2.c
	$(CC) $(CFLAGS) $(LDFLAGS) example6_2.c -o example6_2

example14_1 : example14_1.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_1.c -o example14_1

example14_2 : example14_2.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_2.c -o example14_2

example14_3 : example14_3.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_3.c -o example14_3

# example14_4 : example14_4.c
# 	$(CC) $(CFLAGS) $(LDFLAGS) example14_4.c -o example14_4
				
example14_5 : example14_5.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_5.c -o example14_5

example14_6 : example14_6.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_6.c -o example14_6

example14_7 : example14_7.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_7.c -o example14_7
	
example14_8 : example14_8.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_8.c -o example14_8
	
example14_9 : example14_9.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_9.c -o example14_9

example14_10 : example14_10.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_10.c -o example14_10

example14_11 : example14_11.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_11.c -o example14_11	

example14_12 : example14_12.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_12.c -o example14_12
	
example14_13 : example14_13.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_13.c -o example14_13

example14_14 : example14_14.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_14.c -o example14_14

example14_16 : example14_16.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_16.c -o example14_16

example14_17 : example14_17.c
	$(CC) $(CFLAGS) $(LDFLAGS) example14_17.c -o example14_17

example17_1 : example17_1.c
	$(CC) $(CFLAGS) $(LDFLAGS) example17_1.c -o example17_1

example17_2 : example17_2.c
	$(CC) $(CFLAGS) $(LDFLAGS) example17_2.c -o example17_2

example17_3 : example17_3.c
	$(CC) $(CFLAGS) $(LDFLAGS) example17_3.c -o example17_3

example17_4 : example17_4.c
	$(CC) $(CFLAGS) $(LDFLAGS) example17_4.c -o example17_4

example17_7 : example17_7.c
	$(CC) $(CFLAGS) $(LDFLAGS) example17_7.c -o example17_7

example17_8 : example17_8.c
	$(CC) $(CFLAGS) $(LDFLAGS) example17_8.c -o example17_8
	
reference_arc: reference_arc.c
	$(CC) $(CFLAGS) $(LDFLAGS) reference_arc.c -o reference_arc

reference_spline: reference_spline.c
	$(CC) $(CFLAGS) $(LDFLAGS) reference_spline.c -o reference_spline

reference_spline: reference_curve.c
	$(CC) $(CFLAGS) $(LDFLAGS) reference_curve.c -o reference_curve
					
clean :
	$(RM) *.o $(PROG) *.*~
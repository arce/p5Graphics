LIBS  = -framework OpenGL -lOpenVG -lp5graphics -lglfw
CFLAGS = -Wall -I. -I../include -L.
CC = cc
# Should be equivalent to your list of C files, if you don't build selectively
SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(LIBS) -o $@ $< $
clean: 
	rm -f $(PROGS)
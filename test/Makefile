# Linux (default)

RM=rm
SRC_DIR = src
OBJ_DIR = obj

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
EXECS=$(SOURCES:%.c=%)

CFLAGS += -w -I./include 
LDLIBS = -lGL -lGLU -lglut -lglfw -ldl -lOpenVG -lp5graphics

#OS = Windows_NT
# Windows (cygwin)
ifeq ($(OS), Windows_NT)
  CC = x86_64-w64-mingw32-gcc
  LD = x86_64-w64-mingw32-gcc
  LDLIBS = -lopengl32 -lglu32 glfw3.dll -lgdi32 libOpenVG.dll lib5graphics.dll
else
# OS X
ifeq "$(shell uname)" "Darwin"
  LDLIBS = -L. -framework Carbon -framework OpenGL -lOpenVG -lp5graphics -lglfw
endif

endif

.PHONY: all
all: $(EXECS)

$(EXECS):$(OBJECTS)
	$(CC) $(CFLAGS) $< -o $@

.o.: 
	$(CC) $^ $(LDFLAGS) -o $@

.PHONY: clean
clean:
	-@ $(RM) *.o 
	-@ $(RM) $(EXECS)
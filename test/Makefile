# Linux (default)

RM = rm -vf
SRC_DIR = src
OBJ_DIR = obj

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
EXECS = $(SOURCES:%.c=%)

CFLAGS += -w -I./include 
LDLIBS = -lGL -lGLU -lglut -lglfw -ldl -lOpenVG -lp5graphics

OS = Windows_NT
# Windows (cygwin)
ifeq ($(OS), Windows_NT)
  CC = x86_64-w64-mingw32-gcc
  LD = x86_64-w64-mingw32-gcc
  LDLIBS = -L. -lopengl32 -lglu32 -lp5graphics glfw3.dll
else
# OS X
ifeq "$(shell uname)" "Darwin"
  LDLIBS = -L. -framework Carbon -framework OpenGL -lp5graphics -lglfw
endif

endif

.PHONY: all clean

all: $(EXECS)
	
clean:
	$(RM) $(OBJECTS) $(EXECS) *~
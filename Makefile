# Linux (default)
EXE = libp5graphics.a
SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS += -w -Os -fno-common -I./include
LDLIBS = -lGL -lGLU -lglut -ldl

# OS = "Windows_NT"
# Windows (cygwin)
ifeq ($(OS), Windows_NT)
  CC = x86_64-w64-mingw32-gcc
  LD = x86_64-w64-mingw32-gcc
  EXE = libp5graphics.dll
  LDLIBS = -lopengl32 -lglu32 -lgdi32
  LDFLAGS = -shared
else
# OS X
ifeq "$(shell uname)" "Darwin"
  EXE = libp5graphics.dylib
  LDLIBS = -framework Carbon -framework OpenGL
  LDFLAGS = -dynamiclib -undefined suppress -flat_namespace
endif

endif

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
    
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
    
clean:
	$(RM) $(OBJ)

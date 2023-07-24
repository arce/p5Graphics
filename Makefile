# Linux (default)
EXE = lib/libp5graphics.so
SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS += -w -Os -fno-common -I./include
LDLIBS = -lGL -lGLU -lglut -ldl

#OS = Windows_NT
# Windows (cygwin)
ifeq ($(OS), Windows_NT)
  CC = x86_64-w64-mingw32-gcc
  LD = x86_64-w64-mingw32-gcc
  EXE = lib/libp5graphics.dll
  LDLIBS = -L./lib -lglu32 -lopengl32 -lopenvg
  LDFLAGS = -shared
  CFLAGS = -I./include
else
# OS X
ifeq "$(shell uname)" "Darwin"
  EXE = lib/libp5graphics.dylib
  LDLIBS = -L./lib -framework Carbon -framework OpenGL -lopenvg
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

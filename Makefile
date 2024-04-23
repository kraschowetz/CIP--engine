PROJECTNAME = main
OUTPUT_DIR = build

INCLUDE_DIR = -Iinclude/SDL2
LIB_DIR = -Llib

LIBS = -lmingw32 -lSDL2main -lSDL2_image -lSDL2


SRC = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)

all:
	g++ $(SRC) -o $(OUTPUT_DIR)/$(PROJECTNAME) $(INCLUDE_DIR) $(LIB_DIR) $(LIBS)
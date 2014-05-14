 #
 # Author: KK <thumbd03803@gmail.com>
 #
 # Makefile
 #

CXX = g++
CXXFLAG = -Wall -std=c++11 -g

SRC_PATH = $(PWD)/src

# Include flags
INCLUDE = -I $(PWD)/include
INCLUDE += $(shell pkg-config --cflags sdl2)
INCLUDE += $(shell pkg-config --cflags SDL2_image)
INCLUDE += $(shell pkg-config --cflags lua)
INCLUDE += $(shell pkg-config --cflags openal)

# Libs flags
LIB += $(shell pkg-config --libs sdl2)
LIB += $(shell pkg-config --libs SDL2_image)
LIB += $(shell pkg-config --libs lua)

# Object files
OBJ_PATH = $(PWD)/obj
OBJ = main.o window.o timer.o SDLToolBox.o scriptManager.o button.o startScreen.o menuScreen.o gameSelectScreen.o mainGameScreen.o prototypeScreen.o player.o enemy.o

OUT_EXE= rainbow

all: $(OUT_EXE)
	@cowsay "Everything done!!"

$(OUT_EXE): $(addprefix $(OBJ_PATH)/, $(OBJ))
	@echo "    LD    " $(notdir $@)
	@$(CXX) $(addprefix $(OBJ_PATH)/, $(OBJ)) $(CXXFLAG) $(LIB) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo "    CC    " $(notdir $@)
	@$(CXX) -c $< $(CXXFLAG) $(INCLUDE) -o $@

.PHONY: clean
clean:
	rm -frv $(OBJ_PATH)/*.o $(OUT_EXE)

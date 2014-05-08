CXX= g++
CXXFLAG= -Wall -std=c++11 -g

SRC= $(PWD)/src

# Include flags
INCLUDE= -I $(PWD)/include
INCLUDE+= $(shell pkg-config --cflags sdl2)
INCLUDE+= $(shell pkg-config --cflags SDL2_image)
INCLUDE+= $(shell pkg-config --cflags lua)
INCLUDE+= $(shell pkg-config --cflags openal)

# Libs flags
LIB+= $(shell pkg-config --libs sdl2)
LIB+= $(shell pkg-config --libs SDL2_image)
LIB+= $(shell pkg-config --libs lua)

OBJ= main.o window.o timer.o SDLToolBox.o scriptManager.o button.o startScreen.o menuScreen.o gameSelectScreen.o mainGameScreen.o prototypeScreen.o player.o enemy.o

OUT_EXE= rainbow

$(OUT_EXE): $(OBJ)
	@echo "    LD    "$@
	@$(CXX) $(OBJ) $(CXXFLAG) $(LIB) -o $@

%.o: $(SRC)/%.cpp
	@echo "    CC    "$@
	@$(CXX) $< $(CXXFLAG) $(INCLUDE) -c

.PHONY: clean
clean:
	rm -frv *.o $(OUT_EXE)

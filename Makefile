CXX= g++
CXXFLAG= -Wall -std=c++11 -g

SRC= $(PWD)/src
INCLUDE= -I $(PWD)/include
OBJ= main.o window.o timer.o SDLToolBox.o scriptManager.o button.o startScreen.o menuScreen.o prototypeScreen.o
LIB= -lSDL2 -lSDL2main

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

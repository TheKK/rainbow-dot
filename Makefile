CXX= g++
CXXFLAG= -Wall -g

SRC= $(PWD)/src
INCLUDE= -I $(PWD)/include
OBJ= main.o window.o timer.o SDLToolBox.o button.o startScreen.o menuScreen.o
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

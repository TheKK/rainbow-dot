CXX= g++
CXXFLAG= -Wall -g

SRC= $(PWD)/src/*.cpp
INCLUDE= -I $(PWD)/include/
OBJ= main.o window.o timer.o startScreen.o
LIB= -lSDL2 -lSDL2main

OUT_EXE= rainbow

$(OUT_EXE): $(OBJ)
	        $(CXX) $(SRC) $(CXXFLAG) $(INCLUDE) $(LIB) -o $@

%.o: $(PWD)/src/%.cpp 
	        $(CXX) $< $(CXXFLAG) $(INCLUDE) -c

.PHONY: clean
clean:
	        rm -fr *.o $(OUT_EXE)



CXX= g++
CXXFLAG= -Wall

SRC= $(PWD)/src/*.cpp
INCLUDE= -I $(PWD)/include/
OBJ= main.o game.o window.o

LIB= -lSDL2 -lSDL2main

OUT_EXE= rainbow

$(OUT_EXE): $(OBJ)
	        $(CXX) $(SRC) $(CXXFLAG) $(INCLUDE) $(LIB) -g -o $@

%.o: $(PWD)/src/%.cpp 
	        $(CXX) $< $(CXXFLAG) $(INCLUDE) $(LIB) -c

clean:
	        rm -fr *.o



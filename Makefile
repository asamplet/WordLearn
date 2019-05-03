.PHONY:all clean
SF=~/WordLearn/src/
SD=~/WordLearn/bin/
CC=g++
FLAG=-Wall -Werror
EXE=~/WordLearn/build/wl.exe

all: $(EXE)


$(EXE): $(SD)wl.o 
	$(CC) $(FLAG) -o $(EXE) $(SD)wl.o
$(SD)wl.o: 
	$(CC) $(FLAG) -c -o  $(SD)wl.o $(SF)wl.cpp
clean:
	rm -rf $(EXE) $(SD)*.o

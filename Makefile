.PHONY:all clean
SF=~/WordLearn/src
SD=~/WordLearn/build
CC=gcc
FLAG=-Wall -Werror
EXE=~/WordLearn/bin/wl.exe

all: $(EXE)


$(EXE): $(SD) wl.o $(main.o)
	$(CC) -g $(FLAG) -o $(EXE) $(SD)wl.o  -lm
$(SD)wl.o: $(SF)wl.cpp
	$(CC) -o $(FLAG) -c -o $(SD)wl.o $(SF)wl.cpp -lm
clean:
	rm -rf $(EXE) $(SD)*.o

.PHONY:all clean
CC=gcc
FLAG=-Wall -Werror
SF=src/
SD=build/
EXE=bin/wl.exe

all: $(EXE)


$(EXE): $(SD)wl.o $(SD)voc.o
	$(CC) $(FLAG) -o $(EXE) $(SD)wl.o $(SD)voc.o -lm

$(SD)wl.o: $(SF)wl.cpp
	$(CC) $(FLAG) -c -o  $(SD)wl.o $(SF)wl.cpp -lm

$(SD)voc.o: $(SF)voc.cpp
	$(CC) $(FLAG) -c -o  $(SD)voc.o $(SF)voc.cpp -lm

clean:
	rm -rf $(EXE) $(SD)*.o

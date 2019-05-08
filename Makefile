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
	$(CC) $(FLAG) -o $(SD)wl.o -c $(SF)wl.cpp -lm

$(SD)voc.o: $(SF)voc.cpp
	$(CC) $(FLAG) -o $(SD)voc.o -c $(SF)voc.cpp -lm

clean:
	rm -rf $(EXE) $(SD)*.o

.PHONY:clean all 
CC=gcc
FLAG=-Wall -Werror
SF=src/
SD=build/
EXE=bin/wl.exe

all: $(EXE)


$(EXE): $(SD)wl.o $(SD)voc.o $(SD)learn.o
	$(CC) $(FLAG) -o $(EXE) $(SD)wl.o $(SD)voc.o $(SD)learn.o -lm

$(SD)wl.o: $(SF)wl.cpp
	$(CC) $(FLAG) -o $(SD)wl.o -c $(SF)wl.cpp -lm

$(SD)voc.o: $(SF)voc.cpp
	$(CC) $(FLAG) -o $(SD)voc.o -c $(SF)voc.cpp -lm

$(SD)learn.o: $(SF)learn.cpp
	$(CC) $(FLAG) -o $(SD)learn.o -c $(SF)learn.cpp -lm

clean:
	rm -rf $(EXE) $(SD)*.o

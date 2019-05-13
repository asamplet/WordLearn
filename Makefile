.PHONY:clean all 
CC=gcc
FLAG=-Wall -Werror
SF=src/
SD=build/
EXE=bin/wl.exe

all: $(EXE)


$(EXE): $(SD)main.o $(SD)wl.o $(SD)voc.o $(SD)learn.o $(SD)voc1.o $(SD)learn1.o
	$(CC) $(FLAG) -o $(EXE) $(SD)main.o $(SD)wl.o $(SD)voc.o $(SD)learn.o $(SD)voc1.o $(SD)learn1.o -lm

$(SD)main.o: $(SF)main.cpp
	$(CC) $(FLAG) -o $(SD)main.o -c $(SF)main.cpp -lm

$(SD)wl.o: $(SF)wl.cpp
	$(CC) $(FLAG) -o $(SD)wl.o -c $(SF)wl.cpp -lm

$(SD)voc.o: $(SF)voc.cpp
	$(CC) $(FLAG) -o $(SD)voc.o -c $(SF)voc.cpp -lm

$(SD)learn.o: $(SF)learn.cpp
	$(CC) $(FLAG) -o $(SD)learn.o -c $(SF)learn.cpp -lm

$(SD)voc1.o: $(SF)voc1.cpp
	$(CC) $(FLAG) -o $(SD)voc1.o -c $(SF)voc1.cpp -lm

$(SD)learn1.o: $(SF)learn1.cpp
	$(CC) $(FLAG) -o $(SD)learn1.o -c $(SF)learn1.cpp -lm

clean:
	rm -rf $(EXE) $(SD)*.o

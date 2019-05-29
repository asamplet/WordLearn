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


GTEST_DIR = googletest

TEST_DIR = googletest/src/

USER_DIR_O = build/test/

GTEST_LIB_DIR = .

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Werror -Wextra -pthread -std=c++11

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

TESTS = bin/testprog.exe

test : build/test $(TESTS)

build/test:
	mkdir build/test -p

$(TESTS) : $(USER_DIR_O)voc.o $(USER_DIR_O)voc1.o $(USER_DIR_O)wl.o $(USER_DIR_O)test.o 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -L$(GTEST_LIB_DIR) -lgtest_main -lpthread $^ -o $@

$(USER_DIR_O)voc.o : $(SF)voc.cpp $(SF)wordlearn.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SF)voc.cpp -o $@

$(USER_DIR_O)voc1.o : $(SF)voc1.cpp $(SF)wordlearn.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SF)voc1.cpp -o $@

$(USER_DIR_O)wl.o: $(SF)wl.cpp $(SF)wordlearn.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SF)wl.cpp -o $@

$(USER_DIR_O)test.o : $(TEST_DIR)test.cpp $(SF)wordlearn.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)test.cpp -o $@


clean :
	rm -rf $(TESTS) $(EXE) $(SD)*.o $(USER_DIR_O)*.o

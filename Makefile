.PHONY: all clean test

CC = gcc

FLAG = -Wall -Werror

SF = gavnovtoroe/gavnovtoroe/

SD = build/src/

EXE = bin/wl.exe

all: build/src $(EXE)

build/src:
	mkdir build/src -p

$(EXE): $(SD)main.o $(SD)wl.o $(SD)Voc.o $(SD)Voc1.o $(SF)Learn.o $(SF)Learn1.o
	$(CC) $(FLAG) -o $(EXE) $(SD)main.o $(SD)wl.o $(SD)Voc.o $(SD)Voc1.o $(SF)Learn.o $(SF)Learn1.o

$(SD)main.o: $(SF)main.cpp
	$(CC) $(FLAG) -o $(SD)main.o -c $(SF)main.cpp 

$(SD)wl.o: $(SF)wl.cpp
	$(CC) $(FLAG) -o $(SD)wl.o -c $(SF)wl.cpp 

$(SD)Voc.o: $(SF)Voc.cpp
	$(CC) $(FLAG) -o $(SD)Voc.o -c $(SF)Voc.cpp 

$(SD)Voc1.o: $(SF)Voc1.cpp
	$(CC) $(FLAG) -o $(SD)Voc1.o -c $(SF)Voc1.cpp 

$(SD)learn.o: $(SF)learn.cpp
	$(CC) $(FLAG) -o $(SD)learn.o -c $(SF)learn.cpp

$(SD)learn1.o: $(SF)learn1.cpp
	$(CC) $(FLAG) -o $(SD)learn1.o -c $(SF)learn1.cpp




GTEST_DIR = googletest

TEST_DIR = googletest/src/

USER_DIR_O = build/test/

GTEST_LIB_DIR = googletest/

GTEST_LIBS = libgtest.a libgtest_main.a

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Werror -Wextra -pthread -std=c++11

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

TESTS = bin/testprog.exe

test : build/test $(TESTS)

build/test:
	mkdir build/test -p

$(TESTS) : $(USER_DIR_O)test.o $(USER_DIR_O)Voc.o $(USER_DIR_O)Voc1.o $(USER_DIR_O)wl.o 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -L $(GTEST_LIB_DIR)libs -lgtest_main -lpthread $^ -o $@

$(USER_DIR_O)test.o : $(TEST_DIR)test.cpp $(SF)WordLearn.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)test.cpp -o $@

$(USER_DIR_O)Voc.o : $(SF)Voc.cpp $(SF)WordLearn.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SF)Voc.cpp -o $@

$(USER_DIR_O)Voc1.o : $(SF)Voc1.cpp $(SF)WordLearn.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SF)Voc1.cpp -o $@

$(USER_DIR_O)wl.o: $(SF)wl.cpp $(SF)WordLearn.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SF)wl.cpp -o $@


clean :
	rm -rf $(TESTS) $(EXE) $(SD)*.o $(USER_DIR_O)*.o

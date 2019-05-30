.PHONY: all clean test

CC = gcc

FLAG = -Wall -Werror

SF = gavnovtoroe/gavnovtoroe/

SD = build/src/

EXE = bin/wl.exe

all: build/src $(EXE)

build/src:
	mkdir build/src -p

$(EXE): $(SD)main.o $(SD)wl.o $(SD)Voc.o $(SD)Voc1.o $(SD)Learn.o $(SD)Learn1.o
	$(CC) $(FLAG) -o $(EXE) $(SD)main.o $(SD)wl.o $(SD)Voc.o $(SD)Voc1.o $(SD)Learn.o $(SD)Learn1.o

$(SD)main.o: $(SF)main.cpp
	$(CC) $(FLAG) -o $(SD)main.o -c $(SF)main.cpp 

$(SD)wl.o: $(SF)wl.cpp
	$(CC) $(FLAG) -o $(SD)wl.o -c $(SF)wl.cpp 

$(SD)Voc.o: $(SF)Voc.cpp
	$(CC) $(FLAG) -o $(SD)Voc.o -c $(SF)Voc.cpp 

$(SD)Voc1.o: $(SF)Voc1.cpp
	$(CC) $(FLAG) -o $(SD)Voc1.o -c $(SF)Voc1.cpp 

$(SD)Learn.o: $(SF)Learn.cpp
	$(CC) $(FLAG) -o $(SD)Learn.o -c $(SF)Learn.cpp

$(SD)Learn1.o: $(SF)Learn1.cpp
	$(CC) $(FLAG) -o $(SD)Learn1.o -c $(SF)Learn1.cpp



GTEST_DIR = googletest

TEST_DIR = googletest/src/

USER_DIR_O = build/test/

GTEST_LIB_DIR = .

USER_DIR_b = bin/

GTEST_LIBS = libgtest.a libgtest_main.a

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Werror -Wextra -pthread -std=c++11

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

TESTS = bin/testprog.exe

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

test : build/test $(GTEST_LIBS) $(TESTS)

build/test:
	mkdir build/test -p

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

libgtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

libgtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^


$(TESTS) : $(USER_DIR_O)test.o $(USER_DIR_O)Voc.o $(USER_DIR_O)Voc1.o $(USER_DIR_O)wl.o 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -L$(GTEST_LIB_DIR) -lgtest_main -lpthread $^ -o $@

$(USER_DIR_O)test.o : $(TEST_DIR)test.cpp $(SF)WordLearn.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)test.cpp -o $@

$(USER_DIR_O)Voc.o : $(SF)Voc.cpp $(SF)WordLearn.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SF)Voc.cpp -o $@

$(USER_DIR_O)Voc1.o : $(SF)Voc1.cpp $(SF)WordLearn.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SF)Voc1.cpp -o $@

$(USER_DIR_O)wl.o: $(SF)wl.cpp $(SF)WordLearn.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SF)wl.cpp -o $@


clean :
	rm -rf $(TESTS) $(EXE) $(SD)*.o $(USER_DIR_O)*.o $(GTEST_LIB_DIR)/*.o

CFLAGS = -g

CPP=g++
AR=ar
LIB=libbiginteger.a
TESTS=tests.out

.PHONY: all tests clean

all: $(LIB) tests

$(LIB): biginteger.o
	$(AR) rsv $(LIB) biginteger.o

biginteger.o: biginteger.cpp biginteger.h
	$(CPP) $(CFLAGS) biginteger.cpp -c

tests: $(TESTS)

$(TESTS): $(LIB) tests.cpp
	$(CPP) $(CFLAGS) tests.cpp -lbiginteger -L. -o $(TESTS)

clean:
	rm -f *.o *.a *.exe *.out

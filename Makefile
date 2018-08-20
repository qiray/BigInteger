CFLAGS = -O3 -Wall

CPP=g++
AR=ar
LIB=libbiginteger.a
TESTS=tests.out

ifeq ($(DEBUG),true) 
LOG_EXCEPTIONS=-DDEBUG_EXCEPTIONS
else
LOG_EXCEPTIONS=
endif

.PHONY: all tests clean

all: $(LIB) tests

$(LIB): biginteger.o
	$(AR) rsv $(LIB) biginteger.o

biginteger.o: biginteger.cpp *.h
	$(CPP) $(LOG_EXCEPTIONS) $(CFLAGS) biginteger.cpp -c 

tests: $(TESTS)

$(TESTS): $(LIB) tests.cpp
	$(CPP) $(CFLAGS) tests.cpp -lbiginteger -L. -o $(TESTS)

clean:
	rm -f *.o *.a *.exe *.out

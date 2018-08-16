CFLAGS = -g

CPP=g++
LIB=libbiginteger.a

all: $(LIB) tests

$(LIB): biginteger.o
	$(AR) rsv $(LIB) biginteger.o
	
biginteger.o: biginteger.cpp biginteger.h
	$(CPP) $(CFLAGS) biginteger.cpp -c

tests: $(LIB) tests.cpp
	$(CPP) $(CFLAGS) tests.cpp -lbiginteger -L. -o tests.out
	
clean:
	rm -f *.o *.a *.exe *.out

CFLAGS = -O3 -Wall

ifeq ($(PLATFORM), x86)
	CFLAGS += -m32
	POSTFIX=x86
else
	POSTFIX=x64
endif

ifeq ($(OS),win)
	CXX=i686-w64-mingw32-g++ 
	LIB=$(LIB_WIN)
	TESTS=tests.exe
else
	LIB=$(LIB_NIX)
	TESTS=tests.out
endif

ifeq ($(STD), c++03)
	CFLAGS += -D_GLIBCXX_USE_CXX11_ABI=0 -std=c++03
endif

LIB_NIX=libbiginteger-$(POSTFIX).a
LIB_WIN=biginteger-$(POSTFIX).dll

ifeq ($(NO_DEBUG),true)
	LOG_EXCEPTIONS=
else
	LOG_EXCEPTIONS=-DDEBUG_EXCEPTIONS
endif

.PHONY: all tests clean

all: $(LIB) tests

$(LIB_NIX): biginteger.o
	$(AR) rsv $(LIB) biginteger.o

$(LIB_WIN): biginteger.o
	$(CXX) -o $(LIB_WIN) -s -shared biginteger.o -Wl,--subsystem,windows

biginteger.o: biginteger.cpp *.h
	$(CXX) $(LOG_EXCEPTIONS) $(CFLAGS) biginteger.cpp -c

tests: $(TESTS)

notest: $(LIB) 

$(TESTS): $(LIB) tests.cpp
	$(CXX) $(CFLAGS) tests.cpp -lbiginteger-$(POSTFIX) -L. -o $(TESTS)

clean:
	rm -f *.o *.a *.exe *.out *.dll

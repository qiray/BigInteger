CFLAGS = -O3 -Wall

ifeq ($(PLATFORM), x86)
	CFLAGS += -m32
	BUILD=x86
else
	BUILD=x64
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
	RELEASE_PATH=Release/old
else
	RELEASE_PATH=Release/new
endif

LIB_NIX=libbiginteger-$(BUILD).a
LIB_WIN=biginteger-$(BUILD).dll

CMD_MACROS= -DBUILD='"$(BUILD)"'

ifneq ($(NO_DEBUG),true)
	CMD_MACROS += -DDEBUG_EXCEPTIONS
endif

.PHONY: all tests clean

all: $(LIB) tests
	mkdir -p $(RELEASE_PATH)
	cp $(LIB) $(RELEASE_PATH)/$(LIB)
	cp *.h $(RELEASE_PATH)/

$(LIB_NIX): biginteger.o
	$(AR) rsv $(LIB) biginteger.o

$(LIB_WIN): biginteger.o
	$(CXX) -o $(LIB_WIN) -s -shared biginteger.o -Wl,--subsystem,windows

biginteger.o: biginteger.cpp *.h
	$(CXX) $(CMD_MACROS) $(CFLAGS) biginteger.cpp -c

tests: $(TESTS)

notest: $(LIB) 

$(TESTS): $(LIB) tests.cpp
	$(CXX) $(CFLAGS) tests.cpp -lbiginteger-$(BUILD) -L. -o $(TESTS)

clean:
	rm -f *.o *.a *.exe *.out *.dll

allclean: clean
	rm -rf Release/*

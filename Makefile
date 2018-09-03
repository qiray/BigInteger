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
	OS=linux
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

ARCHIVE_NAME=$(OS)-$(BUILD).zip

.PHONY: all tests clean release

all: $(LIB) tests
	mkdir -p $(RELEASE_PATH)
	cp $(LIB) $(RELEASE_PATH)/$(LIB)
	cp *.h $(RELEASE_PATH)/

release: all
	cd $(RELEASE_PATH); \
	rm -f $(ARCHIVE_NAME); \
	zip $(ARCHIVE_NAME) *.h $(LIB)

LIB_CPP=biginteger.cpp bigintegerversion.cpp
LIB_OBJ=$(patsubst %.cpp,%.o,$(wildcard $(LIB_CPP)))

$(LIB_NIX): $(LIB_OBJ)
	$(AR) rsv $(LIB) $(LIB_OBJ)

$(LIB_WIN): $(LIB_OBJ)
	$(CXX) -o $(LIB_WIN) -s -shared $(LIB_OBJ) -Wl,--subsystem,windows

.cpp.o: #convert cpp files to objects
	$(CXX) -c $(CMD_MACROS) $(CFLAGS) $< -o $@

tests: $(TESTS)

notest: $(LIB) 

$(TESTS): $(LIB) tests.cpp
	$(CXX) $(CFLAGS) tests.cpp -lbiginteger-$(BUILD) -L. -o $(TESTS)

clean:
	rm -f *.o *.gch *.a *.exe *.out *.dll

allclean: clean
	rm -rf Release/*

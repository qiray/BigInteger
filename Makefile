CFLAGS = -O3 -Wall

ifeq ($(PLATFORM), x86)
	CFLAGS += -m32
	BUILD=x86
else
	BUILD=x64
endif

ifeq ($(OS),win)
	CXX=i686-w64-mingw32-g++
	TESTS=tests.exe
	RELEASE_PATH=Release/win
else
	OS = $(shell bash check_os.sh)
	TESTS=tests.out
	RELEASE_PATH=Release/$(OS)
endif

ifeq ($(STD), c++03)
	CFLAGS += -D_GLIBCXX_USE_CXX11_ABI=0 -std=c++03
	RELEASE_PATH:=$(RELEASE_PATH)/std03
else
	RELEASE_PATH:=$(RELEASE_PATH)/std11
endif

LIB=libbiginteger-$(BUILD).a

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

$(LIB): $(LIB_OBJ)
	$(AR) rsv $(LIB) $(LIB_OBJ)

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

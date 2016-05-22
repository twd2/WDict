LS = ls
RM = rm -f
CP = cp
CAT = cat
SLASH = /
EXE_POSTFIX = 
DSO_POSTFIX = .so

OS_NAME = $(shell uname)

ifeq ($(OS_NAME),Linux)
	DSO_POSTFIX = .so
else

ifeq ($(OS_NAME),Darwin)
	DSO_POSTFIX = .dylib
else
	# May be Windows
	OS_NAME = Windows
	WIN32 = 1
	LS = dir /b
	RM = del /f
	CP = copy
	CAT = type
	SLASH = \\
	DSO_POSTFIX = .dll
	EXE_POSTFIX = .exe
	ICONV = tools\\iconv\\iconv.exe
endif

-include config.personal
-include ..$(SLASH)config.personal

endif

ifdef DEBUG
	CC_DBG_FLAGS = -g -DDEBUG
else
	CC_DBG_FLAGS = -O2 -D__NO_INLINE__
endif

SOURCES := $(shell $(LS) *.cpp)
DEPS := $(SOURCES:.cpp=.d)
HEADERS := $(shell $(LS) *.h *.hpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))

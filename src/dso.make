include ../config.make

CC_FLAGS = $(CC_DBG_FLAGS) -fPIC -Wall -std=c++11

.PHONY: all
all: $(PROJECT).$(DSO_POSTFIX)

$(PROJECT).$(DSO_POSTFIX): $(PROJECT).o $(OBJECTS)
	g++ -shared -fPIC -o $@ $^

$(PROJECT).o: $(PROJECT).cpp $(HEADERS)
	g++ $(CC_FLAGS) -o $@ -c $<

%.o: %.cpp %.h
	g++ $(CC_FLAGS) -o $@ -c $<

.PHONY: clean
clean:
	-$(RM) *.o $(PROJECT).$(DSO_POSTFIX)

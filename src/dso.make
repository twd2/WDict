include ../config.make

CC_FLAGS = $(CC_DBG_FLAGS) -fPIC -Wall -std=c++11

.PHONY: all
all: $(PROJECT)$(DSO_POSTFIX)

-include $(DEPS)

$(PROJECT)$(DSO_POSTFIX): $(OBJECTS)
	g++ -shared -fPIC -o $@ $^

%.o: %.cpp
	g++ $(CC_FLAGS) -MD -MM -MP -c $<
	g++ $(CC_FLAGS) -o $@ -c $<

.PHONY: clean
clean:
	-$(RM) *.o *.d $(PROJECT)$(DSO_POSTFIX)

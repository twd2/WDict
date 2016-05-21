include ../config.make

CC_FLAGS = $(CC_DBG_FLAGS) -fPIC -Wall -std=c++11 $(CXXFLAGS)

.PHONY: all
all: $(PROJECT)$(DSO_POSTFIX)

-include $(DEPS)

$(PROJECT)$(DSO_POSTFIX): $(OBJECTS)
	$(CXX) -shared -fPIC -o $@ $^

%.o: %.cpp
	$(CXX) $(CC_FLAGS) -MMD -MP -c $<
	$(CXX) $(CC_FLAGS) -o $@ -c $<

.PHONY: clean
clean:
	-$(RM) *.o *.d $(PROJECT)$(DSO_POSTFIX)

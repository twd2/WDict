include ../config.make

ICONV := ..$(SLASH)$(ICONV)

CC_FLAGS = $(CC_DBG_FLAGS) -fPIC -Wall -std=c++11 $(CXXFLAGS)

.PHONY: all
all: $(PROJECT)$(DSO_POSTFIX)

-include $(DEPS)

$(PROJECT)$(DSO_POSTFIX): $(OBJECTS)
	$(CXX) -shared -fPIC -o $@ $^

%.o: %.cpp
	$(CXX) $(CC_FLAGS) -MMD -MP -c $<
ifdef WIN32
	$(ICONV) -f UTF-8 -t GBK $< > $<.win.cc
	$(CXX) $(CC_FLAGS) -o $@ -c $<.win.cc
else
	$(CXX) $(CC_FLAGS) -o $@ -c $<
endif

.PHONY: clean
clean:
	-$(RM) *.win.cc *.o *.d $(PROJECT)$(DSO_POSTFIX)

include config.make

PROJECT = wdict

CC_FLAGS = -I./libtextdb -I./libdict -I./libui $(CC_DBG_FLAGS) -Wall -std=c++11
LD_FLAGS = -L./libtextdb -L./libdict -L./libui
LD_LIBS = -ltextdb -ldict -lui

.PHONY: all
all: libtextdb_ libdict_ libui_ resources $(PROJECT)$(EXE_POSTFIX)

-include $(DEPS)

$(PROJECT)$(EXE_POSTFIX): $(OBJECTS)
	g++ $(LD_FLAGS) -o $@ $^ $(LD_LIBS)

%.o: %.cpp
	g++ $(CC_FLAGS) -MMD -MP -c $<
ifdef WIN32
	$(ICONV) -f UTF-8 -t GBK $< > $<.win.cc
	g++ $(CC_FLAGS) -o $@ -c $<.win.cc
else
	g++ $(CC_FLAGS) -o $@ -c $<
endif

..$(SLASH)src$(SLASH)%.txt: ..$(SLASH)res$(SLASH)%.txt
ifdef WIN32
	$(ICONV) -f UTF-8 -t GBK $< > $@
else
	$(CP) $< $@
endif

lib%_: lib%
	cd $< && make && $(CP) $<$(DSO_POSTFIX) ..

.PHONY: resources
resources: ..$(SLASH)src$(SLASH)dict.txt ..$(SLASH)src$(SLASH)level.txt ..$(SLASH)src$(SLASH)sentences.txt
	

.PHONY: release
release: all
	-mkdir ..$(SLASH)release
	-mkdir ..$(SLASH)release$(SLASH)$(OS_NAME)
	$(CP) *$(DSO_POSTFIX) ..$(SLASH)release$(SLASH)$(OS_NAME)$(SLASH)
	$(CP) $(PROJECT)$(EXE_POSTFIX) ..$(SLASH)release$(SLASH)$(OS_NAME)$(SLASH)
	$(CP) *.txt ..$(SLASH)release$(SLASH)$(OS_NAME)$(SLASH)
ifeq ($(OS_NAME),Linux)
	$(CP) run_on_linux ..$(SLASH)release$(SLASH)$(OS_NAME)$(SLASH)
endif

.PHONY: clean
clean:
	-$(RM) *.o *.d *.win.cc *.txt $(PROJECT)$(EXE_POSTFIX)
	-$(RM) *$(DSO_POSTFIX)
	cd libtextdb && make clean
	cd libdict && make clean
	cd libui && make clean

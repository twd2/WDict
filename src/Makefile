include config.make

PROJECT = wdict

CC_FLAGS = -I./libtextdb -I./libdict -I./libui $(CC_DBG_FLAGS) -Wall -std=c++11 $(CXXFLAGS)
LD_FLAGS = -L./libtextdb -L./libdict -L./libui
LD_LIBS = -ltextdb -ldict -lui

.PHONY: all
all: resources $(PROJECT)$(EXE_POSTFIX)

-include $(DEPS)

$(PROJECT)$(EXE_POSTFIX): $(OBJECTS) libtextdb_ libdict_ libui_
	$(CXX) $(LD_FLAGS) -o $@ $(OBJECTS) $(LD_LIBS)

%.o: %.cpp
	$(CXX) $(CC_FLAGS) -MMD -MP -c $<
ifdef WIN32
	$(ICONV) -f UTF-8 -t GBK $< > $<.win.cc
	$(CXX) $(CC_FLAGS) -o $@ -c $<.win.cc
else
	$(CXX) $(CC_FLAGS) -o $@ -c $<
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
ifdef WIN32
	cd ..$(SLASH)release && $(RM) $(OS_NAME).7z && 7z a -r $(OS_NAME).7z $(OS_NAME)/*
else
	cd ..$(SLASH)release && $(TAR) cJvf $(OS_NAME).tar.xz $(OS_NAME)$(SLASH)*
endif

.PHONY: clean
clean:
	-$(RM) *.o *.d *.win.cc *.txt $(PROJECT)$(EXE_POSTFIX)
	-$(RM) *$(DSO_POSTFIX)
	cd libtextdb && make clean
	cd libdict && make clean
	cd libui && make clean

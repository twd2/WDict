include config.make

PROJECT = wdict

CC_FLAGS = -I./libtextdb -I./libdict -I./libui $(CC_DBG_FLAGS) -Wall -std=c++11
LD_FLAGS = -L./libtextdb -L./libdict -L./libui
LD_LIBS = -ltextdb -ldict -lui

.PHONY: all
all: libtextdb_ libdict_ libui_ resources $(PROJECT)

-include $(DEPS)

$(PROJECT): $(PROJECT).o $(OBJECTS)
	g++ $(LD_FLAGS) -o $@ $^ $(LD_LIBS)

%.o: %.cpp %.h
	g++ $(CC_FLAGS) -MD -MM -MP -c $<
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
	cd $< && make && $(CP) $<.$(DSO_POSTFIX) ..

.PHONY: resources
resources: ..$(SLASH)src$(SLASH)dict.txt ..$(SLASH)src$(SLASH)level.txt ..$(SLASH)src$(SLASH)sentences.txt
	

.PHONY: clean
clean:
	-$(RM) *.o *.d *.win.cc dict.txt level.txt sentences.txt $(PROJECT) $(PROJECT).exe *.$(DSO_POSTFIX)
	cd libtextdb && make clean
	cd libdict && make clean
	cd libui && make clean

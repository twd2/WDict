include config.make

PROJECT = wdict

CC_FLAGS = -I./libtextdb -I./libdict -g -Wall -std=c++11
LD_FLAGS = -L./libtextdb -L./libdict
LD_LIBS = -ltextdb -ldict

.PHONY: all
all: libtextdb.$(DSO_POSTFIX) libdict.$(DSO_POSTFIX) $(PROJECT)

$(PROJECT): $(PROJECT).o $(OBJECTS)
	g++ $(LD_FLAGS) -o $@ $^ $(LD_LIBS)

main.o: main.cpp $(HEADERS)
	g++ $(CC_FLAGS) -o $@ -c $<

%.o: %.cpp %.h
	g++ $(CC_FLAGS) -o $@ -c $<

.PHONY: lib%.$(DSO_POSTFIX)
lib%.$(DSO_POSTFIX): lib%
	cd $< && make
	$(CP) $<$(SLASH)$@ .

.PHONY: clean
clean:
	-$(RM) *.o $(PROJECT) *.$(DSO_POSTFIX)
	cd libtextdb && make clean
	cd libdict && make clean

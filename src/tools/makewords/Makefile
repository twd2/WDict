include ../../config.make

PROJECT = makewords

CC_FLAGS = -I../../libtextdb -I../../libdict $(CC_DBG_FLAGS) -Wall -std=c++11
LD_FLAGS = -L../../libtextdb -L../../libdict
LD_LIBS = -ltextdb -ldict

.PHONY: all
all: libtextdb libdict $(PROJECT)

$(PROJECT): $(PROJECT).o $(OBJECTS)
	g++ $(LD_FLAGS) -o $@ $^ $(LD_LIBS)

main.o: main.cpp $(HEADERS)
	g++ $(CC_FLAGS) -o $@ -c $<

%.o: %.cpp %.h
	g++ $(CC_FLAGS) -o $@ -c $<

lib%: ..$(SLASH)..$(SLASH)lib%
	cd $< && make
	$(CP) $<$(SLASH)$@.$(DSO_POSTFIX) .

.PHONY: clean
clean:
	-$(RM) *.o $(PROJECT) $(PROJECT).exe *.$(DSO_POSTFIX)
	cd libtextdb && make clean
	cd libdict && make clean

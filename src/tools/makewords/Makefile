include ../../config.make

PROJECT = makewords

CC_FLAGS = -I..$(SLASH)..$(SLASH)libtextdb -I..$(SLASH)..$(SLASH)libdict $(CC_DBG_FLAGS) -Wall -std=c++11
LD_FLAGS = -L..$(SLASH)..$(SLASH)libtextdb -L..$(SLASH)..$(SLASH)libdict
LD_LIBS = -ltextdb -ldict

.PHONY: all
all: libtextdb libdict $(PROJECT)$(EXE_POSTFIX)

$(PROJECT)$(EXE_POSTFIX): $(OBJECTS)
	g++ $(LD_FLAGS) -o $@ $^ $(LD_LIBS)

%.o: %.cpp
	g++ $(CC_FLAGS) -MMD -MP -c $<
	g++ $(CC_FLAGS) -o $@ -c $<

lib%: ..$(SLASH)..$(SLASH)lib%
	cd $< && make
	$(CP) $<$(SLASH)$@$(DSO_POSTFIX) .

.PHONY: clean
clean:
	-$(RM) *.o *.d $(PROJECT)$(EXE_POSTFIX) *$(DSO_POSTFIX)
	cd ..$(SLASH)..$(SLASH)libtextdb && make clean
	cd ..$(SLASH)..$(SLASH)libdict && make clean

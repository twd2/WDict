include ../src/config.make

SOURCES := $(shell $(LS) *.md)

all: combined_design.md combined_usage.md
	

combined_design.md: $(SOURCES)
	$(CAT) req.md > $@
	$(CAT) style.md >> $@
	$(CAT) libtextdb_design.md >> $@
	$(CAT) libui_design.md >> $@
	$(CAT) libdict_design.md >> $@
	$(CAT) design.md >> $@

combined_usage.md: $(SOURCES)
	$(CAT) building.md > $@
	$(CAT) usage.md >> $@
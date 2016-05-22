.PHONY: all
all: exe doc
	

.PHONY: release
release: all
	cd src/ && make release

.PHONY: exe
exe:
	-# Building executables.
	cd src/ && make

.PHONY: doc
doc:
	-# Building documentations.
	cd docs/ && make

.PHONY: clean
clean:
	-# Cleaning.
	cd src/ && make clean
	cd docs/ && make clean
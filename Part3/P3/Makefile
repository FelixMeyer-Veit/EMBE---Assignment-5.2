# This is the default target, which will be built when
# you invoke make
.PHONY: all
all: bin/command
# This rule tells make how to build hello from hello.cpp
bin/command: src/command.c
	g++ -o bin/command src/command.c

# This rule tells make to copy hello to the binaries subdirectory,
# creating it if necessary
.PHONY: install
install: 
	mkdir -p bin 
	cp -p bin/command bin

# This rule tells make to delete hello
.PHONY: clean
clean: 
	rm -f bin/command
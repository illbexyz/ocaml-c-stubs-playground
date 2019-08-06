.PHONY: all compile_lib compile format install run test clean

all: compile_lib compile

compile_lib:
	make -C libplayground

compile:
	dune build src/main.exe

format:
	dune build @fmt --auto-promote

install:
	make -C libplayground install

test:
	dune runtest

clean:
	make -C libplayground clean
	dune clean
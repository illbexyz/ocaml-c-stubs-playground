.PHONY: all compile format test clean

all: compile test

compile:
	dune build src/main.exe

format:
	dune build @fmt --auto-promote

test:
	dune runtest

clean:
	dune clean
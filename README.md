# OCaml-C FFI Bindings Playground

This playground is meant to provide and easy-to-use environment to create a C library and its stubs for OCaml.

## Project Structure

The project is composed by two main components:
- the `playground` C library
- an OCaml `dune` project containing a library which implements the bindings of the `playground` C library.

```bash
.
|-- libplayground               # The C library
|   |-- src                     #   Contains .c files
|   |-- include                 #   Contains .h files
|   |-- Makefile                #   Makefile containing instruction to build
|                               #   the static (.a) and shared (.so) libs
|
|-- src                         # The dune OCaml project
|   |-- main.ml                 #   A .ml file which can use the playground lib
|   |-- playground              #   The library implementing the C FFI
|   |   |-- playground_stubs.c  #     C stubs of the playground library
|   |   |-- playground.ml       #     OCaml part of the bindings: it contains
|                               #     the "external" declarations and tests
|-- dune-project
|-- Makefile                    # A convenience Makefile to build both the 
|                               # libplayground lib and the OCaml project
|
|-- run.sh                      # Handy script to launch the Main module and to
                                # run the tests
```

The main files are:
- `libplayground/src/playground.c` - where the C primitives are defined; 
- `libplayground/include/playground.h` - the header for the file above;
- `src/playground/playground_stubs.c` - the OCaml to C's "glue" code;
- `src/playground/playground.ml` - here are defined the OCaml's `external` declaration and some inline unit tests. This is configured as a library containing C stubs in **dune**. See [this](https://github.com/illbexyz/ocaml-c-stubs-playground/blob/master/src/playground/dune) file for the configuration.
- `src/main.ml` - this file will be executed using the `./run.sh` script (see the section below). Here the Playground module is available.

## Building and running (UNIX)

Note: Windows is not currently supported.

By running:

```bash
$ make
```

you will build both the `libplayground` C library and the OCaml project. Respectively, this will create a `libplayground/build` and a `_build` folder.

`libplayground/build` will contain:
- `shared` and `static` folders, with the intermediate object files for the library. They differ because the `shared` version is built using the `-fPIC` flag (position independent code). You don't have to worry about these files;
- `libplayground.a`, the static library;
- `libplayground.so`, the shared library.

### Running

The script `run.sh` is meant to run and/or test the OCaml project.

```
Usage: run.sh [options]

By default, the script will run the src/main.ml file, but you can customize this behaviour using the options.

Options:
    main        Run src/main.ml (default)
    test        Run the inline tests inside the dune project

You can run both the main and the test by specifying both the options and they will be executed on the given order.
```

## TODO list
- [x] Test an *hello world* from C
- [x] Test arrays
- [x] Test strings
- [x] Test passing a string containing the NULL byte
- [ ] Test tuples
- [ ] Test lists
- [ ] Test float arrays
- [ ] Test objects
- [ ] Test ADTs
- [ ] Test polymorphic variants
# OnOffController

This repository contains the code to use a `OnOffController` and also a class called `Controller` was created to be able to create general controllers in the future.

## Build

If you do not intend to edit the code, go to the Makefile and comment the lines related with `compiledb` those are `13` and `20`. If you do not do this and don't have `compiledb` already installed in your system, you will probably get an error during compilation.

* If you want to get the `compiledb` just run the command below:

    ```bash
    pip install compiledb
    ```

### Static

1. Run the command below to compile the library as static

    ```bash
    make static
    ```

### Shared

1. Run the command below to compile the library as shared

    ```bash
    make shared
    ```

## Link to your program

To link to your program manually (without an automate build system as CMake), use one of the options below. I use both of them with the code under `example folder`, this code is a simple example to show how to instantiate the OnOffController, and how to use the Update function. Check this code to see how to make it.

### Static

```bash
g++ -std=c++11 main.cpp -I../include -L../lib -o main -lonoff_controller
```

### Shared

```bash
g++ -std=c++11 main.cpp -I../include -L../lib -Wl,-rpath=../lib -o main -lonoff_controller
```
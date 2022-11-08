<img src=".github/logo.svg" width="150px" align="right"/>

# Welcome to source code of Umbra language interpreter

![code](https://img.shields.io/github/languages/code-size/umbra-lang/umbra)

## Cloning and setting up project

```sh
$ git clone git@github.com:umbra-lang/umbra.git
$ cd umbra
$ make configure
```

If you want do contribute make sure you have clang-format installed to ensure our formatting settings

## Building the Code

Since you configure the project following the previous step we are ready to go building umbra.

```sh
$ make
$ ./umbra example/example.umb
```
## Running the tests

To run all unit tests suites follow this commands

```sh
cd tests
make
make run-tests
```

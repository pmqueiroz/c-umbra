<img src=".github/logo.svg" width="150px" align="right"/>

# Welcome to source code of Umbra language interpreter

![code](https://img.shields.io/github/languages/code-size/umbra-lang/umbra)

<br/>
<br/>

## Cloning and setting up project

```sh
$ git clone git@github.com:umbra-lang/umbra.git
$ cd umbra
$ make configure
```

If you want do contribute make sure you have clang-format installed to ensure our formatting settings

## Building the Code

This repository uses [git submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) to handle with some dependencies. To install them run:

```sh
git submodule update --init
```

Next you need to download the libs dependencies. For that we use [vcpkg](https://vcpkg.io/en/index.html) as package manager.

```sh
# to install all vcpkg dependencies run
./install_dependencies.sh
```
Now we are ready to go

```sh
make
./umbra some-umbra-file.umb
```
## Running the tests

To run all unit tests suites follow this commands

```sh
cd tests
make
make run-tests
```

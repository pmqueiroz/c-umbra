#ifndef UMBRA_ERROR_H
#define UMBRA_ERROR_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void throw_error(const char* msg);

void throw_sytax_error(const char* msg);

#endif

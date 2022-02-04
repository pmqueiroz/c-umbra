CC = gcc
CFLAGS = -g -Wall -Werror -pedantic
INPUT_FILE = main.c
OUTPUT_FILE = tests_suites

all:
	@${CC} ${CFLAGS} ${INPUT_FILE} -o ${OUTPUT_FILE}

run-tests:
	@./${OUTPUT_FILE}
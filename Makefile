CC = gcc
CFLAGS = -c -std=c99 -g
LDFLAGS = -g
SRC_FILES = ${wildcard src/*.c}
HEADER_FILES = ${wildcard include/*.h}
OBJ_FILES = ${SRC_FILES:.c=.o}
EXECUTABLE = umbra

all: ${SRC_FILES} ${OBJ_FILES} ${EXECUTABLE}

${EXECUTABLE}: ${OBJ_FILES}
	${CC} ${LDFLAGS} $^ -o $@
	
%.o: %.c ${HEADER_FILES}
	${CC} ${CFLAGS} $< -o $@

clean:
	rm ${OBJ_FILES} ${EXECUTABLE}

run:
	./${EXECUTABLE}


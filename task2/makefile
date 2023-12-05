CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

SRC = src/main.c
EXE = src/main

.PHONY: clean build run

clean:
	rm -f $(EXE)

build: $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)

run: build
	./$(EXE)

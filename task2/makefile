CC = gcc

SRC = src/main.c
EXE = src/main.out

.PHONY: clean build run

clean:
	rm -f $(EXE)

build: $(SRC)
	$(CC) -o $(EXE) $(SRC)

run: build
	./$(EXE)

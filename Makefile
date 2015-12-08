CC=clang
CFLAGS=-o
SRC=*.cpp
HEAD=*.h
OBJ=carSimulate

all:$(SRC) $(HEAD)
	$(CC) $(CFLAGS) $(OBJ) $(SRC)
test:$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(SRC)
	./$(OBJ)
clean:$(OBJ)
	rm -rf $(OBJ)

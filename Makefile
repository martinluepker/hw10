CC=fg++
CFLAGS=-o
SRC=*.cpp
HEAD=*.h
OBJ=m

all:$(SRC) $(HEAD)
	$(CC) $(CFLAGS) $(OBJ) $(SRC)
test:$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(SRC)
	./$(OBJ)
	rm -rf ./$(OBJ)
clean:$(OBJ)
	rm -rf $(OBJ)

OBJS = pol.c stack.c

CC = gcc

COMPILER_FLAGS = 

LINKER_FLAGS = 

OBJ_NAME = pol

build: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean: $(OBJ_NAME)
	rm $(OBJ_NAME)

test: $(OBJ_NAME)
	./pol "2 2 +"
	./pol "7 2 3 * -"
	./pol "1 2 + 4 * 3 +"
	./pol "45 36 34 - *"
	./pol "2"
	./pol "+"

TARGET  = BSQ.out
OBJ_DIR = obj
INC_DIR = inc
SRC_DIR = src
CFLAGS  = -Wall -Wextra -Werror -I$(INC_DIR)
OBJS    = $(OBJ_DIR)/main.o\
          $(OBJ_DIR)/prueba.o

$(TARGET) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/main.o : $(SRC_DIR)/main.c
	mkdir -p $(OBJ_DIR)
	cc -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/prueba.o : $(INC_DIR)/prueba.c
	mkdir -p $(OBJ_DIR)
	cc -c $(INC_DIR)/prueba.c -o $(OBJ_DIR)/prueba.o

clean:
	@rm -rf $(OBJ_DIR) $(TARGET)

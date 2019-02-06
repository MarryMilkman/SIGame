# Name of the program
NAME	:= go_SIGame

# Directories
OBJ_DIR	:= ./obj/
SRC_DIR	:= ./src/
SID_SRC_DIR := ./sid_parser/src/

INC_DIR := ./inc/

# Path to sqlite lib
PATH_LIB_SQLITE := ./lib_sqlite/
LIB_SQLITE := ./lib_sqlite/lib_sqlite.a

# Source and object files
SRC		:= main.cpp sid.cpp _getch.cpp \
		SIGame.cpp IDataSIController.cpp IMenuSIController.cpp \
		IDataSIController_save.cpp IDataSIController_load.cpp \
		Place.cpp PlacePermission.cpp \
 		IHuman.cpp BotConstructor.cpp \
		PlayerH.cpp GrayBotH.cpp \
#SRC_SID	:= sid.cpp
OBJ		:= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

# Header files
INC	:= 

# Compiler and flags
CC		:= g++
FLAGS	:= -std=c++11 # -Wall -Wextra

# Compile and link the program
all: get_lib obj_dir $(NAME)

get_lib:
	@make -C $(PATH_LIB_SQLITE)

# Link object files into the executable
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I$(INC_DIR) $(LIB_SQLITE)

# Compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(FLAGS) -o $@ -c $< -I$(INC_DIR)

# Create a directory for object files
obj_dir:
	@mkdir -p $(OBJ_DIR)

# Delete object files
clean:
	make clean -C $(PATH_LIB_SQLITE)
	rm -rf $(OBJ_DIR)

# Delete all files created with the Makefile
fclean: clean
	make fclean -C $(PATH_LIB_SQLITE)
	rm -f $(NAME)

# Re-make all files
re: fclean all

# GNU will run even if files have names as instructions
.PHONY: all clean fclean re

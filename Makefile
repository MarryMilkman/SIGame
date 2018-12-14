# Name of the program
NAME	:= simuator_ivana

# Directories
OBJ_DIR	:= ./obj/
SRC_DIR	:= ./src/
SID_SRC_DIR := ./sid_parser/src/

INC_DIR := ./inc/
# SID_INC_DIR := ./sid_parser/inc/

# Source and object files
SRC		:= main.cpp SIGame.cpp Human.cpp Place.cpp \
		sid.cpp PlacePermission.cpp \
		PlayerA.cpp GrayBotA.cpp
#SRC_SID	:= sid.cpp
OBJ		:= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o)) #$(addprefix $(OBJ_DIR), $(SRC_SID:.cpp=.o))

# Header files
INC	:= 

# Compiler and flags
CC		:= g++
FLAGS	:=# -Wall -Wextra -std=c++11

# Compile and link the program
all: obj_dir $(NAME)

# Link object files into the executable
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I$(INC_DIR) #$(SID_INC_DIR)

# Compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(FLAGS) -o $@ -c $< -I$(INC_DIR)

# Create a directory for object files
obj_dir:
	@mkdir -p $(OBJ_DIR)

# Delete object files
clean:
	rm -rf $(OBJ_DIR)

# Delete all files created with the Makefile
fclean: clean
	rm -f $(NAME)

# Re-make all files
re: fclean all

# GNU will run even if files have names as instructions
.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 18:45:34 by spitul            #+#    #+#              #
#    Updated: 2024/03/16 18:10:39 by spitul           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror -g -I.



SRC_DIR := src
OBJ_DIR := obj

SRC :=	$(SRC_DIR)/main.c \
		$(SRC_DIR)/create_stack.c \
		$(SRC_DIR)/ft_split.c \
		$(SRC_DIR)/error_check.c \
		$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/set_stack.c \
		$(SRC_DIR)/sort_more.c \
		$(SRC_DIR)/sort.c \
		$(SRC_DIR)/utils_stack_cr.c \
		$(SRC_DIR)/push.c \
		$(SRC_DIR)/reverse_r.c \
		$(SRC_DIR)/rotate.c \
		$(SRC_DIR)/swap.c
		
OBJ := 	$(OBJ_DIR)/main.o \
    	$(OBJ_DIR)/create_stack.o \
		$(OBJ_DIR)/ft_split.o \
		$(OBJ_DIR)/error_check.o \
		$(OBJ_DIR)/push_swap.o \
		$(OBJ_DIR)/set_stack.o \
		$(OBJ_DIR)/sort_more.o \
		$(OBJ_DIR)/sort.o \
		$(OBJ_DIR)/utils_stack_cr.o \
		$(OBJ_DIR)/push.o \
		$(OBJ_DIR)/reverse_r.o \
		$(OBJ_DIR)/rotate.o \
		$(OBJ_DIR)/swap.o
	
#OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: directories $(NAME)

#all: directories $(TARGET)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

directories:
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)/*.o 
	
fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re

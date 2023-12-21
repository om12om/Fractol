# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: motanha- <motanha-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 21:04:37 by motanha-          #+#    #+#              #
#    Updated: 2023/10/06 18:07:45 by motanha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol
#define compiler and flags for Debugger
CC 		= gcc
CFLAGS 	= -Wall -Werror -Wextra -o3 -I ./includes/fractol.h

# Including the directories 
LIBFT  	= ./libs/libft/
#MINILIBX = ./libs/minilibx-linux/libmlx.a
MLX    := ./libs/minilibx-linux/
SRC_DIR := ./src
# SRCS	= ./src
SRCS := $(SRC_DIR)/main.c \
		$(SRC_DIR)/initialization.c \
		$(SRC_DIR)/colors.c \
		$(SRC_DIR)/key_oper.c \
		$(SRC_DIR)/mouse_oper.c \
		$(SRC_DIR)/equations.c
# Making it cross-platform
OS := $(shell uname -s)

# Choice for mac/linux version
ifeq ($(OS),Windows_NT)
	NAME := $(addsuffix .exe, $(NAME))
else ifeq ($(OS), Darwin)
	MLX_DIR = libs/minilibx-linux/libmlx.a
	LIBFLAGS = -framework OpenGL -framework AppKit -lm -lmlx -I -L/libs/minilibx-linux/libmlx_linux.a
endif

OBJS 	=  $(SRCS:.c=.o)
# Color Codes 
NC		:= \033[m
B_RED	:= \033[1;31m
RED 	:= \033[0;31m
B_GREEN	:= \033[1;32m
GREEN 	:= \033[0;33m
B_BLUE 	:= \033[1;34m
BLUE 	:= \033[0;34m
PURPLE	:= \033[0;35m
WHCOLOR	:= \033[0;40m

##Check for Linux and run Valgrind when debugger on

UNAME = $(shell uname -s)

ifeq ($(UNAME),Linux)
	VALGRIND = valgrind -q --leak-check=full --track-origin=yes
else 
	detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

all: libft mlx $(NAME) 

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
#	@echo "____!!!$(BLUE)----- Compilation ------$(NC)"
	@$(MAKE) -C $(LIBFT)
#	@echo "Compilation of Libft:	\033[1;32mOK\033[m"


mlx:
#	@echo "____!!!$(RED)----- Compiling mlx ------$(NC)"
	@$(MAKE) -C $(MLX)
#@echo "$(RED)Creation of MLX$(GREEN):	\033[1;32mOK\033[m"


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) $(MLX_DIR) $(LIBFT)libft.a -o $(NAME)
	@echo "Compilation of Fractol:	\033[1;32mSUCCESS\033[m"


# Clean up your trashes 

clean:
	@echo "$(GREEN)♻️ ${B_RED} Trashing Away objects..... $(GREEN)♻️ "
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(MLX) clean
	@sleep 0.5
	@echo "	$(B_RED) Cleaning Done $(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)♻️ ${B_RED} Trashing Away all objects and library...."
	
re: fclean all

.PHONY: all clean fclean re
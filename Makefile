# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 17:53:50 by hakahmed          #+#    #+#              #
#    Updated: 2023/03/31 00:01:11 by hakahmed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

# OPTIONAL FLAGS

# CFLAGS += -fsanitize=address -g3

INCDIR = inc

CFLAGS += -I $(INCDIR) 

LIBNAME = libft.a

LIBDIR = libft

LIBFLAGS = -L ./libft -lft


SRCDIR = srcs

SRCFILES = argparser.c \
	   three_args.c \
	   errors.c \
	   movements.c \
	   movements2.c \
	   algorithm.c \
	   main.c

SRCS = $(addprefix $(SRCDIR)/,$(SRCFILES))

OBJS = $(SRCS:.c=.o)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)Compiling $(COLOUR_END)" $<

# ***** COLORS ********

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

reset := $(shell tput sgr0)
bold := $(shell tput bold)


$(NAME): $(OBJS)
	@echo ""
	@echo "$(COLOUR_GREEN)$(bold)======= COMPILING LIBFT ========$(COLOUR_END)$(reset)"
	@echo ""
	@make bonus -sC libft
	@$(CC) $(CFLAGS) $(INCFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)
	@echo ""
	@echo "$(COLOUR_RED)$(bold)run the program by executing ./$(NAME) arg1 arg2 ...$(reset)"

all: $(lib) $(NAME)

clean:
	@make clean -sC libft
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all

.SILENT: name

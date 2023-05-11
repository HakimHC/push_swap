# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 17:53:50 by hakahmed          #+#    #+#              #
#    Updated: 2023/05/04 10:37:57 by hakahmed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFLAGS += -g3

INCDIR = inc

CFLAGS += -I $(INCDIR)

CFLAGS += -I $(LIBDIR)/$(INCDIR)

LIBDIR = libft

LDFLAGS = -L ./libft -lft

# LDFLAGS += -fsanitize=address

SRCDIR = srcs

SRCFILES = argparser.c \
	   three_args.c \
	   errors.c \
	   movements.c \
	   movements2.c \
	   algorithm.c \
	   main.c \
	   push_swap_utils.c \
	   algo_handler.c

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
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo ""
	@echo "$(COLOUR_RED)$(bold)run the program by executing ./$(NAME) arg1 arg2 ...$(reset)"

all: $(lib) $(NAME)

clean:
	@make fclean -sC libft
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -sC libft

re: fclean all

.SILENT: name fclean clean

.PHONY: all clean fclean re

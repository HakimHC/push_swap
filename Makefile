# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 17:53:50 by hakahmed          #+#    #+#              #
#    Updated: 2023/03/28 22:41:51 by hakahmed         ###   ########.fr        #
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
	   algorithm.c \
	   errors.c \
	   movements.c \
	   movements2.c \
	   push_swap_utils.c \
	   main.c

SRCS = $(addprefix $(SRCDIR)/,$(SRCFILES))

OBJS = $(SRCS:.c=.o)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# ***** COLORS ********

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

$(NAME): $(OBJS)
	@make bonus -sC libft
	@$(CC) $(CFLAGS) $(INCFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)
	@echo "$(COLOUR_GREEN)push_swap ready to rumble!!$(COLOUR_END)🎉"

all: $(NAME)

clean:
	@make clean -sC libft
	@echo "$(COLOUR_GREEN)push_swap cleaned!!$(COLOUR_END)🎉"
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

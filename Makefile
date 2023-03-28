# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 17:53:50 by hakahmed          #+#    #+#              #
#    Updated: 2023/03/28 19:07:11 by hakahmed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

# OPTIONAL FLAGS

CFLAGS += -fsanitize=leak -g3

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
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make bonus -C libft
	@echo "LibFT compiled!"
	$(CC) $(CFLAGS) $(INCFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)
	@echo "push_swap compiled!!!!! :DD"

all: $(NAME)

clean:
	@make clean -C libft
	@rm -rf $(OBJS)
	@echo "Clean Done!"

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@echo "Full Clean Done!"

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakahmed <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 19:15:07 by hakahmed          #+#    #+#              #
#    Updated: 2023/03/28 22:44:52 by hakahmed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

LIB = ar -rcs

RM = rm -f

NAME = libft.a

SRC =	ft_memset.c ft_bzero.c ft_strlen.c ft_atoi.c ft_isdigit.c ft_isalpha.c\
ft_isprint.c ft_isascii.c ft_isalnum.c ft_memchr.c ft_memcpy.c \
ft_memcmp.c ft_memmove.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c\
ft_strncmp.c ft_toupper.c ft_tolower.c ft_strnstr.c ft_strrchr.c ft_calloc.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_substr.c\
ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_itoa.c ft_split.c ft_striteri.c\
ft_printf.c ft_functions.c ft_functions2.c ft_free_strarr.c ft_strcmp.c \
ft_isspace.c ft_atol.c

OBJ = $(SRC:.c=.o)

INCLUDE = libft.h

BONUSSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		   ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUSOBJ = $(BONUSSRC:.c=.o)

# ***** COLORS ********

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@$(LIB) $(NAME) $(OBJ)
	@echo "$(COLOUR_GREEN)LibFT Compiled!$(COLOUR_END)🎉"

bonus: $(OBJ) $(BONUSOBJ) $(INCLUDE)
	@$(LIB) $(NAME) $(BONUSOBJ) $(OBJ)
	@echo "$(COLOUR_GREEN)LibFT Compiled With Bonus!$(COLOUR_END)🎉"

%.o: %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ) $(BONUSOBJ)
	@echo "$(COLOUR_GREEN)LibFT Cleaned!$(COLOUR_END)🫧"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

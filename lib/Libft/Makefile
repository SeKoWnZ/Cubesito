# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 12:39:44 by jose-gon          #+#    #+#              #
#    Updated: 2024/12/16 18:48:48 by jose-gon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -g -Wall -Werror -Wextra
LFLAGS = -I./../../include
FILES = \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_memset.c \
ft_strrchr.c \
ft_strcmp.c \
ft_strncmp.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strnstr.c \
ft_atoi.c \
ft_atol.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c ft_strjoin_free.c \
ft_strtrim.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_split.c \
get_next_line.c \
get_next_line_utils.c \
ft_printf_utils.c \
ft_printf.c \
ft_strcat.c \
ft_atoitoa_cmp.c

FILES_BONUS = \
ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c \

OBJECTS = $(FILES:.c=.o)

OBJECTS_BONUS = $(FILES_BONUS:.c=.o)

$(NAME) : $(OBJECTS) ./../../include/libft.h
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS) : %.o: %.c
	gcc $(FLAGS) $(LFLAGS) -c $^ -o $@

$(OBJECTS_BONUS) : %.o: %.c
	gcc $(FLAGS) -c $^ -o $@

all : $(NAME)

bonus : $(OBJECTS_BONUS) ./../../include/libft.h
	ar rcs $(NAME) $(OBJECTS_BONUS)

fclean :
	rm -f *.o $(NAME)

clean :
	rm -f *.o

re : fclean all

.PHONY : all fclean clean re bonus
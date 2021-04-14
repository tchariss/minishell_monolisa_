# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 11:33:18 by tchariss          #+#    #+#              #
#    Updated: 2020/11/20 14:57:23 by tchariss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c  ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_calloc.c\
		ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strtrim.c \
		ft_strrchr.c  ft_tolower.c  ft_toupper.c ft_strmapi.c ft_substr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c\
		get_next_line_utils.c get_next_line.c

SRCO = $(SRC:.c=.o)

BONUS = ft_lstnew.c ft_lstiter.c \
		ft_lstadd_front.c ft_lstlast.c ft_lstsize.c \

BONUSO = $(BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror -c

%.o: %.c 
	gcc $(FLAGS) $< -o $@

all: $(NAME)

$(NAME): $(SRCO)
	ar rcs $(NAME) $?
	ranlib $(NAME)

bonus: $(BONUSO)
	ar rcs $(NAME) $(BONUSO)

clean:
	rm -f $(SRCO) $(BONUSO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re bonus

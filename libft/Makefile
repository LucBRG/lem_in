# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 15:26:59 by lbrugero          #+#    #+#              #
#    Updated: 2016/11/17 10:01:23 by lbrugero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
		ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strnew.c ft_strdigit.c \
		ft_strchr.c ft_strlenchar.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strrev.c ft_strdel.c ft_strclr.c\
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strsplit_free.c ft_strsplit_len.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c  \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstaddafter.c ft_lstiter.c ft_lstmap.c ft_lstlen.c ft_lstsort.c ft_lstreverse.c ft_lstjump.c ft_lstdefile.c \
		ft_putwstr.c ft_putwchar.c ft_strwoctet.c ft_strwlen.c ft_strwdup.c ft_strwjoin.c ft_strwrev.c ft_wtoc.c ft_strclen.c \
		ft_greater.c ft_max.c ft_nbrlen.c ft_showletter.c get_next_line.c ft_base.c \
		ft_itowchar.c ft_atoi.c ft_itoa.c ft_swap.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compile Libft"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $^

clean:
	@echo "Clean Libft"
	@rm -f $(OBJS)

fclean: clean
	@echo "Fclean Libft"
	@rm -f $(NAME)

re: fclean all

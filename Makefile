# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 15:26:59 by lbrugero          #+#    #+#              #
#    Updated: 2017/03/21 12:08:24 by lbrugero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
OBJS = lemin.o parsing.o parsing2.o solve.o malloc.o lstdel.o
FLAGS = -Wall -Werror -Wextra

all: lib_ft $(NAME)

lib_ft:
	@make -C libft/

$(NAME): $(OBJS)
	@echo "Compile Lem-in"
	@gcc $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a

%.o: %.c
	@gcc $(FLAGS) -c $^

clean:
	@make clean -C libft/
	@echo "Clean Lem-in"
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C libft/
	@echo "Fclean Lem-in"
	@rm -f $(NAME)

re: fclean all
	@make re -C libft/

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by ahryhory          #+#    #+#              #
#    Updated: 2018/03/15 15:29:01 by ahryhory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

PATHLIBFT = ../libft

LIB = ../libft/libft.a

SRC =

SRC += checker.c
SRC += is_stack_sorted.c
SRC += move_stack.c
SRC += print_stacks.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(PATHLIBFT)
	@gcc -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	@gcc $(FLAGS) -c -I. $<

clean:
	@make clean -C $(PATHLIBFT)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C $(PATHLIBFT)
	@rm -rf $(NAME)

re: fclean all

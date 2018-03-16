# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by ahryhory          #+#    #+#              #
#    Updated: 2018/03/16 15:57:59 by ahryhory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

PATHLIBFT = ../libft

LIB = ../libft/libft.a

SRC =

SRC += push_swap.c
SRC += is_stack_sorted.c
SRC += move_stack.c
SRC += print_stacks.c
SRC += get_median.c
SRC += sort_3_elem.c

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by ahryhory          #+#    #+#              #
#    Updated: 2018/03/23 16:22:12 by ahryhory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

PATHLIBFT = ../libft

LIB = ../libft/libft.a

SRC =

SRC += checker.c
SRC += ft_error.c
SRC += reverse_rotate.c
SRC += rotate.c
SRC += push.c
SRC += read_flags.c
SRC += check_num.c
SRC += check_num_duplicates.c
SRC += p_atoi.c
SRC += is_stack_sorted.c
SRC += ft_putendl_color.c
SRC += print_stacks.c
SRC += print_stats.c
SRC += move_stack.c

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

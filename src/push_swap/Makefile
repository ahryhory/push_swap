# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by ahryhory          #+#    #+#              #
#    Updated: 2018/03/24 17:29:01 by ahryhory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../../push_swap

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

PATHLIBFT = ../libft

LIB = ../libft/libft.a

SRC =

SRC += push_swap.c
SRC += is_stack_sorted.c
SRC += move_stack.c
SRC += read_flags.c
SRC += reverse_rotate.c
SRC += ft_putendl_color.c
SRC += rotate.c
SRC += not_last_group.c
SRC += print_stacks.c
SRC += print_stats.c
SRC += push.c
SRC += get_median.c
SRC += p_atoi.c
SRC += b_to_a.c
SRC += sort_elem.c
SRC += check_num_duplicates.c 
SRC += ft_error.c
SRC += check_num.c

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

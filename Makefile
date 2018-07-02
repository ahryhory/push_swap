# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by ahryhory          #+#    #+#              #
#    Updated: 2018/03/24 17:28:36 by ahryhory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

all: $(NAME)

$(NAME):
	@make -C src/push_swap
	@make -C src/checker

clean:
	@make clean -C src/push_swap
	@make clean -C src/checker

fclean: clean
	@make fclean -C src/push_swap
	@make fclean -C src/checker

re: fclean all

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:23:41 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/22 15:45:18 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <stdio.h>

# define SWAP_A "sa"
# define SWAP_B "sb"
# define SWAP_AB "ss"
# define PUSH_A "pa"
# define PUSH_B "pb"
# define ROTATE_A "ra"
# define ROTATE_B "rb"
# define ROTATE_AB "rr"
# define REVERSE_ROTATE_A "rra"
# define REVERSE_ROTATE_B "rrb"
# define REVERSE_ROTATE_AB "rrr"

typedef struct			s_arr
{
	int					num;
	int					median;
}						t_arr;

typedef struct			s_stacks
{
	t_arr				*a_int;
	t_arr				*b_int;
	int					a_size;
	int					b_size;
}						t_stacks;

typedef struct			s_instruct
{
	char				*instruct;
	struct s_instruct	*next;
}						t_instruct;

void					move_stack(t_stacks *stacks, char *buf);
void					push(t_stacks *stacks, char *buf);
void					rotate(t_stacks *stacks, char *buf);
void					reverse_rotate(t_stacks *stacks, char *buf);
int						is_stack_sorted(t_stacks stacks);
void					print_stacks(t_stacks stacks);
int						p_atoi(const char *str);
void					ft_error(int num);

#endif

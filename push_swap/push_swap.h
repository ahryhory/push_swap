/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:38:27 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/21 15:38:59 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct	s_arr
{
	int			num;
	int			median;
}				t_arr;

typedef struct	s_stacks
{
	t_arr		*a_int;
	t_arr		*b_int;
	int			a_size;
	int			b_size;
}				t_stacks;

void			move_stack(t_stacks *stacks, char *buf);
int				is_stack_sorted(t_stacks stacks);
int				not_last_group(t_stacks stacks);
void			print_stacks(t_stacks stacks);
int				get_median(t_stacks stacks, char stack, int *count, int *num);
void			sort_elem(t_stacks *stacks);
void			b_to_a(t_stacks *stacks);
void			push(t_stacks *stacks, char *buf);
void			reverse_rotate(t_stacks *stacks, char *buf);
void			rotate(t_stacks *stacks, char *buf);

#endif

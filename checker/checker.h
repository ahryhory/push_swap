/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:23:41 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/15 15:47:14 by ahryhory         ###   ########.fr       */
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

typedef struct	s_stacks
{
	int		*a_int;
	int		*b_int;
	int		a_size;
	int		b_size;
}				t_stacks;

void			move_stack(t_stacks *stacks, char *buf);
int				is_stack_sorted(t_stacks stacks);
void			print_stacks(t_stacks stacks);

#endif

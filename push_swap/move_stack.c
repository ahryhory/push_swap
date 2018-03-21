/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:32:54 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/21 15:17:20 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stacks *stacks, char *buf)
{
	t_arr		tmp;

	if ((ft_strequ(buf, SWAP_A) || ft_strequ(buf, SWAP_AB)) &&
			stacks->a_size >= 2)
	{
		tmp = stacks->a_int[0];
		stacks->a_int[0] = stacks->a_int[1];
		stacks->a_int[1] = tmp;
	}
	if ((ft_strequ(buf, SWAP_B) || ft_strequ(buf, SWAP_AB)) &&
			stacks->b_size >= 2)
	{
		tmp = stacks->b_int[0];
		stacks->b_int[0] = stacks->b_int[1];
		stacks->b_int[1] = tmp;
	}
}

void		move_stack(t_stacks *stacks, char *buf)
{
	ft_putendl(buf);
	if (ft_strequ(buf, SWAP_A) || ft_strequ(buf, SWAP_B)
			|| ft_strequ(buf, SWAP_AB))
		swap(stacks, buf);
	else if (ft_strequ(buf, PUSH_A) || ft_strequ(buf, PUSH_B))
		push(stacks, buf);
	else if (ft_strequ(buf, ROTATE_A) || ft_strequ(buf, ROTATE_B)
			|| ft_strequ(buf, ROTATE_AB))
		rotate(stacks, buf);
	else if (ft_strequ(buf, REVERSE_ROTATE_A)
			|| ft_strequ(buf, REVERSE_ROTATE_B)
			|| ft_strequ(buf, REVERSE_ROTATE_AB))
		reverse_rotate(stacks, buf);
}

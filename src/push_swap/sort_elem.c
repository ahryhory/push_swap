/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:01:28 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/24 18:12:43 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_elem(t_stacks *stacks)
{
	while (!is_stack_sorted(*stacks))
	{
		if (stacks->a_int[0].num > stacks->a_int[2].num)
			move_stack(stacks, ROTATE_A);
		if (stacks->a_int[1].num > stacks->a_int[2].num)
			move_stack(stacks, REVERSE_ROTATE_A);
		if (stacks->a_int[0].num > stacks->a_int[1].num)
		{
			if (stacks->b_int[0].num < stacks->b_int[1].num)
				move_stack(stacks, SWAP_AB);
			else
				move_stack(stacks, SWAP_A);
		}
	}
}

static void	sort_more_than_3(t_stacks *stacks)
{
	while (!is_stack_sorted(*stacks))
	{
		if (stacks->a_int[0].num > stacks->a_int[1].num)
		{
			if (stacks->b_int[0].num < stacks->b_int[1].num)
				move_stack(stacks, SWAP_AB);
			else
				move_stack(stacks, SWAP_A);
		}
		if (stacks->a_int[1].num > stacks->a_int[2].num)
		{
			move_stack(stacks, ROTATE_A);
			if (stacks->b_int[0].num < stacks->b_int[1].num)
				move_stack(stacks, SWAP_AB);
			else
				move_stack(stacks, SWAP_A);
			move_stack(stacks, REVERSE_ROTATE_A);
		}
	}
}

void		sort_elem(t_stacks *stacks)
{
	if (stacks->a_size > 3)
		sort_more_than_3(stacks);
	else
		sort_3_elem(stacks);
}

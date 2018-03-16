/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:44:30 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/16 17:17:12 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_3_elem(t_stacks *stacks, char stack)
{
	if (stack == 'a' && stacks->a_size >= 3)
	{
		while (!(stacks->a_int[0].num < stacks->a_int[1].num &&
				stacks->a_int[1].num < stacks->a_int[2].num))
		{
			if (stacks->a_int[0].num > stacks->a_int[1].num)
				move_stack(stacks, "sa");
			if (stacks->a_int[0].num > stacks->a_int[2].num)
			{
				move_stack(stacks, "sa");
				move_stack(stacks, "ra");
				move_stack(stacks, "sa");
				move_stack(stacks, "rra");
			}
			if (stacks->a_int[1].num > stacks->a_int[2].num)
			{
				move_stack(stacks, "ra");
				move_stack(stacks, "sa");
				move_stack(stacks, "rra");
			}
		}
	}
	else if (stack == 'b' && stacks->b_size >= 3)
	{
		while (!(stacks->b_int[0].num < stacks->b_int[1].num &&
				stacks->b_int[1].num < stacks->b_int[2].num))
		{
			if (stacks->b_int[0].num > stacks->b_int[1].num)
				move_stack(stacks, "sb");
			if (stacks->b_int[0].num > stacks->b_int[2].num)
			{
				move_stack(stacks, "sb");
				move_stack(stacks, "rb");
				move_stack(stacks, "sb");
				move_stack(stacks, "rrb");
			}
			if (stacks->b_int[1].num > stacks->b_int[2].num)
			{
				move_stack(stacks, "rb");
				move_stack(stacks, "sb");
				move_stack(stacks, "rrb");
			}
		}
	}
	else if (stack == 'a' && stacks->a_size == 2)
	{
		if (stacks->a_int[0].num > stacks->a_int[1].num)
			move_stack(stacks, "sa");
	}
	else if (stack == 'b' && stacks->b_size == 2)
	{
		if (stacks->b_int[0].num > stacks->b_int[1].num)
			move_stack(stacks, "sb");
	}
}

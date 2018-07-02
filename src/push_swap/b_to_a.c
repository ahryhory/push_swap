/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:29:23 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/24 17:08:18 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_b(t_stacks *stacks, int pa)
{
	int		rb;
	int		size;
	int		count;
	int		median;

	while (pa > 3)
	{
		rb = 0;
		median = get_median(*stacks, 'a', &count, &size);
		while (count)
			if (stacks->a_int[0].num < median)
			{
				stacks->a_int[0].median = median;
				pa--;
				count--;
				move_stack(stacks, PUSH_B);
			}
			else
			{
				move_stack(stacks, ROTATE_A);
				rb++;
			}
		while (rb--)
			move_stack(stacks, REVERSE_ROTATE_A);
	}
}

static void	push_a_more(t_stacks *stacks, int count, int median)
{
	int		pa;
	int		rb;

	pa = 0;
	rb = 0;
	while (count)
		if (stacks->b_int[0].num >= median)
		{
			stacks->b_int[0].median = median;
			pa++;
			count--;
			move_stack(stacks, PUSH_A);
		}
		else
		{
			move_stack(stacks, ROTATE_B);
			rb++;
		}
	if (not_last_group(*stacks))
		while (rb--)
			move_stack(stacks, REVERSE_ROTATE_B);
	if (pa > 3)
		a_to_b(stacks, pa);
}

void		b_to_a(t_stacks *stacks)
{
	int		median;
	int		count;
	int		size;

	while (stacks->b_size > 0)
	{
		median = get_median(*stacks, 'b', &count, &size);
		if (size < 3)
			while (size)
			{
				move_stack(stacks, PUSH_A);
				size--;
			}
		else
			push_a_more(stacks, count, median);
		sort_elem(stacks);
	}
}

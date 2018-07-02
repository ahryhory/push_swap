/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:51:14 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/21 14:56:18 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_stacks *stacks)
{
	int	i;
	int	size;

	i = 1;
	size = stacks->a_size;
	while (i <= size)
	{
		stacks->a_int[size - i + 1] = stacks->a_int[size - i];
		i++;
	}
	stacks->a_int[0] = stacks->b_int[0];
	i = 0;
	size = stacks->b_size - 1;
	while (i < size)
	{
		stacks->b_int[i] = stacks->b_int[i + 1];
		i++;
	}
	stacks->b_size -= 1;
	stacks->a_size += 1;
}

static void	push_b(t_stacks *stacks)
{
	int	i;
	int	size;

	i = 1;
	size = stacks->b_size;
	while (i <= size)
	{
		stacks->b_int[size - i + 1] = stacks->b_int[size - i];
		i++;
	}
	stacks->b_int[0] = stacks->a_int[0];
	i = 0;
	size = stacks->a_size - 1;
	while (i < size)
	{
		stacks->a_int[i] = stacks->a_int[i + 1];
		i++;
	}
	stacks->a_size -= 1;
	stacks->b_size += 1;
}

void		push(t_stacks *stacks, char *buf)
{
	if (ft_strequ(buf, PUSH_A) && stacks->b_size >= 1)
		push_a(stacks);
	else if (ft_strequ(buf, PUSH_B) && stacks->a_size >= 1)
		push_b(stacks);
}

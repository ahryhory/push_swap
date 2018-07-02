/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:08:12 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/17 13:59:46 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_stack_sorted(t_stacks stacks)
{
	int		i;

	i = 0;
	while (i < stacks.a_size - 1)
	{
		if (stacks.a_int[i].num > stacks.a_int[i + 1].num)
			return (0);
		i++;
	}
	return (1);
}

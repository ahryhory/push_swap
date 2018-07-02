/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:08:12 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/22 15:33:15 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (stacks.b_size != 0)
		return (0);
	return (1);
}

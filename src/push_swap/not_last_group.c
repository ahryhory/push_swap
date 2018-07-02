/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_last_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:36:01 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/19 12:38:57 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_last_group(t_stacks stacks)
{
	int		median;
	int		size;

	size = 0;
	median = stacks.b_int[0].median;
	while (size < stacks.b_size && median == stacks.b_int[size].median)
		size++;
	if (size == stacks.b_size)
		return (0);
	else
		return (1);
}

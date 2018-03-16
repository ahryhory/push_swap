/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:52:36 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/16 14:49:42 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_median_a(t_stacks stacks)
{
	int		arr[stacks.a_size];
	int		tmp;
	int		j;
	int		i;

	i = 0;
	while (i < stacks.a_size)
	{
		arr[i] = stacks.a_int[i].num;
		i++;
	}
	i = 0;
	while (i < stacks.a_size - 1)
	{
		j = i + 1;
		while (j < stacks.a_size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr[stacks.a_size / 2]);
}

static int	get_median_b(t_stacks stacks)
{
	int		arr[stacks.b_size];
	int		median;
	int		size;
	int		tmp;
	int		j;
	int		i;

	i = 0;
	size = 0;
	median = stacks.b_int[0].median;
	while (i < stacks.b_size && median == stacks.b_int[i].median)
	{
		arr[i] = stacks.b_int[i].num;
		size++;
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr[size / 2]);
}

int		get_median(t_stacks stacks, char stack)
{
	if (stack == 'a')
		return (get_median_a(stacks));
	else
		return (get_median_b(stacks));
}

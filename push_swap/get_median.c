/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:52:36 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/24 16:57:45 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_arr(int arr[], int size)
{
	int		i;
	int		j;
	int		tmp;

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
}

static int	get_median_a(t_stacks stacks, int *count)
{
	int		arr[stacks.a_size];
	int		median;
	int		size;
	int		i;

	i = 0;
	size = 0;
	median = stacks.a_int[0].median;
	while (i < stacks.a_size && median == stacks.a_int[i].median)
	{
		arr[i] = stacks.a_int[i].num;
		size++;
		i++;
	}
	*count = (i / 2);
	sort_arr(arr, size);
	return (arr[size / 2]);
}

static int	get_end_median_a(t_stacks stacks, int *count)
{
	int		arr[stacks.a_size];
	int		median;
	int		size;
	int		i;

	i = stacks.a_size - 1;
	size = 0;
	median = stacks.a_int[stacks.a_size - 1].median;
	while (i >= 0 && median == stacks.a_int[i].median)
	{
		arr[i] = stacks.a_int[i].num;
		size++;
		i--;
	}
	*count = (i / 2);
	sort_arr(arr, size);
	return (arr[size / 2]);
}

static int	get_median_b(t_stacks stacks, int *count, int *num)
{
	int		arr[stacks.b_size];
	int		median;
	int		size;
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
	*num = i;
	if (i % 2 == 0)
		*count = (i / 2);
	else
		*count = (i / 2) + 1;
	sort_arr(arr, size);
	return (arr[size / 2]);
}

int			get_median(t_stacks stacks, char stack, int *count, int *num)
{
	if (stack == 'a')
		return (get_median_a(stacks, count));
	else if (stack == 'b')
		return (get_median_b(stacks, count, num));
	else if (stack == 'e')
		return (get_end_median_a(stacks, count));
	else
		return (0);
}

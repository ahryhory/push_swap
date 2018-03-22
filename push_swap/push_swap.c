/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:39:22 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/22 11:54:00 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stacks stacks)
{
	int			size;
	int			count;
	int			median;

	while (stacks.a_size > 3)
	{
		median = get_median(stacks, 'a', &count, &size);
		while (count)
		{
			if (stacks.a_int[0].num < median)
			{
				stacks.a_int[0].median = median;
				move_stack(&stacks, PUSH_B);
				count--;
				if (stacks.a_size == 3)
					break ;
			}
			else
			{
				if (stacks.b_int[0].num < stacks.b_int[stacks.b_size - 1].num)
					move_stack(&stacks, ROTATE_AB);
				else
					move_stack(&stacks, ROTATE_A);
			}
		}
	}
	sort_elem(&stacks);
	b_to_a(&stacks);
}

int			main(int ac, char **av)
{
	t_stacks	stacks;
	int			i;

	if (ac == 1)
		exit(1);
	stacks.a_size = ac - 1;
	stacks.b_size = 0;
	stacks.a_int = (t_arr *)malloc(sizeof(t_arr) * ac);
	stacks.b_int = (t_arr *)malloc(sizeof(t_arr) * ac);
	i = 0;
	while (i < stacks.a_size)
	{
		stacks.a_int[i].num = ft_atoi(av[i + 1]);
		stacks.a_int[i].median = 0;
		i++;
	}
	if (!is_stack_sorted(stacks))
		sort(stacks);
	return (0);
}

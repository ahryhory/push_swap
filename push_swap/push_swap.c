/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:39:22 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/16 17:19:33 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stacks	stacks;
	int			i;
	int			size;
	int			pa;
	int			rb;
	int			median;
	int			def_median;

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
	while (!is_stack_sorted(stacks))
	{
		while (stacks.a_size > 3)
		{
			median = get_median(stacks, 'a');
			size = stacks.a_size;
			i = 0;
			while (i < size)
			{
				if (stacks.a_int[0].num < median)
				{
					stacks.a_int[0].median = median;
					move_stack(&stacks, "pb");
				}
				else
					move_stack(&stacks, "ra");
				i++;
			}
		}
		sort_3_elem(&stacks, 'a');
		while (stacks.b_size > 3)
		{
			def_median = stacks.b_int[0].median;
			size = stacks.b_size;
			i = 0;
			pa = 0;
			rb = 0;
			median = get_median(stacks, 'b');
			while ((stacks.b_int[0].median == def_median) && (i < size))
			{
				if (stacks.b_int[0].num >= median)
				{
					stacks.b_int[0].median = median;
					pa++;
					move_stack(&stacks, "pa");
				}
				else
				{
					move_stack(&stacks, "rb");
					rb++;
				}
				i++;
			}
			while (rb)
			{
				move_stack(&stacks, "rrb");
				rb--;
			}
			if (pa > 3)
			{
				while (pa > 0)
				{
					move_stack(&stacks, "pb");
					pa--;
				}
			}
			else
				sort_3_elem(&stacks, 'a');
		}
		while (stacks.b_size > 0)
			move_stack(&stacks, "pa");
		sort_3_elem(&stacks, 'a');
//		print_stacks(stacks);
	}
	return (0);
}

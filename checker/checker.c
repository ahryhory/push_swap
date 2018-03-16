/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:51:45 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/16 16:40:53 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_stacks	stacks;
	char		*buf;
	int			i;

	if (ac == 1)
		exit(1);
	stacks.a_size = ac - 1;
	stacks.b_size = 0;
	stacks.a_int = (int *)malloc(sizeof(int) * ac);
	stacks.b_int = (int *)malloc(sizeof(int) * ac);
	i = 0;
	while (i < stacks.a_size)
	{
		stacks.a_int[i] = ft_atoi(av[i + 1]);
		i++;
	}
	while (ft_get_next_line(0, &buf))
	{
		if (ft_strequ(buf, ""))
			break ;
		move_stack(&stacks, buf);
		ft_strdel(&buf);
//		print_stacks(stacks);
	}
	if (is_stack_sorted(stacks))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}

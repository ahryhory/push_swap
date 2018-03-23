/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:51:37 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/23 14:27:19 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init(t_stacks *stacks)
{
	int		i;

	stacks->flgs.print_stck = 0;
	stacks->flgs.color = 0;
	stacks->flgs.error = 0;
	stacks->flgs.file = 0;
	stacks->flgs.stat = 0;
	stacks->fd = 1;
	i = 0;
	while (i < COUNT_OPERATIONS)
		stacks->stat_instr[i++] = 0;
}

int		read_flags(char **av, t_stacks *stacks)
{
	int		i;

	i = 1;
	init(stacks);
	while (ft_strequ(av[i], "-v") || ft_strequ(av[i], "-c") ||
			ft_strequ(av[i], "-f") || ft_strequ(av[i], "-e") ||
			ft_strequ(av[i], "-s"))
	{
		if (ft_strequ(av[i], "-v"))
		{
			stacks->flgs.print_stck = 1;
			i++;
		}
		if (ft_strequ(av[i], "-c"))
		{
			stacks->flgs.color = 1;
			i++;
		}
		if (ft_strequ(av[i], "-e"))
		{
			stacks->flgs.error = 1;
			i++;
		}
		if (ft_strequ(av[i], "-s"))
		{
			stacks->flgs.stat = 1;
			i++;
		}
		if (ft_strequ(av[i], "-f"))
		{
			stacks->flgs.file = 1;
			i++;
		}
		if (stacks->flgs.file)
			stacks->fd = open(av[i++], O_RDWR);
	}
	stacks->a_size -= (i - 1);
	return (i);
}

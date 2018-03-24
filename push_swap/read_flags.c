/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:51:37 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/24 16:15:59 by ahryhory         ###   ########.fr       */
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

static void	flag_on(int *flag, int *i)
{
	*flag = 1;
	*i += 1;
}

static int	check_flags(char **av, int i)
{
	if (ft_strequ(av[i], "-v") || ft_strequ(av[i], "-c") ||
			ft_strequ(av[i], "-f") || ft_strequ(av[i], "-e") ||
			ft_strequ(av[i], "-s"))
		return (1);
	else
		return (0);
}

int			read_flags(char **av, t_stacks *stacks)
{
	int		i;

	i = 1;
	init(stacks);
	while (check_flags(av, i))
	{
		if (ft_strequ(av[i], "-v"))
			flag_on(&(stacks->flgs.print_stck), &i);
		if (ft_strequ(av[i], "-c"))
			flag_on(&(stacks->flgs.color), &i);
		if (ft_strequ(av[i], "-e"))
			flag_on(&(stacks->flgs.error), &i);
		if (ft_strequ(av[i], "-s"))
			flag_on(&(stacks->flgs.stat), &i);
		if (ft_strequ(av[i], "-f"))
			flag_on(&(stacks->flgs.file), &i);
		if (stacks->flgs.file && av[i])
		{
			stacks->fd = open(av[i++], O_RDWR);
			stacks->flgs.file = 0;
		}
	}
	stacks->a_size -= (i - 1);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:51:37 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/24 16:01:43 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	init(t_stacks *stacks)
{
	int		i;

	stacks->flgs.error = 0;
	stacks->wr = 0;
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

int			read_flags(char **av, t_stacks *stacks)
{
	int		i;

	i = 1;
	init(stacks);
	while (ft_strequ(av[i], "-f") || ft_strequ(av[i], "-e") ||
			ft_strequ(av[i], "-s"))
	{
		if (ft_strequ(av[i], "-e"))
			flag_on(&(stacks->flgs.error), &i);
		if (ft_strequ(av[i], "-s"))
			flag_on(&(stacks->flgs.stat), &i);
		if (ft_strequ(av[i], "-f"))
			flag_on(&(stacks->flgs.file), &i);
		if (stacks->flgs.file && av[i])
		{
			stacks->wr = open(av[i++], O_RDWR);
			stacks->flgs.file = 0;
		}
	}
	stacks->a_size -= (i - 1);
	return (i);
}

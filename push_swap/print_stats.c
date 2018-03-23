/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:23:28 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/23 15:46:00 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_n(int num, t_stacks stacks)
{
	if (num == 0)
		ft_putstr_fd("\033[0;31m", stacks.fd);
	else
		ft_putstr_fd("\033[0;32m", stacks.fd);
	ft_putnbr_fd(num, stacks.fd);
	ft_putstr_fd("\033[0m", stacks.fd);
}

static void	first_part(t_stacks stacks)
{
	ft_putendl_fd(" ____________________", stacks.fd);
	ft_putendl_fd("|     STATISTICS     |", stacks.fd);
	ft_putendl_fd("|____________________|", stacks.fd);
	ft_putstr_fd("| sa               ", stacks.fd);
	put_n(stacks.stat_instr[0], stacks);
	ft_putendl_fd(" |\n|____________________|", stacks.fd);
	ft_putstr_fd("| sb               ", stacks.fd);
	put_n(stacks.stat_instr[1], stacks);
	ft_putendl_fd(" |\n|____________________|", stacks.fd);
	ft_putstr_fd("| ss               ", stacks.fd);
	put_n(stacks.stat_instr[2], stacks);
	ft_putendl_fd(" |\n|____________________|", stacks.fd);
	ft_putstr_fd("| pa               ", stacks.fd);
	put_n(stacks.stat_instr[3], stacks);
	ft_putendl_fd(" |\n|____________________|", stacks.fd);
	ft_putstr_fd("| pb               ", stacks.fd);
	put_n(stacks.stat_instr[4], stacks);
	ft_putendl_fd(" |\n|____________________|", stacks.fd);
	ft_putstr_fd("| ra               ", stacks.fd);
}

static void	second_part(t_stacks stacks)
{
	put_n(stacks.stat_instr[5], stacks);
	ft_putendl_fd(" |\n|____________________|", stacks.fd);
	ft_putstr_fd("| rb               ", stacks.fd);
	put_n(stacks.stat_instr[6], stacks);
	ft_putendl_fd(" |\n|____________________|", stacks.fd);
	ft_putstr_fd("| rr               ", stacks.fd);
	put_n(stacks.stat_instr[7], stacks);
	ft_putendl_fd(" |\n|____________________|", stacks.fd);
	ft_putstr_fd("| rra              ", stacks.fd);
	put_n(stacks.stat_instr[8], stacks);
	ft_putendl_fd(" |\n|____________________|", stacks.fd);
	ft_putstr_fd("| rrb              ", stacks.fd);
	put_n(stacks.stat_instr[9], stacks);
	ft_putendl_fd(" |\n|____________________|", stacks.fd);
	ft_putstr_fd("| rrr              ", stacks.fd);
	put_n(stacks.stat_instr[10], stacks);
	ft_putendl_fd(" |\n|====================|", stacks.fd);
	ft_putstr_fd("   TOTAL        ", stacks.fd);
}

void		print_stats(t_stacks stacks)
{
	int		total;
	int		i;

	i = 0;
	total = 0;
	while (i < COUNT_OPERATIONS)
		total += stacks.stat_instr[i++];
	first_part(stacks);
	second_part(stacks);
	put_n(total, stacks);
	ft_putstr_fd("\n", stacks.fd);
}

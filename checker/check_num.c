/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:27:32 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/23 16:04:13 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_num(char **av, int i, t_stacks stacks)
{
	int		j;

	while (av[i])
	{
		if (av[i][0] != '-' && av[i][0] != '+' && !ft_isdigit(av[i][0]))
			ft_error(2, stacks);
		if ((av[i][0] == '-' || av[i][0] == '+') && !ft_isdigit(av[i][1]))
			ft_error(2, stacks);
		j = 1;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				ft_error(2, stacks);
			j++;
		}
		i++;
	}
}

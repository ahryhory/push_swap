/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:13:26 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/22 16:35:25 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stacks(t_stacks stacks)
{
	int		i;

	ft_putendl_fd("====STACK A====", stacks.fd);
	i = 0;
	while (i < stacks.a_size)
	{
		ft_putnbr_fd(stacks.a_int[i].num, stacks.fd);
		i++;
		ft_putstr_fd("\n", stacks.fd);
	}
	ft_putendl_fd("====STACK B====", stacks.fd);
	i = 0;
	while (i < stacks.b_size)
	{
		ft_putnbr_fd(stacks.b_int[i].num, stacks.fd);
		i++;
		ft_putstr_fd("\n", stacks.fd);
	}
	ft_putstr_fd("\n\n", stacks.fd);
}

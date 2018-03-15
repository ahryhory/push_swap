/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:13:26 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/15 15:30:10 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		print_stacks(t_stacks stacks)
{
	int		i;

	ft_putendl("====STACK A====");
	ft_putstr("size: ");
	ft_putnbr(stacks.a_size);
	ft_putstr("\n");
	i = 0;
	while (i < stacks.a_size)
	{
		ft_putnbr(stacks.a_int[i++]);
		ft_putstr("\n");
	}
	ft_putendl("====STACK B====");
	ft_putstr("size: ");
	ft_putnbr(stacks.b_size);
	ft_putstr("\n");
	i = 0;
	while (i < stacks.b_size)
	{
		ft_putnbr(stacks.b_int[i++]);
		ft_putstr("\n");
	}
	ft_putstr("\n\n");
}

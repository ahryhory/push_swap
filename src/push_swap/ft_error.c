/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:02:26 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/24 17:53:37 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int num, t_stacks stacks)
{
	if (num == 2 && stacks.flgs.error)
		ft_putendl_fd("Some arguments aren’t integers", 2);
	else if (num == 3 && stacks.flgs.error)
		ft_putendl_fd("Some arguments are bigger than an integer", 2);
	else if (num == 4 && stacks.flgs.error)
		ft_putendl_fd("Duplicates", 2);
	else if (num == 6 && stacks.flgs.error)
		ft_putendl_fd("File not found", 2);
	else
		ft_putendl_fd("Error", 2);
	exit(1);
}

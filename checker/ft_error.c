/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:02:26 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/23 16:17:52 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(int num, t_stacks stacks)
{
	if (num == 2 && stacks.flgs.error)
		ft_putendl_fd("Some arguments aren’t integers", 2);
	else if (num == 3 && stacks.flgs.error)
		ft_putendl_fd("Some arguments are bigger than an integer", 2);
	else if (num == 4 && stacks.flgs.error)
		ft_putendl_fd("Duplicates", 2);
	else if (num == 5 && stacks.flgs.error)
		ft_putendl_fd("Instruction don’t exist and/or is incorrectly formatted", 2);
	else
		ft_putendl_fd("Error", 2);
	exit(0);
}

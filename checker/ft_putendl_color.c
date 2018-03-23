/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:18:31 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/23 16:04:50 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_putendl_color(char *s, int num, int fd)
{
	if (num == 1)
	{
		ft_putstr_fd("\033[0;32m", fd);
		ft_putendl_fd(s, fd);
		ft_putstr_fd("\033[0m", fd);
	}
	else if (num == 2)
	{
		ft_putstr_fd("\033[0;31m", fd);
		ft_putendl_fd(s, fd);
		ft_putstr_fd("\033[0m", fd);
	}
}

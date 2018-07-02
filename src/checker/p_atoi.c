/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:57:38 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/23 16:05:18 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			p_atoi(const char *str, t_stacks stacks)
{
	unsigned long long	num;
	short				neg;

	num = 0;
	neg = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str && '0' <= *str && *str <= '9')
		num = num * 10 + (*str++ - '0');
	if ((neg == 1 && num > 2147483647) || (neg == -1 && num > 2147483648))
		ft_error(3, stacks);
	return ((int)(num * neg));
}

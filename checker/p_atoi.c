/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:57:38 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/22 15:07:11 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			p_atoi(const char *str)
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
	if (num > 9223372036854775807 && neg == -1)
		return (0);
	if (num > 9223372036854775807)
		return (-1);
	if ((neg == 1 && num > 2147483647) || (neg == -1 && num > 2147483648))
		ft_error(3);
	return ((int)(num * neg));
}

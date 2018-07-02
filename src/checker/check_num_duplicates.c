/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_duplicates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:29:01 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/23 16:04:25 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_num_duplicates(t_stacks stacks)
{
	int		i;
	int		j;

	i = 0;
	while (i < stacks.a_size - 1)
	{
		j = i + 1;
		while (j < stacks.a_size)
		{
			if (stacks.a_int[i].num == stacks.a_int[j].num)
				ft_error(4, stacks);
			j++;
		}
		i++;
	}
}

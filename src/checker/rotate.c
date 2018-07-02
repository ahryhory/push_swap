/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:16:34 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/22 15:26:46 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate_a(t_stacks *stacks)
{
	int		size;
	int		i;
	t_arr	tmp;

	i = 0;
	size = stacks->a_size - 1;
	tmp = stacks->a_int[0];
	while (i < size)
	{
		stacks->a_int[i] = stacks->a_int[i + 1];
		i++;
	}
	stacks->a_int[i] = tmp;
}

static void	rotate_b(t_stacks *stacks)
{
	int		size;
	int		i;
	t_arr	tmp;

	i = 0;
	size = stacks->b_size - 1;
	tmp = stacks->b_int[0];
	while (i < size)
	{
		stacks->b_int[i] = stacks->b_int[i + 1];
		i++;
	}
	stacks->b_int[i] = tmp;
}

void		rotate(t_stacks *stacks, char *buf)
{
	if (ft_strequ(buf, ROTATE_A) || ft_strequ(buf, ROTATE_AB))
		rotate_a(stacks);
	if (ft_strequ(buf, ROTATE_B) || ft_strequ(buf, ROTATE_AB))
		rotate_b(stacks);
}

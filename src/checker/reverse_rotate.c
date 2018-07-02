/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:11:49 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/22 15:26:58 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate_a(t_stacks *stacks)
{
	int		size;
	int		i;
	t_arr	tmp;

	i = 1;
	size = stacks->a_size;
	tmp = stacks->a_int[size - 1];
	while (i <= size)
	{
		stacks->a_int[size - i + 1] = stacks->a_int[size - i];
		i++;
	}
	stacks->a_int[0] = tmp;
}

static void	reverse_rotate_b(t_stacks *stacks)
{
	int		size;
	int		i;
	t_arr	tmp;

	i = 1;
	size = stacks->b_size;
	tmp = stacks->b_int[size - 1];
	while (i <= size)
	{
		stacks->b_int[size - i + 1] = stacks->b_int[size - i];
		i++;
	}
	stacks->b_int[0] = tmp;
}

void		reverse_rotate(t_stacks *stacks, char *buf)
{
	if (ft_strequ(buf, REVERSE_ROTATE_A) || ft_strequ(buf, REVERSE_ROTATE_AB))
		reverse_rotate_a(stacks);
	if (ft_strequ(buf, REVERSE_ROTATE_B) || ft_strequ(buf, REVERSE_ROTATE_AB))
		reverse_rotate_b(stacks);
}

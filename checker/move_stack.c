/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:32:54 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/23 16:05:05 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_stacks *stacks, char *buf)
{
	t_arr		tmp;

	if ((ft_strequ(buf, SWAP_A) || ft_strequ(buf, SWAP_AB)) &&
			stacks->a_size >= 2)
	{
		tmp = stacks->a_int[0];
		stacks->a_int[0] = stacks->a_int[1];
		stacks->a_int[1] = tmp;
	}
	if ((ft_strequ(buf, SWAP_B) || ft_strequ(buf, SWAP_AB)) &&
			stacks->b_size >= 2)
	{
		tmp = stacks->b_int[0];
		stacks->b_int[0] = stacks->b_int[1];
		stacks->b_int[1] = tmp;
	}
}

static void	add_stat(t_stacks *stacks, char *buf)
{
	if (ft_strequ(buf, SWAP_A))
		stacks->stat_instr[0] += 1;
	else if (ft_strequ(buf, SWAP_B))
		stacks->stat_instr[1] += 1;
	else if (ft_strequ(buf, SWAP_AB))
		stacks->stat_instr[2] += 1;
	else if (ft_strequ(buf, PUSH_A))
		stacks->stat_instr[3] += 1;
	else if (ft_strequ(buf, PUSH_B))
		stacks->stat_instr[4] += 1;
	else if (ft_strequ(buf, ROTATE_A))
		stacks->stat_instr[5] += 1;
	else if (ft_strequ(buf, ROTATE_B))
		stacks->stat_instr[6] += 1;
	else if (ft_strequ(buf, ROTATE_AB))
		stacks->stat_instr[7] += 1;
	else if (ft_strequ(buf, REVERSE_ROTATE_A))
		stacks->stat_instr[8] += 1;
	else if (ft_strequ(buf, REVERSE_ROTATE_B))
		stacks->stat_instr[9] += 1;
	else if (ft_strequ(buf, REVERSE_ROTATE_AB))
		stacks->stat_instr[10] += 1;
}

void		move_stack(t_stacks *stacks, char *buf)
{
	if (stacks->flgs.stat)
		add_stat(stacks, buf);
	if (ft_strequ(buf, SWAP_A) || ft_strequ(buf, SWAP_B)
			|| ft_strequ(buf, SWAP_AB))
		swap(stacks, buf);
	else if (ft_strequ(buf, PUSH_A) || ft_strequ(buf, PUSH_B))
		push(stacks, buf);
	else if (ft_strequ(buf, ROTATE_A) || ft_strequ(buf, ROTATE_B)
			|| ft_strequ(buf, ROTATE_AB))
		rotate(stacks, buf);
	else if (ft_strequ(buf, REVERSE_ROTATE_A)
			|| ft_strequ(buf, REVERSE_ROTATE_B)
			|| ft_strequ(buf, REVERSE_ROTATE_AB))
		reverse_rotate(stacks, buf);
	if (stacks->flgs.color && is_stack_sorted(*stacks) &&
			stacks->b_size == 0)
		ft_putendl_color(buf, 1, stacks->fd);
	else
		ft_putendl_fd(buf, stacks->fd);
	if (stacks->flgs.print_stck)
		print_stacks(*stacks);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:32:54 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/16 17:18:04 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stacks *stacks, char *buf)
{
	t_arr		tmp;

	if ((ft_strequ(buf, SWAP_A) || ft_strequ(buf, SWAP_AB)) &&
			stacks->a_size >=2)
	{
		tmp = stacks->a_int[0];
		stacks->a_int[0] = stacks->a_int[1];
		stacks->a_int[1] = tmp;
	}
	if ((ft_strequ(buf, SWAP_B) || ft_strequ(buf, SWAP_AB)) &&
			stacks->b_size >=2)
	{
		tmp = stacks->b_int[0];
		stacks->b_int[0] = stacks->b_int[1];
		stacks->b_int[1] = tmp;
	}
}

static void	push(t_stacks *stacks, char *buf)
{
	int		i;
	int		size;

	if (ft_strequ(buf, PUSH_A) && stacks->b_size >= 1)
	{
		i = 1;
		size = stacks->a_size;
		while (i <= size)
		{
			stacks->a_int[size - i + 1] = stacks->a_int[size - i];
			i++;
		}
		stacks->a_int[0] = stacks->b_int[0];
		i = 0;
		size = stacks->b_size - 1;
		while (i < size)
		{
			stacks->b_int[i] = stacks->b_int[i + 1];
			i++;
		}
		stacks->b_size -= 1;
		stacks->a_size += 1;
	}
	else if (ft_strequ(buf, PUSH_B) && stacks->a_size >= 1)
	{
		i = 1;
		size = stacks->b_size;
		while (i <= size)
		{
			stacks->b_int[size - i + 1] = stacks->b_int[size - i];
			i++;
		}
		stacks->b_int[0] = stacks->a_int[0];
		i = 0;
		size = stacks->a_size - 1;
		while (i < size)
		{
			stacks->a_int[i] = stacks->a_int[i + 1];
			i++;
		}
		stacks->a_size -= 1;
		stacks->b_size += 1;
	}
}

static void	rotate(t_stacks *stacks, char *buf)
{
	int		size;
	int		i;
	t_arr	tmp;

	if (ft_strequ(buf, ROTATE_A) || ft_strequ(buf, ROTATE_AB))
	{
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
	if (ft_strequ(buf, ROTATE_B) || ft_strequ(buf, ROTATE_AB))
	{
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
}

static void	reverse_rotate(t_stacks *stacks, char *buf)
{
	int		size;
	int		i;
	t_arr	tmp;

	if (ft_strequ(buf, REVERSE_ROTATE_A) || ft_strequ(buf, REVERSE_ROTATE_AB))
	{
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
	if (ft_strequ(buf, REVERSE_ROTATE_B) || ft_strequ(buf, REVERSE_ROTATE_AB))
	{
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
}

void		move_stack(t_stacks *stacks, char *buf)
{
	ft_putendl(buf);
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
}

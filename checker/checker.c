/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:51:45 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/23 16:17:54 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_instruct(t_instruct *head, t_stacks stacks)
{
	t_instruct	*instrct;
	char		*s;

	instrct = head;
	while (instrct->next)
	{
		s = instrct->instruct;
		if (!ft_strequ(s, SWAP_A) && !ft_strequ(s, SWAP_B) &&
				!ft_strequ(s, SWAP_AB) && !ft_strequ(s, PUSH_A) &&
				!ft_strequ(s, PUSH_B) && !ft_strequ(s, ROTATE_A) &&
				!ft_strequ(s, ROTATE_B) && !ft_strequ(s, ROTATE_AB) &&
				!ft_strequ(s, REVERSE_ROTATE_A) &&
				!ft_strequ(s, REVERSE_ROTATE_B) &&
				!ft_strequ(s, REVERSE_ROTATE_AB))
			ft_error(5, stacks);
		instrct = instrct->next;
	}
}

static void	checker_sort(t_stacks *stacks)
{
	t_instruct	*instrct;
	t_instruct	*head;

	instrct = (t_instruct *)malloc(sizeof(t_instruct));
	instrct->next = NULL;
	head = instrct;
	if (stacks->wr)
		while (ft_get_next_line(stacks->wr, &(instrct->instruct)))
		{
			instrct->next = (t_instruct *)malloc(sizeof(t_instruct));
			instrct = instrct->next;
			instrct->next = NULL;
		}
	else
		while (ft_get_next_line(0, &(instrct->instruct)))
		{
			instrct->next = (t_instruct *)malloc(sizeof(t_instruct));
			instrct = instrct->next;
			instrct->next = NULL;
		}
	check_instruct(head, *stacks);
	instrct = head;
	while (instrct->next)
	{
		move_stack(stacks, instrct->instruct);
		ft_strdel(&(instrct->instruct));
		instrct = instrct->next;
	}
	if (is_stack_sorted(*stacks))
		ft_putendl("OK");
	else
		ft_putendl("KO");
}

int			main(int ac, char **av)
{
	t_stacks	stacks;
	int			i;
	int			j;

	if (ac == 1)
		exit(1);
	stacks.a_size = ac - 1;
	stacks.b_size = 0;
	stacks.a_int = (t_arr *)malloc(sizeof(t_arr) * ac);
	stacks.b_int = (t_arr *)malloc(sizeof(t_arr) * ac);
	i = read_flags(av, &stacks);
	check_num(av, i, stacks);
	j = 0;
	while (j < stacks.a_size)
	{
		stacks.a_int[j].num = p_atoi(av[i], stacks);
		j++;
		i++;
	}
	check_num_duplicates(stacks);
	if (stacks.flgs.print_stck)
		print_stacks(stacks);
	checker_sort(&stacks);
	if (stacks.flgs.stat)
		print_stats(stacks);
	close(stacks.fd);
	return (0);
}

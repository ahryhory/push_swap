/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:51:45 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/22 15:44:17 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_num(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		if (av[i][0] != '-' && av[i][0] != '+' && !ft_isdigit(av[i][0]))
			ft_error(2);
		if ((av[i][0] == '-' || av[i][0] == '+') && !ft_isdigit(av[i][1]))
			ft_error(2);
		j = 1;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				ft_error(2);
			j++;
		}
		i++;
	}
}

static void	check_instruct(t_instruct *head)
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
			ft_error(1);
		instrct = instrct->next;
	}
}

static void	check_num_duplicates(t_stacks stacks)
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
				ft_error(4);
			j++;
		}
		i++;
	}
}

static void	checker_sort(t_stacks stacks)
{
	t_instruct	*instrct;
	t_instruct	*head;

	instrct = (t_instruct *)malloc(sizeof(t_instruct));
	instrct->next = NULL;
	head = instrct;
	while (ft_get_next_line(0, &(instrct->instruct)))
	{
		instrct->next = (t_instruct *)malloc(sizeof(t_instruct));
		instrct = instrct->next;
		instrct->next = NULL;
	}
	check_instruct(head);
	instrct = head;
	while (instrct->next)
	{
		move_stack(&stacks, instrct->instruct);
		ft_strdel(&(instrct->instruct));
		instrct = instrct->next;
	}
	if (is_stack_sorted(stacks))
		ft_putendl("OK");
	else
		ft_putendl("KO");
}

int			main(int ac, char **av)
{
	t_stacks	stacks;
	int			i;

	if (ac == 1)
		exit(1);
	check_num(av);
	stacks.a_size = ac - 1;
	stacks.b_size = 0;
	stacks.a_int = (t_arr *)malloc(sizeof(t_arr) * ac);
	stacks.b_int = (t_arr *)malloc(sizeof(t_arr) * ac);
	i = 0;
	while (i < stacks.a_size)
	{
		stacks.a_int[i].num = p_atoi(av[i + 1]);
		i++;
	}
	check_num_duplicates(stacks);
	checker_sort(stacks);
	return (0);
}

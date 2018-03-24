/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:23:41 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/24 15:32:59 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define SWAP_A "sa"
# define SWAP_B "sb"
# define SWAP_AB "ss"
# define PUSH_A "pa"
# define PUSH_B "pb"
# define ROTATE_A "ra"
# define ROTATE_B "rb"
# define ROTATE_AB "rr"
# define REVERSE_ROTATE_A "rra"
# define REVERSE_ROTATE_B "rrb"
# define REVERSE_ROTATE_AB "rrr"
# define COUNT_OPERATIONS 11

typedef struct			s_arr
{
	int					num;
	int					median;
}						t_arr;

typedef struct			s_flags
{
	int					stat;
	int					file;
	int					error;
}						t_flags;

typedef struct			s_stacks
{
	t_arr				*a_int;
	t_arr				*b_int;
	t_flags				flgs;
	int					stat_instr[COUNT_OPERATIONS];
	int					fd;
	int					wr;
	int					a_size;
	int					b_size;
}						t_stacks;

typedef struct			s_instruct
{
	char				*instruct;
	struct s_instruct	*next;
}						t_instruct;

void					move_stack(t_stacks *stacks, char *buf);
void					push(t_stacks *stacks, char *buf);
void					rotate(t_stacks *stacks, char *buf);
void					reverse_rotate(t_stacks *stacks, char *buf);
int						is_stack_sorted(t_stacks stacks);
void					print_stacks(t_stacks stacks);
int						read_flags(char **av, t_stacks *stacks);
void					print_stats(t_stacks stacks);
void					ft_putendl_color(char *s, int num, int fd);
int						p_atoi(const char *str, t_stacks stacks);
void					check_num(char **av, int i, t_stacks stacks);
void					check_num_duplicates(t_stacks stacks);
void					ft_error(int num, t_stacks stacks);

#endif

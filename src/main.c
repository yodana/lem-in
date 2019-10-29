/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:09:18 by manki             #+#    #+#             */
/*   Updated: 2019/10/09 16:21:48 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void		ft_error_bis(t_all *all, char str[], char fd, t_list **list)
{
	free_all(all);
	if (list && list[0])
		ft_lstdel_2(list);
	ft_error(str, fd);
}

static void		ft_init(t_all *all, char *end, t_queue **sol, t_list **list)
{
	all->room = NULL;
	all->args = ft_memalloc(ARGS_NUMBER);
	all->command_stack = NULL;
	all->ants = -1;
	all->path_cost = NULL;
	all->ant_nb = NULL;
	all->old_path_cost = NULL;
	all->old_ant_nb = NULL;
	all->total_of_lines = -1;
	end[0] = 0;
	sol[0] = NULL;
	list[0] = NULL;
	all->way = 0;
}

static char		ft_analyse_input(char **input, t_all *all, t_list **list)
{
	char		end_input;

	end_input = 0;
	if (!ft_check_map(*input, ft_check_line(*input), all))
	{
		if (ft_map_enough_to_launch(all))
			end_input = 1;
		else
		{
			ft_strdel(input);
			ft_error_bis(all, "ERROR", 2, list);
		}
	}
	if (!list && !list[0] && !end_input)
		list[0] = ft_lstnew(input[0], ft_strlen(input[0]));
	else if (!end_input)
		ft_lsadd(list, input[0], ft_strlen(input[0]));
	ft_strdel(input);
	return (end_input);
}

void			ft_disp_solution(t_queue **sol, t_list **input_list, t_all *all)
{
	if (sol && sol[0])
	{
		//ft_lstprint(*input_list, '\n');
		write(1, "\n", 1);
		display(sol, all->ants);
		if (all->args[2] == 1)
			ft_printf("Number of lines == %d\n", sol[0]->c_t);
		ft_free_queue(sol);
	}
	ft_lstdel_2(input_list);
	free_all(all);
}

int				main(int ac, char **av)
{
	char		*input;
	t_list		*input_list;
	t_all		all;
	char		end_input;
	t_queue		*solution;

	ft_init(&all, &end_input, &solution, &input_list);
	ft_check_arg(ac, av, &all);
	while (!end_input && get_next_line(0, &input) == 1)
		end_input = ft_analyse_input(&input, &all, &input_list);
	if (ft_map_enough_to_launch(&all))
	{
		ft_printf("ok");
		if (!(solution = ft_breadth_first_search(&all)))
		{
			if (input)
				ft_strdel(&input);
			ft_error_bis(&all, "ERROR", 2, &input_list);
		}
	}
	else
		ft_error_bis(&all, "ERROR", 2, &input_list);
	ft_disp_solution(&solution, &input_list, &all);
	return (0);
}

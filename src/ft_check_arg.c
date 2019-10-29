/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:53:36 by manki             #+#    #+#             */
/*   Updated: 2019/10/03 14:18:56 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void		ft_print_usage(t_all **all)
{
	ft_putendl("Usage:\t./lem-in [-vcl] <map>\n");
	ft_putendl("\t-v,\t\tto use visu-hex.py visualizer");
	ft_putendl("\t-c,\t\tto see output with colors");
	ft_putendl("\t-l,\t\tto see the numbers of lines");
	if (all != NULL)
		free_all(all[0]);
	exit(-2);
}

static char		ft_check_one(char arg[], t_all **all)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == 'v')
			all[0]->args[0] = 1;
		else if (arg[i] == 'c')
			all[0]->args[1] = 1;
		else if (arg[i] == 'l')
			all[0]->args[2] = 1;
		else
			ft_print_usage(all);
		i++;
	}
	return (1);
}

void			ft_check_arg(int ac, char *av[], t_all *all)
{
	int		i;

	ac++;
	if (ac > 2)
	{
		i = 0;
		while (av[++i] && av[i][0] == '-')
		{
			if (av[i][0] == '-' && av[i][1])
				ft_check_one(&av[i][1], &all);
			else if (av[i][0] == '-')
				ft_print_usage(&all);
		}
	}
}

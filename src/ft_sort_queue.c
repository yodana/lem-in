/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 11:56:12 by yodana            #+#    #+#             */
/*   Updated: 2019/10/09 11:29:21 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		ft_sort_queue(t_queue **sol)
{
	t_queue		*tmp;
	t_room		*swap;
	int			keep_going;

	keep_going = 1;
	while (keep_going)
	{
		tmp = sol[0];
		keep_going = 0;
		while (tmp && tmp->next)
		{
			if (calc_nodes(tmp->room) > calc_nodes(tmp->next->room))
			{
				swap = tmp->room;
				tmp->room = tmp->next->room;
				tmp->next->room = swap;
				keep_going = 1;
			}
			tmp = tmp->next;
		}
	}
}

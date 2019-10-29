/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:59:53 by yodana            #+#    #+#             */
/*   Updated: 2019/10/09 11:47:06 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		ft_inside_sol(t_queue *sol)
{
	t_queue *tmp;

	tmp = sol;
	while (tmp)
	{
		ft_printf("path name : %s\n", tmp->room->name);
		ft_printf("path cost : %d\n", ft_solution_len(tmp->room));
		ft_putendl("//////////////");
		tmp = tmp->next;
	}
	ft_putendl("//////////////");
}

char		ft_has_loop(t_room *room)
{
	t_room		*tmp1;
	t_room		*tmp2;

	tmp1 = room;
	while (tmp1)
	{
		tmp2 = room->parent;
		while (tmp2)
		{
			if (tmp1 == tmp2)
				return (1);
			tmp2 = tmp2->parent;
		}
		tmp1 = tmp1->parent;
	}
	return (0);
}

void		ft_reset_visit(t_all **map)
{
	t_room	*tmp;

	tmp = map[0]->room;
	while (tmp)
	{
		tmp->visit = 0;
		tmp = tmp->next;
	}
}

char		ft_end_is_a_child(t_room *room, t_room *end)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp == end)
			return (1);
		if (tmp->child && tmp->child != end && tmp->child->parent != tmp)
			return (0);
		tmp = tmp->child;
	}
	return (0);
}

char		ft_start_is_a_parent(t_room *room, t_room *start)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp == start)
			return (1);
		if (tmp->parent && tmp->parent != start && tmp->parent->child != tmp)
			return (0);
		tmp = tmp->parent;
	}
	return (0);
}

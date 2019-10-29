/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 11:56:12 by yodana            #+#    #+#             */
/*   Updated: 2019/09/26 12:29:02 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		set_next(t_queue **cpy, t_queue **before, t_queue **next)
{
	(*cpy)->next = (*next)->next;
	(*next)->next = *cpy;
	(*before) = *next;
	*next = (*cpy)->next;
}

int			sort(t_queue *cpy, t_queue *before, t_queue *next, t_queue **first)
{
	int		i;

	i = 0;
	before = NULL;
	cpy = first[0];
	next = cpy->next;
	while (next)
	{
		if (cpy->nodes > cpy->next->nodes)
		{
			i = 1;
			if (before == NULL)
				first[0] = next;
			else
				before->next = next;
			set_next(&cpy, &before, &next);
		}
		else
		{
			before = cpy;
			cpy = cpy->next;
			next = cpy->next;
		}
	}
	return (i);
}

t_queue		*sort_lst(t_queue *display)
{
	t_queue		*cpy;
	t_queue		*before;
	t_queue		*next;
	t_queue		**first;

	first = &display;
	before = NULL;
	cpy = display;
	next = cpy->next;
	while (sort(cpy, before, next, first))
		;
	return (*first);
}

int			calc_nodes(t_room *room)
{
	t_room	*tmp;
	int		c;

	c = 0;
	tmp = room;
	while (tmp)
	{
		tmp = tmp->child;
		c++;
	}
	return (c);
}

int			total_ants(int *ants, int size)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (i < size)
	{
		res = res + ants[i];
		i++;
	}
	return (res);
}

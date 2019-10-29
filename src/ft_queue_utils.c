/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:52:44 by manki             #+#    #+#             */
/*   Updated: 2019/09/16 13:58:29 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_queue		*ft_create_queue(t_room **room)
{
	t_queue	*fresh;

	if (!(fresh = (t_queue *)malloc(sizeof(t_queue) * 2)))
		return (NULL);
	fresh->room = room[0];
	fresh->next = NULL;
	return (fresh);
}

void		ft_enqueue(t_queue **list, t_room **room)
{
	t_queue	*tmp;
	t_queue	*list_copy;

	tmp = ft_create_queue(room);
	if (list && list[0] && tmp)
	{
		list_copy = *list;
		tmp->next = list_copy;
	}
	list[0] = tmp;
}

t_queue		*ft_dequeue(t_queue **list)
{
	t_queue		*tmp;
	t_queue		*previous;
	t_queue		*ret;

	ret = NULL;
	if (list && *list)
	{
		previous = list[0];
		tmp = list[0];
		while (tmp && tmp->next)
		{
			previous = tmp;
			tmp = tmp->next;
		}
		ret = tmp;
		if (previous != tmp)
			previous->next = NULL;
		else
			list[0] = NULL;
	}
	return (ret);
}

void		ft_free_queue(t_queue **list)
{
	t_queue		*tmp;
	t_queue		*to_del;

	tmp = list[0];
	while (tmp)
	{
		to_del = tmp;
		tmp = tmp->next;
		free(to_del);
	}
	list[0] = NULL;
}

int			ft_queue_len(t_queue *queue)
{
	t_queue	*tmp;
	int		i;

	i = 0;
	tmp = queue;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

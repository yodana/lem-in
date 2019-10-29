/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 11:12:35 by manki             #+#    #+#             */
/*   Updated: 2019/10/09 11:19:51 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		check_end(t_room **room, int size)
{
	int		i;
	t_room	**tmp;
	int		c;

	c = 0;
	tmp = room;
	i = 0;
	while (i < size)
	{
		if (tmp[i])
			return (-1);
		i++;
	}
	if (c > 0)
		return (-1);
	return (1);
}

t_room	*chose_display(t_queue *display, int size)
{
	t_queue	*tmp_q;
	int		i;

	i = 0;
	tmp_q = display;
	if (size >= ft_queue_len(display))
	{
		if (tmp_q->ants == 0)
			return (NULL);
		tmp_q->ants = tmp_q->ants - 1;
		return (tmp_q->room);
	}
	while (tmp_q && i < size)
	{
		tmp_q = tmp_q->next;
		i++;
	}
	if (tmp_q->ants == 0)
		return (NULL);
	tmp_q->ants = tmp_q->ants - 1;
	return (tmp_q->room);
}

void	stock_ants_sol(int *ants, t_queue *display, int c_ants, int size)
{
	int		c;
	t_queue	*tmp_q;

	tmp_q = display;
	c = 0;
	while (total_ants(ants, ft_queue_len(display)) < c_ants)
	{
		ants[c]++;
		c++;
		if (c >= size)
			c = 0;
	}
	c = 0;
	tmp_q = display;
	while (tmp_q)
	{
		tmp_q->ants = ants[c];
		c++;
		tmp_q = tmp_q->next;
	}
}

void	chose_ants(int *ants, int c_ants, int size, t_queue **display)
{
	t_queue	*tmp_q;
	int		i;
	int		worst;

	worst = 0;
	i = 0;
	tmp_q = *display;
	while (i < ft_queue_len(*display))
	{
		tmp_q->nodes = calc_nodes(tmp_q->room);
		tmp_q->nodes >= worst ? worst = tmp_q->nodes : tmp_q->nodes;
		i++;
		tmp_q = tmp_q->next;
	}
	*display = sort_lst(*display);
	display[0]->c_t = 1;
	tmp_q = *display;
	i = 0;
	while (tmp_q && i < size)
	{
		ants[i] = 1 + (worst - calc_nodes(tmp_q->room));
		tmp_q = tmp_q->next;
		i++;
	}
	stock_ants_sol(ants, *display, c_ants, size);
}

void	stock_room_sol(t_room **tmp, t_queue *display, int c_ants)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (k < c_ants)
	{
		if (i >= ft_queue_len(display))
			i = 0;
		tmp[k] = chose_display(display, i);
		if (tmp[k])
			k++;
		i++;
	}
	tmp[k] = NULL;
}

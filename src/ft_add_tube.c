/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:50:15 by manki             #+#    #+#             */
/*   Updated: 2019/09/09 13:55:45 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int				ft_tab_len(t_room *r)
{
	int		i;

	i = 0;
	if (r && r->tab)
	{
		while (r->tab[i])
			i++;
	}
	return (i);
}

static int		ft_copy_tab(t_room **src, t_room **dest)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

static char		ft_already_exist(t_room **tab, t_room *search)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		if (tab[i] == search)
			return (1);
		i++;
	}
	return (0);
}

static char		ft_connect(t_room **room_a, t_room **room_b)
{
	int		i;
	t_room	**tmp;

	if (!ft_already_exist(room_a[0]->tab, room_b[0]))
	{
		tmp = room_a[0]->tab;
		if (!(room_a[0]->tab = (t_room **)malloc(sizeof(t_room *) *
						(ft_tab_len(*room_a) + 2))))
			return (0);
		if (tmp)
		{
			i = ft_copy_tab(tmp, room_a[0]->tab);
			room_a[0]->tab[i] = room_b[0];
			room_a[0]->tab[i + 1] = NULL;
			free(tmp);
			tmp = NULL;
		}
		else
		{
			room_a[0]->tab[0] = room_b[0];
			room_a[0]->tab[1] = NULL;
		}
	}
	return (1);
}

char			ft_add_tube(t_room **list, char *room_a, char *room_b)
{
	t_room	*tmp;
	t_room	*r_a;
	t_room	*r_b;
	char	ok;

	if (*list)
	{
		r_a = NULL;
		r_b = NULL;
		tmp = *list;
		ok = 0;
		while (tmp && !ok)
		{
			if (!ft_strcmp(tmp->name, room_a))
				r_a = tmp;
			else if (!ft_strcmp(tmp->name, room_b))
				r_b = tmp;
			if (r_a && r_b)
				ok = 1;
			tmp = tmp->next;
		}
		return (ft_connect(&r_a, &r_b) + ft_connect(&r_b, &r_a));
	}
	return (0);
}

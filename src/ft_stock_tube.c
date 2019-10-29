/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_tube.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:11:01 by manki             #+#    #+#             */
/*   Updated: 2019/09/09 12:36:56 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static char		ft_both_are_room(char **split, t_room *list)
{
	char	room_a;
	char	room_b;
	t_room	*tmp;

	room_a = 0;
	room_b = 0;
	tmp = list;
	while (tmp)
	{
		if (!ft_strcmp(split[0], tmp->name) && !room_a)
			room_a++;
		else if (!ft_strcmp(split[1], tmp->name) && !room_b)
			room_b++;
		tmp = tmp->next;
	}
	return (room_a && room_b);
}

char			ft_cmp(char str1[], char str2[], char ref1[], char ref2[])
{
	if (!ft_strcmp(str1, ref1) && !ft_strcmp(str2, ref2))
		return (1);
	else if (!ft_strcmp(str1, ref2) && !ft_strcmp(str2, ref1))
		return (1);
	else
		return (0);
}

char			ft_stock_tube(char *input, t_all **map)
{
	char	**split;
	char	ret;

	ret = 0;
	if (!(split = ft_strsplit(input, '-')))
		return (0);
	if (ft_both_are_room(split, map[0]->room))
	{
		ft_add_tube(&map[0]->room, split[0], split[1]);
		ret = 1;
	}
	ft_strrdel(split);
	return (ret);
}

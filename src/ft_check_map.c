/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:27:37 by manki             #+#    #+#             */
/*   Updated: 2019/09/18 14:22:54 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static char		ft_stock_command(char *str, t_all **map)
{
	map[0]->command_stack = ft_strdup(str);
	return (1);
}

static char		ft_have_tube(t_room *room)
{
	t_room		*tmp;

	tmp = room;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->tab)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

static char		ft_start_and_end_there(t_all *map)
{
	t_room		*tmp;
	char		end;
	char		start;

	end = 0;
	start = 0;
	tmp = map->room;
	while (tmp)
	{
		if (tmp->command == CMD_START)
			start++;
		else if (tmp->command == CMD_END)
			end++;
		tmp = tmp->next;
	}
	if (start == 1 && end == 1)
		return (1);
	else
		return (0);
}

char			ft_check_map(char *input, char line_id, t_all *map)
{
	if (line_id == NUMBER && map->ants < 0)
		map->ants = ft_atoi(input);
	else if (line_id == ROOM && map->ants > 0 && !ft_have_tube(map->room))
		return (ft_stock_room(input, &map->room, &map->command_stack));
	else if (line_id == TUBE && map->ants > 0 && map->room != NULL &&
			map->command_stack == NULL)
		return (ft_stock_tube(input, &map));
	else if (line_id == COMMAND && map->command_stack == NULL)
		return (ft_stock_command(input, &map));
	else if (line_id != COMMENT)
		return (ERROR);
	return (1);
}

char			ft_map_enough_to_launch(t_all *map)
{
	char	ret;

	ret = 1;
	if (map->ants <= 0 || ft_room_lstlen(map->room) < 2 ||
			!ft_have_tube(map->room) || !ft_start_and_end_there(map))
		ret = 0;
	return (ret);
}

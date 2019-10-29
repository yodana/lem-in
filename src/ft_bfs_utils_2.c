/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:04:47 by manki             #+#    #+#             */
/*   Updated: 2019/10/09 15:46:29 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_stock_solution(t_queue **sol, t_all **map)
{
	t_room		*tmp;
	t_room		*start;
	t_room		*end;

	start = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_START));
	end = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_END));
	tmp = map[0]->room;
	while (tmp)
	{
		if ((tmp->parent && tmp->parent == start)
				|| (tmp == end && tmp->old_parent == start))
		{	
			ft_enqueue(sol, &tmp);
			//ft_printf("room name == %s\n", tmp->name);
		}
		tmp = tmp->next;
	}
	if (!sol[0] && start->child && start->child == end)
		ft_enqueue(sol, &start);
	ft_sort_queue(sol);
}

int		ft_another_path_exist(t_all *map, t_room **room)
{
	t_room	*start;
	int		i;
	t_room *tmp;
	t_room *end;

	end = ft_get_room(&map->room, ft_get_room_pos_by_cmd(map->room,
				CMD_END));
	tmp = *room;
	ft_printf( YELLOW "in another path == %s  || " END_COLOR, tmp->name);
	start = ft_get_room(&map->room, ft_get_room_pos_by_cmd(map->room,
				CMD_START));
	i = -1;

	while (room[++i])
	{
		if (room[i]->visit == 0 && room[i]->child == NULL && room[i] != start && room[i]->way == 0 && room[i] != end)
			return (1);
	}
	ft_printf (" pas d autre chemins");
	return (0);
}

void	ft_visit_node(t_room **room, t_all **map, char *stop)
{
	t_room	*end;
	t_room	*start;
	int		i;

	start = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_START));
	end = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_END));
	i = -1;
	while (room[0]->tab && room[0]->tab[++i] && !stop[0])
	{
		//if (ft_strcmp(room[0]->name, "1") == 0)
		//	ft_printf("pour 1 je passe a 3 == %s ", room[0]->tab[i]->name);
		if (room[0]->tab[i] == end && !(room[0] == start && start->old_child
					== end && end->old_parent == start))
			stop[0]++;
		if (room[0] != end && !room[0]->tab[i]->parent &&
				room[0]->tab[i] != start)
		{
				//if (room[0]->tab[i]->parent != room[0])
			room[0]->tab[i]->parent = room[0];
			room[0]->tab[i]->parent->c_parent++;
		}
	}
	room[0]->visit++;
}

void	ft_check_duplicates(t_all **map)
{
	t_room	*tmp;

	tmp = map[0]->room;
	ft_printf("in check %s ", tmp->name);
	while (tmp)
	{
		if (tmp->parent && tmp->old_child && tmp->parent == tmp->old_child)
		{
			//if (ft_strcmp("Mkb6", tmp->name) == 0)
			//ft_printf(YELLOW" I M HERE " END_COLOR);
			ft_printf(GREEN " %s CODE GREEN %s" END_COLOR, tmp->name, tmp->parent->name);
			tmp->parent = tmp->old_parent;
			tmp->parent->c_parent++;
		}
		if (tmp->child && tmp->old_parent && tmp->child == tmp->old_parent)
		{
			ft_printf(RED " %s CODE RED %s " END_COLOR, tmp->name, tmp->child->name);
				//if (tmp->c_child == 0)
				tmp->child = tmp->old_child;
				tmp->child->c_child++;
		}
		tmp = tmp->next;
	}
}

int		ft_solution_len(t_room *room)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = room;
	while (tmp)
	{
		i++;
		tmp = tmp->child;
	}
	return (i);
}

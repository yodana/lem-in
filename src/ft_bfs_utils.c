/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:52:32 by manki             #+#    #+#             */
/*   Updated: 2019/10/09 16:09:55 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		ft_clean_path(t_all **map)
{
	t_room	*tmp;
	t_room	*end;
	t_room	*start;

	end = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_END));
	start = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_START));
	tmp = map[0]->room;
	ft_printf("tmp destroy : ");
	map[0]->way = map[0]->way + 1;
	while (tmp)
	{
		tmp->c_back = 0;
		if ((!ft_end_is_a_child(tmp, end) || !ft_start_is_a_parent(tmp, start)))
		{
			//if (tmp->old_parent)
			tmp->parent = NULL;
			//ft_printf(" %s\n", tmp->name);
			//if (tmp->old_child)
			tmp->child = NULL;
			tmp->way = 0;
		}
		else
		{
			//tmp->old_parent = tmp->parent;
			//tmp->old_child = tmp->child;
			tmp->way = 1;
		}
		//if (ft_strcmp("Mkb6", tmp->name) == 0)
		//	ft_printf("TMP NAME == %s || %d || %d\n", tmp->name, tmp->c_child, tmp->c_parent);
		if (tmp->c_child > 1)
			ft_printf("TMP NAME == %s || %d || %d\n", tmp->name, tmp->c_child, tmp->c_parent);
		tmp->c_child = 0;
		tmp->c_parent = 0;
		tmp = tmp->next;
	}
}

/*static void	ft_forget_this_path(t_room **begin, t_room **start, t_all **map)
{
	t_room		*tmp;
	t_room		*tmp2;

	ft_reset_visit(map);
	tmp = begin[0];
	while (tmp && tmp != start[0] && !tmp->visit)
	{
		tmp2 = tmp->parent;
		tmp->parent = tmp->old_parent;
		tmp->child = tmp->old_child;
		tmp->visit++;
		tmp = tmp2;
	}
}*/

void		ft_forget_this_fcking_path(t_room *tmp, t_room **start, t_all **map)
{
	while (tmp != start[0])
	{
		tmp->parent = NULL;
		tmp->child = NULL;
		tmp = tmp->old_parent;
	}
	(void)map;
}
void		ft_put_child(t_all **map, t_room **end, t_room **start)
{
	t_room	*tmp;
	int		i;
	tmp = end[0];
	while (tmp && tmp->parent && tmp->parent != start[0])
	{
		ft_printf("name == %s\n", tmp->parent->name);
		{tmp->parent->child = tmp;
		tmp->c_child++;}
		tmp = tmp->parent;
	}
	if (tmp->parent == start[0] && tmp == end[0])
		tmp->parent->child = tmp;
	tmp = start[0];
	i = -1;
	//ft_reset_visit(map);
	/*while (tmp)
	{
		if (tmp && tmp->c_child > 1)
			ft_printf(GREEN "FORGET %s\n" END_COLOR, tmp->name);
		if (tmp->c_child > 1 && tmp != start[0])
		{
			ft_printf(GREEN "FORGET " END_COLOR);
			ft_forget_this_fcking_path(tmp, start, map);
		}
		tmp->visit++;
		tmp = tmp->next;
	}*/
	/*while (tmp && tmp->tab && tmp->tab[++i])
	{
		if ((!tmp->tab[i]->child && tmp->tab[i] != end[0]
		&& tmp->tab[i] != start[0]))
		{
			ft_forget_this_path(&tmp->tab[i], start, map);
		}
	}*/
	(void)map;
}

void		ft_copy_in_old(t_all **map)
{
	t_room	*tmp;

	tmp = map[0]->room;
	while (tmp)
	{
		if (tmp->parent)
			tmp->old_parent = tmp->parent;
		if (tmp->child)
			tmp->old_child = tmp->child;
		tmp = tmp->next;
	}
}

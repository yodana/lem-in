/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:26:17 by manki             #+#    #+#             */
/*   Updated: 2019/10/04 14:21:26 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void			free_all(t_all *all)
{
	t_room	*tmp2;
	t_room	*room_ref;

	room_ref = all->room;
	while (room_ref)
	{
		ft_strdel(&(room_ref->name));
		free(room_ref->tab);
		room_ref->tab = NULL;
		tmp2 = room_ref->next;
		free(room_ref);
		room_ref = tmp2;
	}
	ft_strdel(&all->args);
	ft_strdel(&all->command_stack);
	if (all->path_cost)
		free(all->path_cost);
	if (all->ant_nb)
		free(all->ant_nb);
	if (all->old_path_cost)
		free(all->old_path_cost);
	if (all->old_ant_nb)
		free(all->old_ant_nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_breadth_first_search.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:52:25 by manki             #+#    #+#             */
/*   Updated: 2019/10/09 16:21:08 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int				multi_pass(t_room *room, t_room *start)
{
	t_room *tmp;
	int i;

	i = 0;
	tmp = room;
	if (!tmp)
		return (1);
	while (tmp->tab[i] && tmp->tab[i] != start)
	{
		if (i > 1)
			return (1);
		i++;
	}
	return (0);
}
void		ft_one_backtrack(t_room **room, t_queue **list, int i, t_all **map)
{
	t_room		*tmp;
	t_room		*start;
	t_room 		*end;

	end = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_END));
	(void)i;
	(void)map;
	(void)list;
	start = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_START));
		/*tmp = room[0]->tab[i];
	while (!ft_another_path_exist(map[0], tmp->tab))
	{
		tmp = tmp->old_parent;
	}
	ft_printf("tmp dns back == %s", tmp->name);
	ft_enqueue(list, &tmp);*/
	tmp = room[0]->tab[i]->parent;
	//ft_printf("tmp before antoher path == %s\n", tmp->name)
	while (tmp && !ft_another_path_exist(map[0], tmp->tab))
	{
		tmp = tmp->old_parent;
	}
	// /t_room *tmp2 = room[0]->tab[i]->parent;
	//ft_printf("tmp after antoher path == %s\n", tmp->name);
	if (tmp && tmp != start)
	{
		//tmp = room[0]->tab[i]->old_parent;
		ft_enqueue(list, &tmp);
		tmp = room[0]->tab[i]->parent;
		while (tmp && !ft_another_path_exist(map[0], tmp->tab))
		{
			tmp->way = 0;
			tmp = tmp->parent;

		}
		while (tmp->parent != start)
		{
			tmp->child = NULL;
			//tmp->way = 0;
			tmp = tmp->parent;
		}
	room[0]->tab[i]->parent = room[0];
	room[0]->child = room[0]->tab[i];
	tmp = room[0];
	while (tmp && tmp->parent && tmp != start)
	{
		tmp->parent->child = tmp;
		//tmp->visit = 1;
		tmp->way = 1;
		tmp = tmp->parent;
	}
	//ft_printf("%s room at the end\n", tmp->name);
	//print_inside_room(tmp, map);
	while (tmp->child != end)
	{
		tmp->old_parent = tmp->parent;
		tmp->old_child = tmp->child;
		//tmp->visit = 1;
		tmp->way = 1;
		tmp = tmp->child;
	}
	tmp = room[0]->tab[i];
	while (tmp && tmp->child != end)
	{
		//ft_printf("%s room at the end\n", tmp->name);
		tmp->parent = tmp->old_parent;
		tmp->c_back = 1;
		//tmp->way = 1;
		tmp = tmp->old_child;
	}
	//print_inside_room(tmp, map);
	}
	ft_printf("finish");
	/*start = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_START));
	ft_printf(" old parent = %s ",room[0]->tab[i]->old_parent->name);
		room[0]->tab[i]->child = room[0]->tab[i]->old_parent;
		room[0]->tab[i]->child->c_child++;
	if (ft_strcmp("Mkb6", room[0]->tab[i]->name) == 0)
		ft_printf(RED " I M HERE %d"  END_COLOR, room[0]->tab[i]->c_child);
	room[0]->tab[i]->c_back++;
	if (room[0]->tab[i]->child->visit == 0)//&& room[0]->tab[i]->child->child == NULL) //|| ft_strcmp(room[0]->tab[i]->old_parent->name, "Tgr2") != 0)
	{
		ft_printf("je [asse");
			ft_enqueue(list, &room[0]->tab[i]->child);
	}
	room[0]->tab[i]->child->parent = room[0]->tab[i];
	room[0]->tab[i]->c_parent++;
	room[0]->tab[i]->parent = room[0];
	room[0]->c_parent++;
	room[0]->child = room[0]->tab[i];
	room[0]->child->c_child++;
	room[0]->tab[i]->visit++;
	//if (room[0]->tab[i]->child->child != start)
	room[0]->tab[i]->child->child = NULL;
	tmp = room[0]->tab[i]->child->old_parent;
	while (tmp) //&& tmp->old_parent == 0)
	{
			//ft_printf("tmp name in multi pass = %s\n", tmp->name);
		tmp->child = NULL;
		tmp->parent = NULL;
		tmp = tmp->old_parent;
	}*/
		ft_printf("MDR FINISH");
}

int				ft_another_path_exist_2(t_all *map, t_room *room)
{
	t_room *tmp;
	t_room *start;
	int i;

	i = 0;
	start = ft_get_room(&map->room, ft_get_room_pos_by_cmd(map->room,
				CMD_START));
	tmp = room;
	t_room *end;
	end = ft_get_room(&map->room, ft_get_room_pos_by_cmd(map->room,
				CMD_END));
	while (tmp && tmp->parent != start)
	{
		while (tmp->tab[i])
		{
			if (tmp->tab[i]->visit == 0 && tmp->tab[i]->child == NULL && tmp->tab[i] != start && tmp->tab[i]->way == 0 && tmp->tab[i] != end)
				return (1);
			i++;
		}
		i = 0;
		tmp = tmp->parent;
	}
	return (0);
}

static void		ft_bfs_run(t_queue **list, char *stop, t_all **map)
{
	t_queue		*working_node;
	int			i;
	t_room		*start;
	t_room		*end;
	start = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_START));
	end = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_END));
	//ft_printf(" LIST == ");
	//ft_print_queue(*list);
	working_node = ft_dequeue(list);
	if (working_node->room->visit == 0)
	{
		ft_visit_node(&working_node->room, &map[0], stop);
		//ft_printf("working node == %s ", working_node->room->name);
	}
	i = -1;
	while (working_node->room->tab && working_node->room->tab[++i] && stop)
	{
		//ft_printf(" || %s %d || ", working_node->room->tab[i]->name, working_node->room->tab[i]->way);
		if (working_node->room->tab[i]->visit == 0 && working_node->room->tab[i]->child == NULL && working_node->room->tab[i]->way == 0)
		{
	//		if (ft_strcmp("9", working_node->room->name) == 0)
		//		ft_printf(RED "%s" END_COLOR, working_node->room->tab[i]->name);
			ft_enqueue(list, &working_node->room->tab[i]);
		}
		else if (working_node->room->tab[i]->way == 1 &&
				working_node->room->tab[i]->child != NULL && !ft_another_path_exist(map[0], working_node->room->tab)) //&& ft_another_path_exist_2(map[0], working_node->room) == 0)
				 //!ft_another_path_exist(map[0], working_node->room->tab) && working_node->room != start) //&& !(ft_end_is_a_child(working_node->room->tab[i], end) && ft_start_is_a_parent(working_node->room->tab[i], start))) //&& !ft_start_is_a_old_parent(working_node->room->tab[i], start))
		{
			ft_printf("BACKTRACJKUNG ");
			//ft_printf("node in bakctacking == %s || %s\n", working_node->room->tab[i]->name,working_node->room->name);
			
			//working_node->room->tab[i]->visit = 1;
			ft_one_backtrack(&working_node->room, list, i, map);
		}
		//if (working_node->room->tab[i]->c_child > 0)
			//ft_printf("ERROR BUG == %s || %d\n", working_node->room->tab[i]->name, working_node->room->tab[i]->c_child);
	}
	free(working_node);
}

char		ft_bfs_algo(t_all **map, unsigned long long tour)
{
	t_room		*start;
	t_room		*end;
	t_queue		*list;
	char		stop;

	start = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_START));
	end = ft_get_room(&map[0]->room, ft_get_room_pos_by_cmd(map[0]->room,
				CMD_END));
	list = ft_create_queue(&start);
	stop = 0;
	while (!stop && list)
		ft_bfs_run(&list, &stop, map);
	if (!list)
		ft_printf(RED "LIST VIDE " END_COLOR);
	if (stop || !list)
		ft_put_child(map, &end, &start);
	ft_free_queue(&list);
	if (!end->parent && tour == 0)
		return (0);
	if (end->parent == start)
		end->old_parent = end->parent;
	end->parent = NULL;
	return (1);
}

static void		ft_keep_going(int *k_g, t_queue **sol, int *s_cost, t_all *map)
{
	int			cost;
	t_room		*tmp;

	k_g[0] = 0;
	cost = ft_cost_computation(&map, sol);
	ft_print_queue(*sol);
	(void)tmp;
//	display(sol, 5);
	/*if (s_cost[0] == 94)
	{
		ft_print_queue(*sol);
		display(sol, 440);
		exit(0);
	}*/
	if (cost == 89)
		exit(0);
	//k_g[0] = 1;
	//if (cost <= s_cost[0])
	{
		s_cost[0] = cost;
		k_g[0] = 1;
		ft_copy_in_old(&map);
	}
	//else
	{
		//k_g[0] = 0;
	}
	/*else
	{
		tmp = map->room;
		while (tmp)
		{
			tmp->parent = tmp->old_parent;
			tmp->child = tmp->old_child;
			tmp = tmp->next;
		}
		ft_free_queue(sol);
		ft_stock_solution(sol, &map);
		if (map->ant_nb)
			free(map->ant_nb);
		if (map->path_cost)
			free(map->path_cost);
		map->ant_nb = map->old_ant_nb;
		map->path_cost = map->old_path_cost;
		map->old_path_cost = NULL;
		map->old_ant_nb = NULL;
	}*/
}

/*
** ft_breadth_first_search(t_all *map);
** VARIABLES:
**		sol: est un tableau de pointeurs sur room, sol contient la liste de
** toutes les rooms commencant un chemin a suivre par les fourmis
**		sol_cost: nombre total de lignes que prendra la solution trouvee
**		keep_going: variable qui dit si il faut continuer de chercher d'autres
** chemins
**		tour: variable qui compte le nombre de fois ou on a fait appel a
** ft_bfs_algo (necessaire pour savoir si il n'y a aucune solution dans la map)
** FONCTION:
** tant qu'il faut continuer a chercher des chemin on lance ft_bfs_algo() qui
** cherche le premier chemin le plus court apres ceux qu'on a deja trouve.
** ft_reset_visit pour remettre a 0 le compteur de visite de toutes les rooms
** de la map
** ft_check_duplicate: si lors de la recherche du chemin le plus court on a fait
** un backtracking sur un chemin precedemment trouve check_duplicate verifie les
** repetitions de pointeurs et fait les permutation pour avoir des chemins
** distinct
** stock_solution remplit sol avec la solution trouvee
** keep_going evalue la solution trouve en la comparant a la precedente et
** attribue a la variable keep_going 0 ou 1 en fonction de si il faut continuer
** a chercher des chemins ou si notre solution est deja la meilleur.
** RETOUR:
** sol est retourne pour etre utilise dans l'affichage de la solution.
*/

t_queue			*ft_breadth_first_search(t_all *map)
{
	t_queue				*sol;
	int					sol_cost;
	int					keep_going;
	unsigned long long	tour;

	sol = NULL;
	sol_cost = INT_MAX;
	keep_going = 1;
	tour = 0;
	while (keep_going)
	{
		if (!ft_bfs_algo(&map, tour))
			return (NULL);
		ft_reset_visit(&map);
		//ft_check_duplicates(&map);
		ft_clean_path(&map);
		ft_stock_solution(&sol, &map);
		ft_keep_going(&keep_going, &sol, &sol_cost, map);
		if (keep_going)
			ft_free_queue(&sol);
		tour++;
	}
	return (sol);
}

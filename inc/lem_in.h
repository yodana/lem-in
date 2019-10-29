/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:01:13 by manki             #+#    #+#             */
/*   Updated: 2019/10/09 11:46:14 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "limits.h"

# define _GREY "\033[30m"
# define _RED "\033[31m"
# define _GREEN "\033[32m"
# define _YELLOW "\033[33m"
# define _BLUE "\033[34m"
# define _PURPLE "\033[35m"
# define _CYAN "\033[36m"
# define _WHITE "\033[37m"
# define _END "\033[0m"

# define ARGS_NUMBER 3

enum	{ ERROR, NUMBER, COMMAND, ROOM, TUBE, COMMENT };

enum	{ NO_CMD, CMD_START, CMD_END};

int					ft_check_line(char *in);

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_room
{
	char			*name;
	char			command;
	char			visit;
	int				x;
	int				y;
	struct s_room	**tab;
	struct s_room	*next;
	struct s_room	*parent;
	struct s_room	*child;
	int				c_child;
	int				c_parent;
	int				c_back;
	int				way;
	struct s_room	*old_parent;
	struct s_room	*old_child;
}					t_room;

typedef struct		s_all
{
	int				ants;
	char			*args;
	char			*command_stack;
	t_room			*room;
	int				*path_cost;
	int				*ant_nb;
	int				*old_path_cost;
	int				*old_ant_nb;
	int				total_of_lines;
	int				way;

}					t_all;

typedef struct		s_queue
{
	t_room			*room;
	int				nodes;
	int				ants;
	int				c_t;
	struct s_queue	*next;
}					t_queue;

char				ft_stock_room(char *input, t_room **list, char **cmd_stack);
void				free_all(t_all *all);

char				ft_cmp(char str1[], char str2[], char ref1[], char ref2[]);
char				ft_stock_tube(char *input, t_all **map);
char				ft_check_map(char *input, char line_id, t_all *map);
char				ft_map_enough_to_launch(t_all *map);

void				ft_display_all(t_all *map);
void				ft_print_room_ptr(t_room *room);
void				ft_print_queue(t_queue *list);
void				ft_print_solutions(t_queue *list);
void				print_inside_room(t_room *room, t_all **map);
int				numbers_of_ways(t_queue **sol);

t_room				*ft_room_lstnew(char *name, t_coord c, char cmd);
void				ft_room_lstadd(t_room **l, char *name, t_coord c, char cmd);
int					ft_room_lstlen(t_room *list);
t_room				*ft_get_room(t_room **list, int position);
int					ft_get_room_pos_by_cmd(t_room *list, char cmd);
char		ft_bfs_algo(t_all **map, unsigned long long tour);
int					ft_tab_len(t_room *r);
char				ft_add_tube(t_room **list, char *room_a, char *room_b);

t_queue				*ft_create_queue(t_room **room);
void				ft_enqueue(t_queue **list, t_room **room);
t_queue				*ft_dequeue(t_queue **list);
void				ft_free_queue(t_queue **list);
int					ft_queue_len(t_queue *queue);

void				ft_stock_solution(t_queue **sol, t_all **map);
int					ft_another_path_exist(t_all *map, t_room **room);
void				ft_visit_node(t_room **room, t_all **map, char *stop);
void				ft_check_duplicates(t_all **map);
int					ft_solution_len(t_room *room);

void				ft_put_child(t_all **map, t_room **room, t_room **start);
void				ft_copy_in_old(t_all **map);
void				ft_reset_visit(t_all **map);
void				ft_clean_path(t_all **map);

t_queue				*ft_breadth_first_search(t_all *map);

int					ft_cost_computation(t_all **map, t_queue **sol);

void				display(t_queue **sol, int ants);
int					calc_nodes(t_room *room);

int					total_ants(int *ants, int size);

t_queue				*sort_lst(t_queue *display);
int					sort(t_queue *cpy, t_queue *before, t_queue *next
						, t_queue **first);
void				set_next(t_queue **cpy, t_queue **before, t_queue **next);

t_room				*chose_display(t_queue *display, int size);
void				stock_ants_sol(int *ants, t_queue *dis, int c_ants, int s);
void				chose_ants(int *ants, int c_ants, int size, t_queue **disp);
void				stock_room_sol(t_room **tmp, t_queue *display, int c_ants);
int					check_end(t_room **room, int size);

void				ft_check_arg(int ac, char *av[], t_all *all);
void				ft_paths(t_all *map, int sol_nb);
void				ft_sort_queue(t_queue **sol);
void				ft_inside_sol(t_queue *sol);
int					ft_calc_final_cost(int *path_cost, int *ant_nb, int len);

char				ft_end_is_a_child(t_room *room, t_room *end);
char				ft_start_is_a_parent(t_room *room, t_room *start);

char				ft_has_loop(t_room *room);

#endif

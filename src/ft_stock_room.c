/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:56:17 by manki             #+#    #+#             */
/*   Updated: 2019/09/18 14:51:40 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static char		ft_room_already_exist(char **s, t_room *list, char cmd)
{
	t_room	*tmp;
	char	already_exist;

	tmp = list;
	already_exist = 0;
	while (tmp && !already_exist)
	{
		if (!ft_strcmp(tmp->name, s[0]) ||
				(cmd != NO_CMD && tmp->command == cmd) ||
				((ft_atoi(s[1]) == tmp->x) && (ft_atoi(s[2]) == tmp->y)))
			already_exist++;
		tmp = tmp->next;
	}
	return (already_exist);
}

static char		ft_add_room(t_room **list, char **s, char cmd)
{
	t_coord		c;

	if (!ft_room_already_exist(s, *list, cmd))
	{
		c.x = ft_atoi(s[1]);
		c.y = ft_atoi(s[2]);
		if (!list[0])
			list[0] = ft_room_lstnew(s[0], c, cmd);
		else
			ft_room_lstadd(list, s[0], c, cmd);
		return (1);
	}
	else
		return (0);
}

char			ft_stock_room(char *input, t_room **list, char **cmd_stack)
{
	char	**split;
	char	ret;
	char	command;

	ret = 0;
	if (!(split = ft_strsplit(input, ' ')))
		return (0);
	command = NO_CMD;
	if (cmd_stack[0] && !ft_strcmp(cmd_stack[0], "##start"))
		command = CMD_START;
	else if (cmd_stack[0] && !ft_strcmp(cmd_stack[0], "##end"))
		command = CMD_END;
	ret += ft_add_room(list, split, command);
	ft_strdel(cmd_stack);
	ft_strrdel(split);
	return (ret);
}

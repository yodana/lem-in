/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:09:23 by manki             #+#    #+#             */
/*   Updated: 2019/09/26 12:17:21 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void		ft_coord(char *str, int *i, int *ok)
{
	char	nb_len;
	char	*ref;

	if (i[0] > 0 && str[i[0]] == ' ')
	{
		i[0]++;
		ok[0]++;
	}
	nb_len = 0;
	ref = &str[i[0]];
	while (str[i[0]] && str[i[0]] != ' ' && ft_isdigit(str[i[0]]))
	{
		nb_len++;
		i[0]++;
	}
	if (!(nb_len > 0 && nb_len <= 10 && ft_atoll(ref) <= INT_MAX))
		ok[0]--;
}

static int		ft_is_room(char *str)
{
	int		i;
	int		ok;

	i = 0;
	ok = 0;
	while (str[i] && str[i] != ' ' && ft_isprint(str[i]) && str[i] != '-')
		i++;
	ft_coord(str, &i, &ok);
	ft_coord(str, &i, &ok);
	if (str[i] == '\0' && ok == 2)
		return (1);
	else
		return (0);
}

static int		ft_is_tube(char *str)
{
	int		dash;
	int		char_after_dash;
	int		i;

	i = 0;
	dash = 0;
	char_after_dash = 0;
	while (str[i] && dash < 2 && ft_isprint(str[i]) && str[i] != ' ')
	{
		if (str[i] == '-')
			dash++;
		else if (dash)
			char_after_dash++;
		i++;
	}
	if (str[i] == '\0' && dash == 1 && char_after_dash > 0 && str[0] != '-')
		return (1);
	else
		return (0);
}

int				ft_check_line(char *in)
{
	int		len;

	len = ft_strlen(in);
	if (len >= 1 && len <= 10 && ft_str_is_numeric(in) &&
			ft_atoll(in) <= INT_MAX)
		return (NUMBER);
	else if (len >= 2 && in[0] == '#' && in[1] == '#')
		return (COMMAND);
	else if (len >= 1 && in[0] == '#')
		return (COMMENT);
	else if (len >= 1 && in[0] != 'L' && ft_is_room(in))
		return (ROOM);
	else if (len >= 1 && in[0] != 'L' && ft_is_tube(in))
		return (TUBE);
	else
		return (ERROR);
}

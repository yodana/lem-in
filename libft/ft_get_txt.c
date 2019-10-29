/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_txt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:54:26 by yodana            #+#    #+#             */
/*   Updated: 2019/08/27 14:08:13 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_txt(int fd)
{
	char	*line;
	int		res;

	while ((res = get_next_line(fd, &line)) > 0)
		return (line);
	return (NULL);
}
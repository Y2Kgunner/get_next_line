/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:18:59 by ykulkarn          #+#    #+#             */
/*   Updated: 2021/11/24 10:38:29 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*combine(int fd, char *store)
{
	char	*buf;
	int		i;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr(store, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		store = ft_strjoin(store, buf);
	}
	free(buf);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*str[10000];
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = combine(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	l = find_nl(str[fd]);
	str[fd] = after_nl(str[fd]);
	return (l);
}

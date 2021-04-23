/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:24 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/30 22:21:40 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			gnl_check(char **line, char *gnline)
{
	if (!line || !gnline)
		return (-1);
	return (1);
}

static int			gnl_return(char **line, char **gnline)
{
	int				ret;

	ret = 0;
	if (*gnline)
		*line = *gnline;
	else
	{
		*line = malloc(sizeof(char) * 1);
		if (*line == NULL)
			return (-1);
		*line[0] = '\0';
	}
	*gnline = NULL;
	return (ret);
}

int					get_next_line(int fd, char **line)
{
	static char		*gnline;
	char			buffer[BUFFER_SIZE + 1];
	int				n;
	int				flag;

	if ((read(fd, buffer, 0) < 0) || fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		if (!(gnline = gnl_join(gnline, buffer)))
			return (-1);
		flag = gnl_find(gnline);
		if (flag != -1)
			break ;
	}
	flag = gnl_find(gnline);
	if (flag != -1)
	{
		*line = gnl_sub(gnline, 0, flag, 0);
		gnline = gnl_dup(&gnline[flag + 1], gnline);
		return (gnl_check(line, gnline));
	}
	return (gnl_return(line, &gnline));
}

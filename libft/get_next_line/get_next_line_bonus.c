/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:17:24 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/31 01:17:11 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char		*gnline[FDMAX];
	char			buffer[BUFFER_SIZE + 1];
	int				n;
	int				flag;

	if ((read(fd, buffer, 0) < 0) || fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		if (!(gnline[fd] = gnl_join(gnline[fd], buffer)))
			return (-1);
		flag = gnl_find(gnline[fd]);
		if (flag != -1)
			break ;
	}
	flag = gnl_find(gnline[fd]);
	if (flag != -1)
	{
		*line = gnl_sub(gnline[fd], 0, flag, 0);
		gnline[fd] = gnl_dup(&gnline[fd][flag + 1], gnline[fd]);
		return (gnl_check(line, gnline[fd]));
	}
	return (gnl_return(line, &gnline[fd]));
}

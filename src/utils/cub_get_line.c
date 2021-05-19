/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_get_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 04:52:19 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 04:15:49 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	gnl_return(char **line, char **gnline)
{
	int		ret;

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

int	cub_get_line(char **line, int fd)
{
	int			n;
	int			i;
	char		buffer[BUFF_SIZE + 1];
	static char	*temp;

	if (fd < 0 || !line || read(0, buffer, 0) < 0)
		return (-1);
	n = 1;
	while (n > 0)
	{	
		n = read(fd, buffer, BUFF_SIZE);
		buffer[n] = '\0';
		temp = gnl_join(temp, buffer);
		if (gnl_find(temp) != -1)
			break ;
	}
	i = gnl_find(temp);
	if (i != -1)
	{
		*line = gnl_sub(temp, 0, i, 0);
		temp = gnl_dup(&temp[i + 1], temp);
		return (1);
	}
	return (gnl_return(line, &temp));
}

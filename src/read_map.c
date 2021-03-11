/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 02:23:03 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/11 20:45:08 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int			ft_get_line(char **line, int fd)
{
	int				n;
	int				i;
	static char		*temp;
	char			buffer[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(0, buffer, 0) < 0)
		return (-1);
	while ((n = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[n] = '\0';
		temp = gnl_join(temp, buffer);
		if (gnl_find(temp) != -1)
			break;
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
t_settings		ft_settings(char *map)
{
	int			fd;
	char		*line;
	t_settings	*settings;

	settings = NULL;
	settings = malloc(sizeof(t_settings));
	fd = open(map, O_RDONLY);
	while ((ft_get_line(&line, fd) > 0))
	{
		ft_setparams(line, settings);
		free(line);
	}
	free(line);
	printf("res_x = %d\n", settings->res.res_x);
	printf("res_y = %d\n", settings->res.res_y);	
	printf("floor = %d\n" , settings->floor);
	printf("ceiling = %d\n" , settings->ceiling);
	printf("size_y = %d\n" , settings->size_y);
	printf("size_x = %d\n" , settings->size_x);
	free(settings);
	return (*settings);
}

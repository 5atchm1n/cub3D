/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_save_bmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:48:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/19 07:15:13 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void cub_bmp_header(t_mlx mlx, int fd)
{
	int		filesize;
	int		offset;
	int		zero;

	filesize = 14 + 40 + (4 * mlx.res.x * mlx.res.y);
	offset = 54;
	zero = 0;
	write(fd, "BM", 2);
	write(fd, &filesize, 4);
	write(fd, &zero, 2);
	write(fd, &zero, 2);
	write(fd, &offset, 4);
}

static void cub_bmp_infoheader(t_mlx mlx, int fd)
{
	int		headersize;
	int		colorplanes;
	int		zero;

	headersize = 40;
	colorplanes = 1;
	zero = 0;
	write(fd, &headersize, 4);
	write(fd, &mlx.res.x, 4);
	write(fd, &mlx.res.y, 4);
	write(fd, &colorplanes, 2);
	write(fd, &mlx.img.bpp, 2);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
}

static void	cub_bmp_img(t_mlx mlx, int fd)
{
	int		x;
	int		y;

	y = mlx.res.y;
	while (y >= 0)
	{
		x = 0;
		while (x < mlx.res.x)
		{
			write(fd, &mlx.img.add[y * mlx.img.len / 4 + x], 4);
			x++;
		}
		y--;
	}
}

void		cub_save_bmp(t_cub *game)
{
	int		fd;

	fd = open("image.bmp", O_CREAT | O_RDWR | O_TRUNC);
	if (fd <= 0)
		return ;
	cub_bmp_header(game->mlx, fd);
	cub_bmp_infoheader(game->mlx, fd);
	cub_bmp_img(game->mlx, fd);
	system("chmod 777 image.bmp");
}

int			cub_check_save_arg(char *save_arg)
{
	int		len;

	len = ft_strlen(save_arg);
	if (len != 6)
		return (0);
	len = len - 1;
	if (save_arg[len] != 'e')
		return (0);
	if (save_arg[len - 1] != 'v')
		return (0);
	if (save_arg[len - 2] != 'a')
		return (0);
	if (save_arg[len - 3] != 's')
		return (0);
	if (save_arg[len - 4] != '-')
		return (0);
	if (save_arg[len - 5] != '-')
		return (0);
	return (1);
}

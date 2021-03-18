/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:31:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/18 12:31:35 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_img *img, int x, int y ,int color)
{
	char	*dst;

	dst = img->add + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void		put_grid(t_cub *game)
{
	int		k;
	int		l;
	float	offset;

	offset = game->settings.offset * MAP_SIZE;
	l = 0;
	while (l < game->settings.size_y)
	{
		k = 0;
		while(k < game->settings.res.x)
		{
			my_pixel_put(&game->img, k, l * offset, 0x00000000);
			k++;
		}
		l++;
	}
	l = 0;
	while (l < game->settings.size_x)
	{
		k = 0;
		while (k < game->settings.res.y)
		{
			my_pixel_put(&game->img, l * offset, k, 0x00000000);
			k++;
		}
		l++;
	}
}

void		put_wall(t_cub *game, int x, int y, int colour)
{
	int		k;
	int		l;
	float	offset;

	offset = game->settings.offset * MAP_SIZE;
	k = 0;
	while (k < offset)
	{
		l = 0;
		while (l < offset)
		{
			my_pixel_put(&game->img, x * offset + k, y * offset + l, colour);
			l++;
		}
		k++;
	}
}

void	draw_map(t_cub *game)
{

	int i;
	int j;

	i = 0;
	while (i < game->settings.size_y)
	{
		j = 0;
		while (j < game->settings.size_x)
		{
			if (game->map[i][j] == '0')
				put_wall(game, j, i, 0x00000000);
			if (game->map[i][j] == ' ')
				put_wall(game, j, i, 0x000000FF);
			if (game->map[i][j] == '1')
				put_wall(game, j, i, 0x00FF0000);
			if (game->map[i][j] == '2')
				put_wall(game, j, i, 0x0000FF00);
			j++;
		}
		i++;
	}
}

void	my_player(t_img *img, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			my_pixel_put(img, (x * MAP_SIZE) + i, (y * MAP_SIZE) + j, 0x00FFFFFF);
			i++;
		}
		j++;
	}
}

int			ft_can_see(t_cub *game, double x, double y)
{
	int		grid_x;
	int		grid_y;
	float	offset;

	offset = game->settings.offset;
	grid_y = (int)(y / offset);
	grid_x = (int)(x / offset);

	if (grid_x > game->settings.size_x - 1 || grid_x < 0)
		return (0);
	if (grid_y > game->settings.size_y - 1 || grid_y < 0)
		return (0);
//	printf("y = %d\n", grid_y);
//	printf("x = %d\n", grid_x);
//	printf("map = %d\n", game->map[grid_y][grid_x]);
	if (game->map[grid_y][grid_x] != '0')
	{	
//		printf("map = %d\n", game->map[grid_y][grid_x]);
		return (0);
	}
	return (1);
}

void			fov_line(t_cub *game, double theta)
{
	int			l;
	double		x;
	double		y;
	double		x1,y1;

	l = 0;
	y = sin(theta) * l;
	x = cos(theta) * l;

	while(l < 150)
	{
		y = sin(theta) * l;
		x = cos(theta) * l;
		y1 = game->player.pos_y - y + 2;
		x1 = game->player.pos_x + x + 2;
		if (game->player.pos_y - y + 2 > 2  && ft_can_see(game,x1, y1))
			my_pixel_put(&game->img, x1 * MAP_SIZE, y1 * MAP_SIZE, 0x00FFFFFF);
		if (ft_can_see(game, x1, y1) == 0)
			break;
		l--;
	}
//	printf("x = %f\n", x);
//	printf("y = %f\n", y);
//	printf("dir = %.8f\n", game->settings.dir);
}

void			player_fov(t_cub *game)
{
	double		fov;

	fov = game->player.dir + 0.3;
	while(fov > game->player.dir - 0.3)
	{
		fov_line(game, fov);
		fov -= 0.0005;
	}
//	printf("x = %f\n", x);
//	printf("y = %f\n", y);
//	printf("dir = %.8f\n", game->settings.dir);
}

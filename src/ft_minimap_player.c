/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:20:09 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/24 02:44:49 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		y = -cos(theta) * l;
		x = sin(theta) * l;
		y1 = (game->player.pos_y * game->settings.offset) - y;
		x1 = (game->player.pos_x * game->settings.offset) + x;
		if (x1 > 2  && ft_can_see(game,x1, y1))
		{
			if (theta == game->player.dir)
				my_pixel_put(&game->img, x1 * MAP_SIZE, y1 * MAP_SIZE, 0x00FF0000);
			else
				my_pixel_put(&game->img, x1 * MAP_SIZE, y1 * MAP_SIZE, 0x00FFFFFF);
		}
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
/*
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
*/
	fov_line(game, game->player.dir);
}
/*
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
*/
void	my_player(t_img *img, int x, int y)
{
	double	x1;
	double	y1;
	double	angle;

	angle = 0;

	while(angle <= 360)
	{
		x1 = 8 * cos(angle);
		y1 = 8 * sin(angle);
		my_pixel_put(img, (x + x1) * MAP_SIZE, (y + y1) * MAP_SIZE, 0x00FFFFFF);
		angle += 0.1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:20:09 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/30 01:58:37 by sshakya          ###   ########.fr       */
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
	if (game->map[grid_y][grid_x] != '0')
		return (0);
	return (1);
}

void			fov_line(t_cub *game)
{
	int			l;
	double		x1;
	double		y1;

	l = 0;
	while(l < game->settings.res.x)
	{
		x1 = (game->player.vector.x * game->settings.offset) + ((game->player.vector.dx * 0.94604) - (game->player.vector.dy * -0.32404)) * l;
		y1 = (game->player.vector.y * game->settings.offset) + ((game->player.vector.dx * -0.32404) + (game->player.vector.dy * 0.94604)) * l;
		if (x1 > 2  && ft_can_see(game,x1, y1))
			my_pixel_put(&game->img, x1 * MAP_SIZE, y1 * MAP_SIZE, 0x00FFFFFF);
		if (ft_can_see(game, x1, y1) == 0)
			break;
		l++;
	}
}

void			ft_player_fov(t_cub *game)
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
	fov_line(game);
}

void	ft_minimap_player(t_cub *game)
{
	double	x1;
	double	y1;
	double	angle;
	double	x;
	double	y;

	x = game->player.vector.x * game->settings.offset * MAP_SIZE;
	y = game->player.vector.y * game->settings.offset * MAP_SIZE;
	angle = 0;
	while(angle <= 360)
	{
		x1 = 1 * cos(angle);
		y1 = 1 * sin(angle);
		my_pixel_put(&game->img, x + x1, y + y1, 0x00FFFFFF);
		angle += 0.1;
	}
}

void	ft_minimap(t_cub *game)
{
	ft_draw_map(game);
	ft_player_fov(game);
	ft_minimap_player(game);
}

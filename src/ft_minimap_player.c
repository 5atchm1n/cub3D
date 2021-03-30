/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:20:09 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/30 21:04:51 by sshakya          ###   ########.fr       */
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

void			ft_player_fov(t_cub *game)
{
	int			l;
	double		x1;
	double		y1;

	l = 0;
	while(l < 40)
	{
		x1 = (game->player.vector.x * game->settings.offset) +
			((game->player.vector.dx) ) * l;
		y1 = (game->player.vector.y * game->settings.offset) +
			((game->player.vector.dy) ) * l;
		if (x1 > 2  && ft_can_see(game,x1, y1))
			ft_pixelput(&game->img, x1 * MAP_SIZE, y1 * MAP_SIZE, 0x00FFFFFF);
		if (ft_can_see(game, x1, y1) == 0)
			break;
		l++;
	}
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
		ft_pixelput(&game->img, x + x1, y + y1, 0x00FFFFFF);
		angle += 0.1;
	}
}

void	ft_minimap(t_cub *game)
{
	ft_draw_map(game);
	ft_player_fov(game);
	ft_minimap_player(game);
}

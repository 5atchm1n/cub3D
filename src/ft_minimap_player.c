/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:20:09 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/01 05:33:06 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_can_see(t_world *world, double x, double y)
{
	int		grid_x;
	int		grid_y;
	float	offset;

	offset = world->offset;
	grid_y = (int)(y / offset);
	grid_x = (int)(x / offset);
	if (grid_x > world->size_x - 1 || grid_x < 0)
		return (0);
	if (grid_y > world->size_y - 1 || grid_y < 0)
		return (0);
	if (world->map[grid_y][grid_x] != '0')
		return (0);
	return (1);
}

void		ft_player_fov(t_player *player, t_world *world, t_mlx *mlx)
{
	int		l;
	double	x1;
	double	y1;

	l = 0;
	while (l < 40)
	{
		x1 = player->vector.x * world->offset + player->vector.dx * l;
		y1 = player->vector.y * world->offset + player->vector.dy * l;
		if (ft_can_see(world, x1, y1))
			ft_pixelput(&mlx->img, x1 * MAP_SIZE, y1 * MAP_SIZE, 0x00FFFFFF);
		if (ft_can_see(world, x1, y1) == 0)
			break ;
		l++;
	}
}

void		ft_minimap_player(t_player *player, t_world *world, t_mlx *mlx)
{
	double	x1;
	double	y1;
	double	angle;
	double	x;
	double	y;

	x = player->vector.x * world->offset * MAP_SIZE;
	y = player->vector.y * world->offset * MAP_SIZE;
	angle = 0;
	while (angle <= 360)
	{
		x1 = 1 * cos(angle);
		y1 = 1 * sin(angle);
		ft_pixelput(&mlx->img, x + x1, y + y1, 0x00FFFFFF);
		angle += 0.1;
	}
}

void		ft_minimap(t_cub *game)
{
	ft_draw_map(&game->world, &game->mlx);
	ft_player_fov(&game->player, &game->world, &game->mlx);
	ft_minimap_player(&game->player, &game->world, &game->mlx);
}

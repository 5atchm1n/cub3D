/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:47:00 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/16 20:22:47 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_isempty(t_cub *game, int x, int y)
{
	int			grid_x;
	int			grid_y;
	int			offset;

	offset = game->settings.res.x / game->settings.size_x;
	grid_y = (game->player.pos_y + y) / offset;
	grid_x = (game->player.pos_x + x) / offset;

	if (grid_x > game->settings.size_x || grid_x < 0)
		return (0);
	if (grid_y > game->settings.size_y || grid_y < 0)
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


static int		ft_update_fov(t_cub *game)
{
	if (game->player.move.turn_r)
		game->player.dir += TURN_SPEED;
	if (game->player.move.turn_l)
		game->player.dir -= TURN_SPEED;
		return (0);
}

static void		ft_move_up(t_cub *game)
{
	int			x;
	int			y;

	x = game->player.pos_x - (cos(game->player.dir) * MOVE_SPEED);
	y = game->player.pos_y + (sin(game->player.dir) * MOVE_SPEED);

	if (ft_can_see(game, x - 3, y + 3))
	{
		game->player.pos_x = x;
		game->player.pos_y = y;
	}
}

static void		ft_move_down(t_cub *game)
{
	int			x;
	int			y;

	x = game->player.pos_x + (cos(game->player.dir) * MOVE_SPEED);
	y = game->player.pos_y - (sin(game->player.dir) * MOVE_SPEED);

	if (ft_can_see(game, x + 3, y - 3))
	{
		game->player.pos_x = x;
		game->player.pos_y = y;
	}
}

static void		ft_move_right(t_cub *game)
{
	int			x;
	int			y;

	x = game->player.pos_x + (sin(game->player.dir) * MOVE_SPEED);
	y = game->player.pos_y - (cos(game->player.dir) * MOVE_SPEED);

	if (ft_can_see(game, x + 3, y - 3))
	{
		game->player.pos_x = x;
		game->player.pos_y = y;
	}
}

static void		ft_move_left(t_cub *game)
{
	int			x;
	int			y;

	x = game->player.pos_x - (sin(game->player.dir) * MOVE_SPEED);
	y = game->player.pos_y + (cos(game->player.dir) * MOVE_SPEED);

	if (ft_can_see(game, x - 3, y + 3))
	{
		game->player.pos_x = x;
		game->player.pos_y = y;
	}
}

static int		ft_update_pos(t_cub *game, int dir_x, int dir_y)
{
	if (dir_y == 1 && dir_x == 0)
		ft_move_up(game);
	if (dir_y == -1 && dir_x == 0)
		ft_move_down(game);
	if (dir_y == 0 && dir_x == 1)
		ft_move_right(game);
	if (dir_y == 0 && dir_x == -1)
		ft_move_left(game);
	return (0);
}

int		ft_move(t_cub *game)
{
	ft_update_fov(game);
	if (game->player.move.up && ft_isempty(game, 0, -1))
		ft_update_pos(game, 0 , 1);
	if (game->player.move.down && ft_isempty(game, 0, 1))
		ft_update_pos(game, 0, -1);
 	if (game->player.move.left && ft_isempty(game, -1, 0))
		ft_update_pos(game, 1, 0);
	if (game->player.move.right && ft_isempty(game, 1, 0))
		ft_update_pos(game, -1, 0);

	draw_map(game);
	my_player(&game->img, game->player.pos_x, game->player.pos_y);
	player_fov(game);
	mlx_put_image_to_window(game->win.mlx , game->win.win, game->img.img, 0 , 0);

	return (0);
}

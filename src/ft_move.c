/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:47:00 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/29 01:12:29 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_update_fov(t_cub *game)
{
	double		dir;
	double		plane;

	if (game->player.move.turn_r)
	{
		dir = game->camera.dirx;
		game->camera.dirx = game->camera.dirx * cos(-TURN_SPEED) - game->camera.diry * sin(-TURN_SPEED);
		game->camera.diry = dir * sin(-TURN_SPEED) + game->camera.diry * cos(-TURN_SPEED);
		plane = game->camera.planex;
		game->camera.planex = game->camera.planex * cos(-TURN_SPEED) - game->camera.planey * sin(-TURN_SPEED);
		game->camera.planey = plane * sin(-TURN_SPEED) + game->camera.planey * cos(-TURN_SPEED);
		game->player.dir = tan(game->camera.diry / game->camera.dirx);
	}
	if (game->player.move.turn_l)
	{	
		dir = game->camera.dirx;
		game->camera.dirx = game->camera.dirx * cos(TURN_SPEED) - game->camera.diry * sin(TURN_SPEED);
		game->camera.diry = dir * sin(-TURN_SPEED) + game->camera.diry * cos(-TURN_SPEED);
		plane = game->camera.planex;
		game->camera.planex = game->camera.planex * cos(TURN_SPEED) - game->camera.planey * sin(TURN_SPEED);
		game->camera.planey = plane * sin(TURN_SPEED) + game->camera.planey * cos(TURN_SPEED);
		game->player.dir = tan(game->camera.diry / game->camera.dirx);
	}
	return (0);
}

static void		ft_move_up(t_cub *game)
{
	double		x;
	double		y;

	x = game->player.pos_x + game->camera.dirx * MOVE_SPEED;
	y = game->player.pos_y + game->camera.diry * MOVE_SPEED;
	if (game->map[(int)y][(int)x] == '0')
	{
		game->player.pos_x += game->camera.dirx * MOVE_SPEED;
		game->player.pos_y += game->camera.diry * MOVE_SPEED;
	}

}

static void		ft_move_down(t_cub *game)
{
	double		x;
	double		y;

	x = game->player.pos_x - game->camera.dirx * MOVE_SPEED;
	y = game->player.pos_y - game->camera.diry * MOVE_SPEED;
	if (game->map[(int)y][(int)x] == '0')
	{
		game->player.pos_x -= game->camera.dirx * MOVE_SPEED;
		game->player.pos_y -= game->camera.diry * MOVE_SPEED;
	}

}

static void		ft_move_right(t_cub *game)
{
	double		x;
	double		y;
	x = game->player.pos_x - game->camera.dirx * MOVE_SPEED;
	y = game->player.pos_y + game->camera.diry * MOVE_SPEED;
	if (game->map[(int)y][(int)x] == '0')
	{
		game->player.pos_x -= game->camera.dirx * MOVE_SPEED;
		game->player.pos_y += game->camera.diry * MOVE_SPEED;
	}
}

static void		ft_move_left(t_cub *game)
{
	double		x;
	double		y;

	x = game->player.pos_x + game->camera.dirx * MOVE_SPEED;
	y = game->player.pos_y - game->camera.diry * MOVE_SPEED;
	if (game->map[(int)y][(int)x] == '0')
	{
		game->player.pos_x += game->camera.dirx * MOVE_SPEED;
		game->player.pos_y -= game->camera.diry * MOVE_SPEED;
	}
}

void	put_black(t_cub *game)
{
	int x;
	int y;
	x = 0;
	y = 0;
	while (x < game->settings.res.x)
	{
		y = 0;
		while (y < game->settings.res.y)
		{
			my_pixel_put(&game->img, x, y, 0x0000000);
			y++;
		}
		x++;
	}
}
	
int		ft_move(t_cub *game)
{
	if (game->player.move.up)
		ft_move_up(game);
	if (game->player.move.down)
		ft_move_down(game);;
 	if (game->player.move.left)
		ft_move_left(game);
	if (game->player.move.right)
		ft_move_right(game);
	ft_update_fov(game);
	put_black(game);
	ft_drawrays3D(game);
	draw_map(game);
	put_grid(game);
	my_player(&game->img, game->player.pos_x * game->settings.offset, game->player.pos_y * game->settings.offset);
//	player_fov(game);
	mlx_put_image_to_window(game->win.mlx , game->win.win, game->img.img, 0 , 0);

	return (0);
}

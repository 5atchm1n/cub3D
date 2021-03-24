/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:47:00 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/24 02:16:06 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
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
*/

static int		ft_update_fov(t_cub *game)
{
	float		d;
	double		dir;
	double		plane;

	d = game->player.dir;

	if (game->player.move.turn_r)
	{
		dir = game->camera.dirx;
		game->camera.dirx = game->camera.dirx * cos(-TURN_SPEED) - game->camera.diry * sin(-TURN_SPEED);
		game->camera.diry = dir * sin(-TURN_SPEED) + game->camera.diry * cos(-TURN_SPEED);
		plane = game->camera.planex;
		game->camera.planex = game->camera.planex * cos(-TURN_SPEED) - game->camera.planey * sin(-TURN_SPEED);
		game->camera.planey = plane * sin(-TURN_SPEED) + game->camera.planey * cos(-TURN_SPEED);
		game->player.dir = tan(game->camera.dirx / game->camera.diry);
	}
	if (game->player.move.turn_l)
	{	
		game->player.dir = d;
		dir = game->camera.dirx;
		game->camera.dirx = game->camera.dirx * cos(TURN_SPEED) - game->camera.diry * sin(TURN_SPEED);
		game->camera.diry = dir * sin(-TURN_SPEED) + game->camera.diry * cos(-TURN_SPEED);
		plane = game->camera.planex;
		game->camera.planex = game->camera.planex * cos(TURN_SPEED) - game->camera.planey * sin(TURN_SPEED);
		game->camera.planey = plane * sin(TURN_SPEED) + game->camera.planey * cos(TURN_SPEED);
		game->player.dir = tan(game->camera.dirx / game->camera.diry);
	}
	return (0);
}

static void		ft_move_up(t_cub *game)
{
	double		x;
	double		y;
/*
	x = (game->player.pos_x * game->settings.offset) - 
		(cos(game->player.dir) * MOVE_SPEED);
	y = (game->player.pos_y * game->settings.offset) +
		(sin(game->player.dir) * MOVE_SPEED);

//	if (ft_can_see(game, x, y))
//	{
	//	game->player.pos_x = x / game->settings.offset;
	//	game->player.pos_y = y / game->settings.offset;
	}
*/		
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
/*
	x = (game->player.pos_x * game->settings.offset) +
		(cos(game->player.dir) * MOVE_SPEED);
	y = (game->player.pos_y * game->settings.offset) -
		(sin(game->player.dir) * MOVE_SPEED);

//	if (ft_can_see(game, x, y))
//	{		
	//	game->player.pos_x = x / game->settings.offset;
	//	game->player.pos_y = y / game->settings.offset;
//	}
*/
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
	x = game->player.pos_x + game->camera.dirx * MOVE_SPEED;
	y = game->player.pos_y + game->camera.diry * MOVE_SPEED;
	if (game->map[(int)y][(int)x] == '0')
	{
		game->player.pos_x += game->camera.dirx * MOVE_SPEED;
		game->player.pos_y += game->camera.diry * MOVE_SPEED;
	}
/*
	x = (game->player.pos_x * game->settings.offset) +
		(sin(game->player.dir) * MOVE_SPEED);
	y = (game->player.pos_y * game->settings.offset) +
		(cos(game->player.dir) * MOVE_SPEED);

	if (ft_can_see(game, x, y))
	{		
		game->player.pos_x = x / game->settings.offset;
		game->player.pos_y = y / game->settings.offset;
	}
*/
}

static void		ft_move_left(t_cub *game)
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
/*
	x = (game->player.pos_x * game->settings.offset) -
		(sin(game->player.dir) * MOVE_SPEED);
	y = (game->player.pos_y * game->settings.offset) -
		(cos(game->player.dir) * MOVE_SPEED);

	if (ft_can_see(game, x, y))
	{		
		game->player.pos_x = x / game->settings.offset;
		game->player.pos_y = y / game->settings.offset;
	}
*/
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
	ft_update_fov(game);
	if (game->player.move.up)
		ft_update_pos(game, 0 , 1);
	if (game->player.move.down)
		ft_update_pos(game, 0, -1);
 	if (game->player.move.left)
		ft_update_pos(game, 1, 0);
	if (game->player.move.right)
		ft_update_pos(game, -1, 0);

	put_black(game);
	ft_drawrays3D(game);
	draw_map(game);
	put_grid(game);
	my_player(&game->img, game->player.pos_x * game->settings.offset, game->player.pos_y * game->settings.offset);
	player_fov(game);
	mlx_put_image_to_window(game->win.mlx , game->win.win, game->img.img, 0 , 0);

	return (0);
}

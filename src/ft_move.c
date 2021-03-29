/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:47:00 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/29 20:36:26 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_update_fov(t_vector *vector, t_camera *camera, t_move *move)
{
	double		dir;
	double		plane;

	if (move->turn_r)
	{
		dir = vector->dx;
		vector->dx = (vector->dx * cos(-TURN_SPEED)) - (vector->dy * sin(-TURN_SPEED));
		vector->dy = (dir * sin(-TURN_SPEED)) + (vector->dy * cos(-TURN_SPEED));
		plane = camera->planex;
		camera->planex = camera->planex * cos(-TURN_SPEED) - camera->planey * sin(-TURN_SPEED);
		camera->planey = plane * sin(-TURN_SPEED) + camera->planey * cos(-TURN_SPEED);
	}
	if (move->turn_l)
	{	
		dir = vector->dx;
		vector->dx = vector->dx * cos(TURN_SPEED) - vector->dy * sin(TURN_SPEED);
		vector->dy = dir * sin(TURN_SPEED) + vector->dy * cos(TURN_SPEED);
		plane = camera->planex;
		camera->planex = camera->planex * cos(TURN_SPEED) - camera->planey * sin(TURN_SPEED);
		camera->planey = plane * sin(TURN_SPEED) + camera->planey * cos(TURN_SPEED);
	}
	return (0);
}

static void		ft_move_up(t_vector *vector, char **map)
{
	double		x;
	double		y;

	x = vector->x + vector->dx * MOVE_SPEED;
	y = vector->y + vector->dy * MOVE_SPEED;
	if (map[(int)y][(int)x] == '0')
	{
		vector->x += vector->dx * MOVE_SPEED;
		vector->y += vector->dy * MOVE_SPEED;
	}

}

static void		ft_move_down(t_vector *vector, char **map)
{
	double		x;
	double		y;

	x = vector->x - vector->dx * MOVE_SPEED;
	y = vector->y - vector->dy * MOVE_SPEED;
	if (map[(int)y][(int)x] == '0')
	{
		vector->x -= vector->dx * MOVE_SPEED;
		vector->y -= vector->dy * MOVE_SPEED;
	}

}

static void		ft_move_right(t_vector *vector, char **map)
{
	double		x;
	double		y;
	x = vector->x + (vector->dy * MOVE_SPEED);
	y = vector->y - (vector->dx * MOVE_SPEED);
	if (map[(int)y][(int)x] == '0')
	{
		vector->x += vector->dy * MOVE_SPEED;
		vector->y -= vector->dx * MOVE_SPEED;
	}
}

static void		ft_move_left(t_vector *vector, char **map)
{
	double		x;
	double		y;

	x = vector->x - vector->dy * MOVE_SPEED;
	y = vector->y + vector->dx * MOVE_SPEED;
	if (map[(int)y][(int)x] == '0')
	{
		vector->x -= vector->dy * MOVE_SPEED;
		vector->y += vector->dx * MOVE_SPEED;
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
	ft_update_fov(&game->player.vector, &game->player.camera, &game->player.move);
	if (game->player.move.up)
		ft_move_up(&game->player.vector, game->map);
	if (game->player.move.down)
		ft_move_down(&game->player.vector, game->map);
 	if (game->player.move.left)
		ft_move_left(&game->player.vector, game->map);
	if (game->player.move.right)
		ft_move_right(&game->player.vector, game->map);
	put_black(game);
//	ft_drawrays3D(game);
	ft_raycasting(game);
	draw_map(game);
	put_grid(game);
	my_player(&game->img, game->player.vector.x * game->settings.offset, game->player.vector.y * game->settings.offset);
	player_fov(game);
	mlx_put_image_to_window(game->win.mlx , game->win.win, game->img.img, 0 , 0);
/*
	printf("dirx = %.10f\n", vector->dx);
		printf("diry = %.10f\n", vector->dy);
		printf("plx = %.10f\n", camera->planex);
		printf("plx = %.10f\n", camera->planey);
		printf("\n");
*/
	return (0);
}

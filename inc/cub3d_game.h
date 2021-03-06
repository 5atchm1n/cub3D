/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:04:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 04:05:40 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_H
# define CUB3D_GAME_H

# define MOVE_SPEED 9.0
# define TURN_SPEED 7.0
# define LEVEL 7.0

/*
** MLX -- WIN, IMG, RES, MOUSE, BUFFER, SPEED --
*/

typedef struct s_time
{
	clock_t	cycle;
	int		step;
}	t_time;

typedef struct s_mlx
{
	t_win	win;
	t_img	img;
	t_grid	res;
	t_grid	mouse;
	t_time	time;
	int		**buffer;
	int		on;
}	t_mlx;

/*
** PLAYER -- MOVE, VECTOR, CAMERA --
*/

typedef struct s_player
{
	t_vector		vector;
	t_camera		camera;
	t_speed			speed;
	uint_fast16_t	move;
	int				health;
}	t_player;

/*
** WORLD -- SPRITES, OBJECTS, MAP, INFO --
*/

typedef struct s_world
{
	t_objects	objs;
	t_info		info;
	t_sprite	*sprite;
	char		**map;
}	t_world;

/*
**  -- GLOBAL --
*/

typedef struct s_cub
{
	t_player	player;
	t_mlx		mlx;
	t_world		world;
}	t_cub;

#endif

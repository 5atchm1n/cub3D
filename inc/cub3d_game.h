/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:04:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/29 13:09:15 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_H
# define CUB3D_GAME_H

# define PLAYER_SIZE 0.1
# define MAP_SIZE 0.15
# define MOVE_SPEED 9.0
# define TURN_SPEED 7.0
# define LEVEL 7.0

/*
** MLX -- WIN, IMG, RES
*/
typedef struct		s_mlx
{
	t_win			win;
	t_img			img;
	t_res			res;
	int				**buffer;
	int				on;
	t_mouse			mouse;
	clock_t			time;
	double			move_speed;
	double			turn_speed;
	double			skyx;
}					t_mlx;
/*
** PLAYER -- MOVE, VECTOR, CAMERA --
*/
typedef struct		s_player
{
	t_vector		vector;
	t_camera		camera;
	uint_fast16_t	move;
	int				health;
}					t_player;
/*
** WORLD -- SPRITE, PARAMS, PATHS
**			TEXTURE, BUFFERS
*/
typedef struct		s_world
{
	t_sprite		*sprite;
	t_map_size		msize;
	t_color			floor;
	t_color			ceiling;
	double			*zbuffer;
	float			offset;
	int				scount;
	int				**tex;
	int				**obj;
	char			**map;
	char			**tpath;
	char			**objpath;
	int				*sky;
	int				*skybox;
	int				*ground;
}					t_world;
/*
** GLOBAL STRUCT
*/
typedef struct		s_cub
{
	t_player		player;
	t_mlx			mlx;
	t_world			world;
}					t_cub;

#endif

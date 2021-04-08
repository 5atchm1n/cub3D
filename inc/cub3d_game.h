/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:04:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 16:18:38 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_H
# define CUB3D_GAME_H

# define PLAYER_SIZE 0.2
# define MAP_SIZE 0.2
# define MOVE_SPEED 0.02
# define TURN_SPEED 0.01
# define ERRORS 11

/*
** ERROR HANDLING
*/
typedef enum		e_errn
{
	NO_ERR = 0,
	INV_CHAR = 1,
	O_MAP = 2,
	IS_PATH = 3,
	INV_FILE = 4,
	SPACE_EOL = 5,
	INV_EXT = 6,
	MAP_NOEND = 7,
	MI_FILES = 8,
	MI_RES = 9,
	MI_FLO = 10,
	MI_CEI = 11
}					t_errn;

typedef struct		s_error
{
	t_errn			id;
	t_grid			coords;
	int				texture;
	int				res;
	int				floor;
	int				ceiling;
	int				map;
}					t_error;
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
}					t_mlx;
/*
** PLAYER -- MOVE, VECTOR, CAMERA --
*/
typedef struct		s_player
{
	t_move			move;
	t_vector		vector;
	t_camera		camera;
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

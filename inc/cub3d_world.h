/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:04:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 04:46:28 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_WORLD_H
# define CUB3D_WORLD_H

# define PLAYER_SIZE 0.2
# define MAP_SIZE 0.2
# define MOVE_SPEED 0.02
# define TURN_SPEED 0.01

/*
** MLX -- WINDOW, IMAGE, BUFFER --
*/
typedef struct		s_win
{
	void			*mlx;
	void			*win;
}					t_win;

typedef struct		s_img
{
	void			*img;
	int				*add;
	int				bpp;
	int				len;
	int				endian;
	int				x;
	int				y;
}					t_img;

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

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
typedef struct		s_move
{
	int				left;
	int				right;
	int				up;
	int				down;
	int				turn_l;
	int				turn_r;
}					t_move;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			dx;
	double			dy;
}					t_vector;

typedef struct		s_camera
{
	double			px;
	double			py;
}					t_camera;

typedef struct		s_player
{
	t_move			move;
	t_vector		vector;
	t_camera		camera;
}					t_player;
/*
** WORLD -- MAP, TEXTURES, FLOOR, CEILING --
*/
typedef struct		s_sprite
{
	double			x;
	double			y;
	double			vmove;
	int				id;
	int				udiv;
	int				vdiv;
}					t_sprite;

typedef struct		s_map_size
{
	int				x;
	int				y;
}					t_map_size;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef union		u_color
{
	int				color;
	t_rgb			rgb;
}					t_color;

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

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:04:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/07 00:26:46 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_WORLD_H
# define CUB3D_WORLD_H

# define PLAYER_SIZE 0.2
# define MAP_SIZE 0.2
# define MOVE_SPEED 0.02
# define TURN_SPEED 0.01

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
typedef struct		s_sort
{
	int				order;
	double			dist;
}					t_sort;

typedef struct		s_objs
{
	int				*order;
	double			*dist;
	int				count;
	double			tx;
	double			ty;
	int				spritew;
	int				spriteh;
	int				index;
	int				hitx;
	int				voffset;
	int				startx;
	int				starty;
	int				endx;
	int				endy;
}					t_objs;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			vmove;
	int				id;
	int				udiv;
	int				vdiv;
}					t_sprite;

typedef struct		s_world
{
	t_sprite		*sprite;
	float			offset;
	int				floor;
	int				ceiling;
	int				size_x;
	int				size_y;
	char			**map;
	int				**tex;
	int				**obj;
	double			*zbuffer;
	int				scount;
	char			**tpath;
	char			**objpath;
}					t_world;

#endif

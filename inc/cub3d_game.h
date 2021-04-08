/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:54:53 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 00:42:43 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_H
# define CUB3D_GAME_H

# include "mlx.h"

# define BUFF_SIZE 256
# define TEXTURES 4
# define SPRITES 2
# define SPRITE_H 64
# define SPRITE_W 64
# define TEX_X 64
# define TEX_Y 64

/*
** RAYCASTING, TEXTURE CASTING, GRID
*/

typedef struct		s_grid
{
	int				x;
	int				y;
}					t_grid;

typedef enum		e_dir
{
	NO = 0,
	SO = 1,
	EA = 2,
	WE = 3
}					t_dir;

typedef struct		s_ray
{
	double			dirx;
	double			diry;
	double			deltax;
	double			deltay;
	double			distx;
	double			disty;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				side;
	double			dw;
}					t_ray;

typedef struct		s_texture
{
	t_dir			dir;
	int				lineheight;
	int				start;
	int				end;
	double			pos;
}					t_texture;

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

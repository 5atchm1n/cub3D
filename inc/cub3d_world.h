/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:54:53 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 05:27:48 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_WORLD_H
# define CUB3D_WORLD_H

# define BUFF_SIZE 256
# define TEXTURES 4
# define SPRITES 2
# define SPRITE_H 64
# define SPRITE_W 64
# define TEX_X 64
# define TEX_Y 64

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
** SUB STRUCTURE - WORLD
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
/*
** SUB STRUCTURE - PLAYER
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

#endif

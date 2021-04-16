/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:54:53 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/16 14:18:15 by sshakya          ###   ########.fr       */
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
# define ERRORS 17

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

typedef struct		s_mouse
{
	int				x;
	int				y;
}					t_mouse;

/*
** FLOOR , CEILIING CASTING
*/
typedef struct		s_fray
{
	float			dirx;
	float			diry;
}					t_fray;

typedef struct		s_floor
{
	int				horizon;
	float			camv;
	float			rdist;
	float			stepx;
	float			stepy;
	float			flx;
	float			fly;
	int				tx;
	int				ty;
	int				isfloor;
}					t_floor;
/*
** RAYCASTING, TEXTURE CASTING
*/
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

typedef enum		e_dir
{
	NO = 0,
	SO = 1,
	EA = 2,
	WE = 3
}					t_dir;

typedef struct		s_texture
{
	t_dir			dir;
	int				lineheight;
	int				start;
	int				end;
	double			pos;
}					t_texture;
/*
** OBJECTS CASTING - SORT ORDER , OBJS CASTING
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
/*
** WORLD -- SPRITE , COLOR[RGB], MAP SIZE
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
** PLAYER -- MOVE , VECTOR, CAMERA PLANE
*/

typedef struct		s_vector
{
	double			x;
	double			y;
	double			dx;
	double			dy;
	double			pitch;
	double			posz;
}					t_vector;

typedef struct		s_camera
{
	double			px;
	double			py;
}					t_camera;
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
	MI_CEI = 11,
	INV_SIZE = 12,
	MEM_FAIL = 13,
	MLX_ERR1 = 14,
	MLX_ERR2 = 15,
	INV_RGB = 16,
	MUL_ST = 17,
}					t_errn;

typedef struct		s_grid
{
	int				x;
	int				y;
}					t_grid;

typedef struct		s_error
{
	t_errn			id;
	t_grid			coords;
	int				texture;
	int				res;
	int				floor;
	int				ceiling;
	int				map;
	int				dir;
}					t_error;

typedef struct		s_pixel
{
	int				x;
	int				y;
	int				tex_x;
	int				tex_y;
}					t_pixel;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:11:19 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/05 04:53:41 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 256
# define MOVE_SPEED 0.02
# define TURN_SPEED 0.01
# define MAP_SIZE 0.2
# define TEXTURES 5
# define SPRITES 2
# define SPRITE_H 64
# define SPRITE_W 64
# define TEX_X 64
# define TEX_Y 64
# define PLAYER_SIZE 0.1
/*
** RAYCASTING, TEXTURE CASTING, GRID
*/

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

typedef struct		s_grid
{
	int				x;
	int				y;
}					t_grid;

typedef struct		s_texture
{
	t_dir			dir;
	int				lineheight;
	int				start;
	int				end;
	double			pos;
}					t_texture;
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
	int				id;
	int				udiv;
	int				vdiv;
	double			vmove;
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
/*
** PARSE MAP AND INITILIASE SETTINGS
*/
int					ft_settings(char *map, t_world *world, t_mlx *mlx);
int					ft_get_line(char **line, int fd);
char				**ft_parse_map(char *map, t_world *world);
/*
** CUSTOM PIXEL PUT FOR PERFORMANCE - MLX
*/
void				ft_pixelput(t_img *img, int x, int y, int color);
void				ft_vertline(int x, int start, int end, int color, t_img *img);
void				ft_draw(t_mlx *mlx);
/*
** INITIALIZE PLAYER AND GAME
*/
void				ft_init(t_cub *game, char *map);
void				ft_player_pos(t_player *player, t_world *world);
void				ft_load_textures(t_mlx *mlx, t_world *world);
void				ft_load_objects(t_world *world);
void				ft_set_texture(t_cub *game, t_texture *t, t_ray *ray, int x);
void				ft_init_object_pos(t_world *world);
void				ft_init_object(t_world *world);
int					ft_quit(t_cub *game);
int					ft_nobject(t_world *world);
void				ft_sort_sprites(t_objs *objs);
/*
** MOVE PLAYER AND ROTATE PLAYER
*/
int					ft_keypress(int keycode, t_cub *game);
int					ft_keyrelease(int keycode, t_cub *game);
int					ft_move(t_cub *game);
void				ft_raycasting(t_cub *game);
void				ft_cast_sprites(t_cub *game);
/*
** MINIMAP
*/
void				ft_draw_map(t_world *world, t_mlx *mlx);
void				ft_minimap(t_cub *game);
/*
** UTILS FUNCTION ADD TO LIBFT
*/
int					ft_isspace(char c);

#endif

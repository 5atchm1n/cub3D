/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:11:19 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/30 01:45:28 by sshakya          ###   ########.fr       */
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
# define MOVE_SPEED 0.05
# define TURN_SPEED 0.02
# define MAP_SIZE 0.3

typedef struct		s_win
{
	void			*mlx;
	void			*win;
}					t_win;

typedef struct		s_img
{
	void			*img;
	char			*add;
	int				bpp;
	int				len;
	int				endian;
}					t_img;

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_settings
{
	t_res			res;
	int				floor;
	int				ceiling;
	int				size_x;
	int				size_y;
	float			offset;
}					t_settings;

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
	double			planex;
	double			planey;
}					t_camera;

typedef struct		s_player
{
	t_move			move;
	t_vector		vector;
	t_camera		camera;
}					t_player;

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
}					t_ray;

typedef struct		s_cub
{
	t_settings		settings;
	t_img			img;
	t_player		player;
	t_win			win;
	char			**map;
}					t_cub;

/*
** PARSE MAP AND INITILIASE SETTINGS
*/
int					ft_setparams(char *line, t_settings *settings);
int					ft_settings(char *map, t_settings *settings);
int					ft_get_line(char **line, int fd);
char				**ft_parse_map(char *map, t_cub *game);
/*
** CUSTOM PIXEL PUT FOR PERFORMANCE - MLX
*/
void				my_pixel_put(t_img *img, int x, int y, int color);
/*
** INITIALIZE PLAYER AND GAME
*/
void				ft_init(t_cub *game);
/*
** MOVE PLAYER AND ROTATE PLAYER
*/
int					ft_keypress(int keycode, t_cub *game);
int					ft_keyrelease(int keycode, t_cub *game);
/*
** DISPLAY
*/
int					ft_move(t_cub *game);
/*
** TEST FUNCTIONS -> MINIMAP
*/
//void				put_grid(t_cub *game);
//void				my_player(t_img *img, int x, int y);
void				ft_draw_map(t_cub *game);
void				ft_drawrays3D(t_cub *game);
void				ft_raycasting(t_cub *game);
void				ft_minimap(t_cub *game);
//void				player_fov(t_cub *game);
//void				put_wall(t_cub *game, int x, int y, int colour);
//int					ft_can_see(t_cub *game, double x, double y);
/*
** UTILS FUNCTION ADD TO LIBFT
*/
int					ft_isspace(char c);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:11:19 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/19 06:51:41 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include "mlx.h"
# include "../libft/inc/libft.h"

# include "cub3d_keys.h"
# include "cub3d_world.h"
# include "cub3d_game.h"

# ifndef BONUS
#  define BONUS 0
# endif

/*
** CUSTOM PIXEL PUT FOR PERFORMANCE - MLX
*/
void	cub_draw(t_mlx *mlx);
/*
** SETTINGS
*/
int		cub_settings(char *map_path, t_cub *game);
void	cub_import_settings(char *map_path, t_cub *game, t_error *error);
/*
** INITIALIZE GAME
*/
void	cub_init(t_cub *game, char *map);
void	cub_init_mlx(t_mlx *mlx, t_error *error);
void	cub_init_player(t_player *player, t_world *world, t_error *error);
void	cub_load_textures(t_mlx *mlx, t_world *world);
void	cub_load_objects(t_world *world);
void	cub_init_object_pos(t_world *world);
void	cub_init_object(t_world *world, t_error *error);
void	cub_init_world(t_world *world, t_mlx mlx, char *map_path, t_error
		*error);
void	cub_load_xpm(t_mlx *mlx, int *tex, char *path, t_img *img);
/*
** MOVE PLAYER
*/
int		cub_keypress(int keycode, t_cub *game);
int		cub_keyrelease(int keycode, t_cub *game);
int		cub_move(t_cub *game);
void	cub_look_left_right(t_vector *v, t_camera *cam, uint_fast8_t move);
void	cub_look_up_down(t_vector *v, t_mlx mlx, uint_fast8_t move);
void	cub_player_offset(t_vector *v, double *offset);
/*
** RAYCASTING - SPRITES, TEXTURES
*/
void	cub_raycasting(t_cub *game);
void	cub_set_texture(t_cub *game, t_texture *t, t_ray *ray, int x);
int		cub_nobject(t_world *world);
void	cub_cast_sprites(t_cub *game);
void	cub_sort_sprites(t_objs *objs, int count);
void	cub_render(t_cub *game);
void	cub_set_buffer_pixel(t_mlx *mlx, t_world world, t_objs objs,
		t_pixel *px);
/*
** MINIMAP
*/
void	cub_draw_map(t_world *world, t_mlx *mlx);
void	cub_minimap(t_cub *game);
/*
** ERROR ,CHECKS AND EXIT
*/
void	cub_test_xpm(t_cub *game, t_error *error);
void	cub_check(t_world *world, t_cub *game);
void	cub_check_files(t_world *world, t_error *error);
int		cub_quit(t_cub *game);
void	cub_error(t_error error, t_cub *game, int state);
void	cub_free_world(t_world *world);
void	cub_error_set(t_error *error, t_errn id);
int		cub_check_save_arg(char *save_arg);
int		cub_check_map_arg(char *map);
/*
** UTILS FUNCTION
*/
int		cub_get_line(char **line, int fd);
char	**cub_copy_map(char *map_path, t_world *world);
int		cub_set_rgb(char *line, t_color *color);
int		cub_set_res(char *line, t_res *res);
void	cub_set_texture_paths(char *line, t_world *world, int *i);
int		cub_rgb_to_int(t_color color);
int		cub_isdir(char c);
void	cub_save_bmp(t_cub *game);
/*
** ADD TO LIBFT
*/
int		ft_isspace(char c);
int		ft_strcmp(char *s1, char *s2);
double	ft_fmax(double a, double b);
double	ft_fmin(double a, double b);
/*
** BONUS - FLOOR CASTING
*/
void	cub_floor_casting(t_player *player, t_world *world, t_mlx *mlx);
int		cub_mouse(int x, int y, t_cub *game);
int		cub_set_shadow(int colour, double dist);
/*
** TEST - PRINT INFO
*/
void	cub_print_info(t_cub *game);
int		key_hook(int keycode, t_win *win);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:11:19 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/09 08:10:21 by sshakya          ###   ########.fr       */
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

# include "cub3d_world.h"
# include "cub3d_game.h"

/*
** CUSTOM PIXEL PUT FOR PERFORMANCE - MLX
*/
void	ft_draw(t_mlx *mlx);
/*
** SETTINGS
*/
int		ft_settings(char *map_path, t_cub *game);
void	ft_import_settings(char *map_path, t_cub *game, t_error *error);
/*
** INITIALIZE GAME
*/
void	ft_init(t_cub *game, char *map);
void	ft_init_player(t_player *player, t_world *world);
void	ft_load_textures(t_mlx *mlx, t_world *world);
void	ft_load_objects(t_world *world);
void	ft_init_object_pos(t_world *world);
void	ft_init_object(t_world *world);
void	ft_init_world(t_world *world, t_mlx mlx, char *map_path);
void	ft_load_xpm(t_mlx *mlx, int *tex, char *path, t_img *img);
/*
** MOVE PLAYER
*/
int		ft_keypress(int keycode, t_cub *game);
int		ft_keyrelease(int keycode, t_cub *game);
int		ft_move(t_cub *game);
/*
** RAYCASTING - SPRITES, TEXTURES
*/
void	ft_raycasting(t_cub *game);
void	ft_set_texture(t_cub *game, t_texture *t, t_ray *ray, int x);
int		ft_nobject(t_world *world);
void	ft_cast_sprites(t_cub *game);
void	ft_sort_sprites(t_objs *objs, int count);
/*
** MINIMAP
*/
void	ft_draw_map(t_world *world, t_mlx *mlx);
void	ft_minimap(t_cub *game);
/*
** ERROR AND EXIT
*/
void	ft_check(t_world *world, t_cub *game);
void	ft_check_files(t_world *world, t_error *error);
int		ft_quit(t_cub *game);
void	ft_error(t_error error, t_cub *game, int state);
void	ft_free_world(t_world *world);
/*
** UTILS FUNCTION
*/
int		ft_get_line(char **line, int fd);
char	**ft_copy_map(char *map_path, t_world *world);
int		ft_set_rgb(char *line, t_color *color);
int		ft_set_res(char *line, t_res *res);
void	ft_set_texture_paths(char *line, t_world *world, int *i);
int		ft_rgb_to_int(t_color color);
/*
** ADD TO LIBFT
*/
int		ft_isspace(char c);
int		ft_strcmp(char *s1, char *s2);
double	ft_max(double a, double b);
double	ft_min(double a, double b);
/*
** BONUS - FLOOR CASTING
*/
void	ft_floor_casting(t_player *player, t_world *world, t_mlx *mlx);
#endif

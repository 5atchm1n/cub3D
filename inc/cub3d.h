/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:11:19 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/07 00:25:17 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# include "../libft/inc/libft.h"
# include "cub3d_world.h"
# include "cub3d_game.h"

/*
** PARSE MAP AND INITILIASE SETTINGS
*/
int		ft_settings(char *map, t_world *world, t_mlx *mlx);
int		ft_get_line(char **line, int fd);
char	**ft_parse_map(char *map, t_world *world);
/*
** CUSTOM PIXEL PUT FOR PERFORMANCE - MLX
*/
void	ft_pixelput(t_img *img, int x, int y, int color);
void	ft_vertline(int x, int start, int end, int color, t_img *img);
void	ft_draw(t_mlx *mlx);
/*
** INITIALIZE PLAYER AND GAME
*/
void	ft_init(t_cub *game, char *map);
void	ft_player_pos(t_player *player, t_world *world);
void	ft_load_textures(t_mlx *mlx, t_world *world);
void	ft_load_objects(t_world *world);
void	ft_set_texture(t_cub *game, t_texture *t, t_ray *ray, int x);
void	ft_init_object_pos(t_world *world);
void	ft_init_object(t_world *world);
int		ft_quit(t_cub *game);
int		ft_nobject(t_world *world);
void	ft_sort_sprites(t_objs *objs, int count);
int		ft_set_res(char *line, t_res *res);
int		ft_set_colour(char *line, int *color);
/*
** MOVE PLAYER AND ROTATE PLAYER
*/
int		ft_keypress(int keycode, t_cub *game);
int		ft_keyrelease(int keycode, t_cub *game);
int		ft_move(t_cub *game);
void	ft_raycasting(t_cub *game);
void	ft_cast_sprites(t_cub *game);
/*
** MINIMAP
*/
void	ft_draw_map(t_world *world, t_mlx *mlx);
void	ft_minimap(t_cub *game);
/*
** UTILS FUNCTION ADD TO LIBFT
*/
int		ft_isspace(char c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:11:19 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/17 19:45:13 by sshakya          ###   ########.fr       */
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
# include <time.h>
# include "mlx_linux/mlx.h"
# include "libft/inc/libft.h"

# include "cub3d_keys.h"
# include "cub3d_world.h"
# include "cub3d_game.h"

# ifndef BONUS
#  define BONUS 0
# endif

# ifndef TEST
#  define TEST 0
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
void	cub_init_structs(t_cub *game);
void	cub_init_player(t_player *player, t_world *world, t_error *error);
void	cub_load_textures(t_mlx *mlx, t_world *world);
void	cub_load_objects(t_world *world);
void	cub_init_object_pos(t_world *world);
void	cub_init_object(t_world *world, t_error *error);
void	cub_init_world(t_world *world, t_mlx mlx, char *map_path, t_error
		*error);
void	cub_load_xpm(t_mlx *mlx, int *tex, char *path, t_img *img);
void	cub_start_mlx(t_mlx *mlx);
/*
** MOVE PLAYER
*/
int		cub_move(t_cub *game);
void	cub_look_left_right(t_vector *v, t_camera *cam, uint_fast16_t move,
		t_speed speed);
void	cub_look_up_down(t_vector *v, t_mlx mlx, uint_fast16_t move,
		t_speed speed);
void	cub_jump_crouch(t_vector *vector, uint_fast16_t move, t_speed speed);
void	cub_player_offset(t_vector *v, double *offset);
void	cub_mlx_hooks(t_cub *game);
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
** ERROR ,CHECKS AND EXIT
*/
void	cub_test_xpm(t_cub *game, t_error *error);
void	cub_check(t_world *world, t_cub *game);
void	cub_check_files(t_world *world, t_error *error);
int		cub_quit(t_cub *game);
int		cub_error(t_error error, t_cub *game);
void	cub_free_world(t_world *world);
void	cub_error_set(t_error *error, t_errn id);
int		cub_check_save_arg(char *save_arg);
int		cub_check_map_arg(char *map);
void	cub_error_msg(t_errn id, t_error error);
/*
** UTILS FUNCTION
*/
int		cub_get_line(char **line, int fd);
char	**cub_copy_map(char *map_path, t_world *world);
int		cub_set_rgb(char *line, t_color *color, t_error *error);
int		cub_set_res(char *line, t_grid *res, t_error *error);
void	cub_sprite_path(char *line, t_objects *objs, int *i);
void	cub_texture_path(char *line, t_objects *objs, t_error *error);
int		cub_rgb_to_int(t_color color);
int		cub_isdir(char c);
int		cub_istex(char c);
int		cub_issprite(char c);
void	cub_save_bmp(t_cub *game);
char	*cub_set_path(char *line, char *dir);
void	cub_sanity_check(t_error *error);

/*
** BONUS - FLOOR, SKYBOX, MULTIPLE SPRITES, MOUSE, KILL, DAMAGE, JUMP, CROUCH
*/
void	cub_floor_casting(t_player *player, t_world *world, t_mlx *mlx);
void	cub_mouse_hook(t_cub *game);
void	cub_mouse_move(int x, int y, t_player *player, t_mlx mlx);
void	cub_mouse_stop(t_player *player);
int		cub_set_shadow(int colour, double dist);
void	cub_sprite_move(t_world *world, t_player *player);
void	cub_speed(t_cub *game);
void	cub_hud(t_cub *game);
void	cub_hud_player(t_player *player, t_world *world, t_mlx *mlx);
void	cub_draw_health(t_mlx *mlx, int health);
void	cub_init_bonus(t_world *world, t_mlx *mlx, t_error *error);
void	cub_kill(t_sprite *sprite, uint_fast16_t move);
void	cub_collision(t_sprite *sprite, int count, t_player *player);
int		cub_isbonus(char c1, char c2);
void	cub_bonus_textures(char *line, t_cub *game, t_error *error);
void	cub_quit_bonus(t_cub *game);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:31:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/19 20:53:13 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_img *img, int x, int y ,int color)
{
	char	*dst;

	dst = img->add + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

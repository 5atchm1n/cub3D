/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:31:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/30 21:30:17 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_vertline(int x, int drawstart, int drawend, int color,
		t_img *img)
{
	int		start;

	start = drawstart;
	while (start < drawend)
	{
		ft_pixelput(img, x, start, color);
		start++;
	}
}

void		ft_pixelput(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->add + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

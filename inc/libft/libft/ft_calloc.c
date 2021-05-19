/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:59:20 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 04:27:15 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ret;

	ret = malloc(num * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, (num * size));
	return ((void *)ret);
}

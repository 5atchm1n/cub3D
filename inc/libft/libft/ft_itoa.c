/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 00:16:17 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/03 16:58:03 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_power_ten(int i)
{
	int				len;
	unsigned int	n;

	len = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		n = i * (-1);
	else
		n = i;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	int				l;
	char			*ret;
	unsigned int	num;

	l = ft_power_ten(n);
	if (n < 0)
		l++;
	if (!(ret = malloc(sizeof(char) * (l + 1))))
		return (NULL);
	ret[l] = '\0';
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
	{
		n *= -1;
		ret[0] = '-';
	}
	num = n;
	while (num != 0)
	{
		ret[l - 1] = (num % 10) + '0';
		num = num / 10;
		l--;
	}
	return (ret);
}

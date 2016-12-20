/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:29:51 by mploux            #+#    #+#             */
/*   Updated: 2016/11/26 23:37:22 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*source;

	i = -1;
	dest = dst;
	source = src;
	if (src > dst)
	{
		while (++i < len)
			dest[i] = source[i];
	}
	else if (src < dst)
	{
		while (++i < len)
			dest[len - i - 1] = source[len - i - 1];
	}
	return (dest);
}

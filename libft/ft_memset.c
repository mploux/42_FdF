/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:27:52 by mploux            #+#    #+#             */
/*   Updated: 2016/11/26 23:37:25 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*data;

	data = b;
	i = 0;
	while (i < len)
	{
		data[i] = (unsigned char)c;
		i++;
	}
	return (data);
}

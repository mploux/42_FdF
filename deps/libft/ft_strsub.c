/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:57:59 by mploux            #+#    #+#             */
/*   Updated: 2016/11/26 23:38:40 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*data;

	i = 0;
	if (!s)
		return (NULL);
	if (!(data = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i++ < len)
		data[i - 1] = s[i - 1 + start];
	data[i - 1] = 0;
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:09:54 by mploux            #+#    #+#             */
/*   Updated: 2016/11/26 23:38:28 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		k = 1;
		j = 0;
		while (little[j])
		{
			if (i + j >= len)
				return (NULL);
			if (!big[i + j] || little[j] != big[i + j])
				k = 0;
			j++;
		}
		if (k)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

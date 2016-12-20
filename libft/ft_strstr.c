/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 08:54:15 by mploux            #+#    #+#             */
/*   Updated: 2016/11/07 17:19:04 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i])
	{
		k = 1;
		j = 0;
		while (little[j])
		{
			if (!big[i + j] || little[j] != big[i + j])
				k = 0;
			j++;
		}
		if (k)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}

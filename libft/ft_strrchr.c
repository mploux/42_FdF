/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:10:38 by mploux            #+#    #+#             */
/*   Updated: 2016/11/26 23:38:31 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strrchr(const char *s, int c)
{
	size_t		i;
	const char	*tmp;

	i = 0;
	tmp = NULL;
	while (s[i])
	{
		if (s[i] == c)
			tmp = &s[i];
		if (s[i + 1] == c)
			tmp = &s[i + 1];
		i++;
	}
	return ((char *)tmp);
}

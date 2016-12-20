/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:10:10 by mploux            #+#    #+#             */
/*   Updated: 2016/12/12 13:43:58 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		l1;
	int		l2;
	char	*data;

	i = 0;
	if (!s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(data = ft_strnew(l1 + l2)))
		return (NULL);
	while (i < l1 + l2)
	{
		if (i < l1)
			data[i] = s1[i];
		else
			data[i] = s2[i - l1];
		i++;
	}
	data[i] = '\0';
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:35:32 by mploux            #+#    #+#             */
/*   Updated: 2016/11/26 23:38:43 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (ft_iswhitespace(s[i]) && i < j)
		i++;
	while (ft_iswhitespace(s[j]) && j >= i)
		j--;
	if (!(result = (char *)malloc(sizeof(char) * (j - i + 2))) || !s)
		return (NULL);
	while (i <= j)
		result[k++] = s[i++];
	result[k++] = 0;
	return (result);
}

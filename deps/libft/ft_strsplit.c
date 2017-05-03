/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:54:10 by mploux            #+#    #+#             */
/*   Updated: 2016/11/26 23:38:36 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_getword(const char *s, char c, int i)
{
	int		j;
	char	*result;

	j = 0;
	while (s[i + j] != c && s[i + j] != 0)
		j++;
	if (!(result = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	j = 0;
	while ((s[i + j] != c && s[i + j] != 0))
	{
		result[j] = s[i + j];
		j++;
	}
	result[j] = 0;
	j = 0;
	return (result);
}

static char		**ft_malloc_words(const char *s, char c)
{
	int		i;
	int		num;
	char	**result;

	i = 0;
	num = 1;
	if (!s)
		return (NULL);
	while (s[i++])
		if (s[i - 1] != c && (s[i] == c || s[i] == 0))
			num++;
	if (!(result = (char **)malloc(sizeof(char *) * num)))
		return (NULL);
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	char	**result;

	i = 0;
	k = 0;
	if (!(result = ft_malloc_words(s, c)))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			result[k++] = ft_getword(s, c, i);
		result[k] = NULL;
		i++;
	}
	if (!i)
		result[0] = NULL;
	return (result);
}

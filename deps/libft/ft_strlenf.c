/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:18:27 by mploux            #+#    #+#             */
/*   Updated: 2016/11/04 14:18:54 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strlenf(const char *s, int (*f)(char))
{
	int i;
	int length;

	if (!s || !f)
		return (0);
	i = 0;
	length = 0;
	while (s[i++])
	{
		if (f(s[i - 1]))
			continue;
		else
			length++;
	}
	return (length);
}

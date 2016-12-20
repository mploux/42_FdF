/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:45:10 by mploux            #+#    #+#             */
/*   Updated: 2016/11/07 21:54:39 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(const void *src, size_t n)
{
	void *result;

	if (!(result = ft_memalloc(n)))
		return (NULL);
	return (ft_memcpy(result, src, n));
}

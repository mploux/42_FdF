/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:15:18 by mploux            #+#    #+#             */
/*   Updated: 2016/12/12 11:21:34 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishex(char *str)
{
	if (str && str[0] && str[1])
		if (str[0] == '0' && str[1] == 'x')
			return (1);
	return (0);
}

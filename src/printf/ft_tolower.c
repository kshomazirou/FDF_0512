/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:44:18 by kshoma            #+#    #+#             */
/*   Updated: 2023/10/17 10:44:15 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tolower_all(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		c[i] = ft_tolower(c[i]);
		i++;
	}
	return (c);
}
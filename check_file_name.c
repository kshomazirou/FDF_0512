/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:35:39 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/05/12 19:35:50 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file_name(const char *s)
{
	char	*s2;

	s2 = 0;
	s2 = ft_strrchr(s, '.');
	if (s2 != NULL && ft_strncmp(s2, ".fdf", 4) == 0 \
		&& ft_strlen(s2) == 4)
		return (0);
	else
		return (1);
}

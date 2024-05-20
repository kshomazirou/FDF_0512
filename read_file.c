/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:24:24 by kshoma            #+#    #+#             */
/*   Updated: 2024/05/20 17:05:31 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_data_from_map(char *line, t_fdf **data, int y, int width)
{
	char	**map_data;
	int		x;
	int		num_count;

	map_data = ft_split(line, ' ');
	num_count = deli_count(line, ' ');
	x = -1;
	if (map_data[0] == NULL)
		ft_error("no data");
	while (map_data[++x] && x < width)
	{
		data[y][x].z = atoi(map_data[x]);
		data[y][x].x = x;
		data[y][x].y = y;
		data[y][x].is_last = 0;
		free(map_data[x]);
	}
	if (num_count != width)
		ft_error("data width is not same!");
	free(map_data);
	free(line);
	data[y][--x].is_last = 1;
}

int	line_check(char *line)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	if (line[i] != ' ')
		i--;
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	return (width);
}

t_fdf	**new_malloc(int x, int y)
{
	t_fdf		**new;

	new = (t_fdf **)malloc(sizeof(t_fdf *) * (++y + 1));
	if (!new)
		ft_error("malloc error");
	while (y > 0)
	{
		new[--y] = (t_fdf *)malloc(sizeof(t_fdf) * (x + 1));
		if (!new[y])
			ft_error("malloc error");
	}
	return (new);
}

t_fdf	**map_memory(char *file_name, int *width)
{
	int			x;
	int			y;
	int			fd;
	char		*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("NOT EXIST FILE!");
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_error("no data"), NULL);
	x = deli_count(line, ' ');
	*width = line_check(line);
	free(line);
	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (new_malloc(x, y));
}

t_fdf	**read_file(char *file_name)
{
	int			fd;
	int			y;
	int			width;
	char		*line;
	t_fdf		**data;

	width = 0;
	data = map_memory(file_name, &width);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		get_data_from_map(line, data, y++, width);
		line = get_next_line(fd);
	}
	free(line);
	data[y] = NULL;
	return (close(fd), data);
}

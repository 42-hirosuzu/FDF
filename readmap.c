/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 07:43:46 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/17 23:56:39 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	resize_fdf(t_data *fdf, int malloc_size)
{
	t_vector	**temp_z;

	temp_z = (t_vector **)ft_realloc(fdf->matrix_z, \
		fdf->size_y * sizeof(t_vector *), \
		(malloc_size + 1) * sizeof(t_vector *));
	free(fdf->matrix_z);
	fdf->matrix_z = temp_z;
}

int	allocate_memory(t_data *fdf, char *line)
{
	static size_t	malloc_size;
	size_t			numwords;

	if (fdf->size_y >= malloc_size)
	{
		malloc_size += 100;
		resize_fdf(fdf, malloc_size);
	}
	numwords = ft_countwords(line, ' ');
	fdf->matrix_z[fdf->size_y] = \
	(t_vector *)ft_calloc(numwords + 1, sizeof(t_vector));
	return (malloc_size);
}

void	input_fdf(t_data *fdf, int z, uint32_t color)
{
	fdf->matrix_z[fdf->size_y][fdf->size_x].z = z;
	fdf->matrix_z[fdf->size_y][fdf->size_x].x = fdf->size_x;
	fdf->matrix_z[fdf->size_y][fdf->size_x].y = fdf->size_y;
	fdf->matrix_z[fdf->size_y][fdf->size_x].color = color;
}

void	set_matrix(t_data *fdf, char *line)
{
	char		**words;
	char		*temp;
	size_t		comma;

	allocate_memory(fdf, line);
	words = ft_split(line, ' ');
	while (*words)
	{
		comma = ft_strchar_position(*words, ',');
		if (comma)
		{
			temp = ft_strndup(*words, (comma - 1));
			input_fdf (fdf, ft_atoi (temp), \
				ft_strtol ((*words) + comma, NULL, 0));
			free (temp);
		}
		else
			input_fdf (fdf, ft_atoi(*words), COLOR);
		words++;
		fdf->size_x++;
	}
	free(*words);
}

void	read_map(t_data *fdf, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		error_exit("get_next_line");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fdf->size_x = 0;
		set_matrix(fdf, line);
		free(line);
		fdf->size_y++;
	}
	close(fd);
}

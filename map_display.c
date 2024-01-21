/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 07:46:40 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/10 00:37:27 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_display(t_data *fdf, size_t i, size_t j, char content)
{
	if (content == '0')
		ft_printf("%d\t", (int)fdf->matrix_z[i][j].x);
	else if (content == '1')
		ft_printf("%d\t", (int)fdf->matrix_z[i][j].y);
	else if (content == '2')
		ft_printf("%d\t", (int)fdf->matrix_z[i][j].z);
	else if (content == '3')
		ft_printf("%d\t", (int)fdf->matrix_z[i][j].vx);
	else if (content == '4')
		ft_printf("%d\t", (int)fdf->matrix_z[i][j].vy);
	else if (content == '5')
		ft_printf("%d\t", (int)fdf->matrix_z[i][j].vz);
	else if (content == '6')
		ft_printf("%d\t", (int)fdf->matrix_z[i][j].color);
}

void	map_display(t_data *fdf, char content)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (fdf->size_y > i)
	{
		j = 0;
		while (fdf->size_x > j)
		{
			print_display(fdf, i, j, content);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

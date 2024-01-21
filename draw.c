/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:36:28 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/21 18:54:41 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_pixel(t_data *fdf, t_vector *change, t_vector *end)
{
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)(change->x), \
		(int)(change->y), change->color);
	change->x += change->vx;
	change->y += change->vy;
	if ((change->x >= end->vx && change->vx >= 0) || \
		(change->x < end->vx && change->vx < 0))
		if ((change->y >= end->vy && change->vy >= 0) || \
			(change->y < end->vy && change->vy < 0))
			return (1);
	return (0);
}

void	draw_line(t_data *fdf, t_vector *start, t_vector *end)
{
	t_vector	change;
	int			step;
	int			i;

	i = 0;
	affine_transformation(fdf, start->x, start->y);
	affine_transformation(fdf, end->x, end->y);
	change.vx = end->vx - start->vx;
	change.vy = end->vy - start->vy;
	step = ft_uppercase(ft_fabs(change.vx), ft_fabs(change.vy));
	if (step == 0)
		step = 1;
	change.vx /= step;
	change.vy /= step;
	change.x = start->vx;
	change.y = start->vy;
	while (i <= step)
	{
		change.color = create_gradient(start->color, end->color, i, step);
		if (draw_pixel(fdf, &change, end))
			break ;
		i++;
	}
}

int	draw_wireframe(t_data *fdf)
{
	int			x;
	int			y;

	y = 0;
	while ((double)y < fdf->size_y - 1)
	{
		x = 0;
		while ((double)x < fdf->size_x - 1)
		{
			draw_line(fdf, &fdf->matrix_z[y][x], &fdf->matrix_z[y][(x + 1)]);
			draw_line(fdf, &fdf->matrix_z[y][x], &fdf->matrix_z[(y + 1)][x]);
			x++;
		}
		draw_line(fdf, &fdf->matrix_z[y][x], &fdf->matrix_z[(y + 1)][x]);
		y++;
	}
	x = 0;
	while ((double)x < fdf->size_x - 1)
	{
		draw_line(fdf, &fdf->matrix_z[y][x], &fdf->matrix_z[y][(x + 1)]);
		x++;
	}
	return (0);
}

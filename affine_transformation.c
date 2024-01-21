/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:22:47 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/21 18:54:13 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	to_radians(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

void	transform_zoom(t_data *fdf, int x, int y)
{
	fdf->matrix_z[y][x].vx *= fdf->head->zoom;
	fdf->matrix_z[y][x].vy *= fdf->head->zoom;
	fdf->matrix_z[y][x].vz *= fdf->head->zoom;
}

void	transform_rotate(t_data *fdf, int x, int y)
{
	double		rotation_x;
	double		rotation_y;
	double		rotation_z;
	t_vector	temp;

	rotation_x = to_radians(fdf->head->rotation_x);
	rotation_y = to_radians(fdf->head->rotation_y);
	rotation_z = to_radians(fdf->head->rotation_z);
	temp = fdf->matrix_z[y][x];
	fdf->matrix_z[y][x].vy = temp.vy * cos(rotation_x) \
		- temp.vz * sin(rotation_x);
	fdf->matrix_z[y][x].vz = temp.vy * sin(rotation_x) \
		+ temp.vz * cos(rotation_x);
	temp = fdf->matrix_z[y][x];
	fdf->matrix_z[y][x].vx = temp.vx * cos(rotation_y) \
		+ temp.vz * sin(rotation_y);
	fdf->matrix_z[y][x].vz = temp.vx * sin(rotation_y) \
		+ temp.vz * cos(rotation_y);
	temp = fdf->matrix_z[y][x];
	fdf->matrix_z[y][x].vx = temp.vx * cos(rotation_z) \
		- temp.vy * sin(rotation_z);
	fdf->matrix_z[y][x].vy = temp.vx * sin(rotation_z) \
		+ temp.vy * cos(rotation_z);
}

void	transform_shift(t_data *fdf, int x, int y)
{
	fdf->matrix_z[y][x].vx += fdf->head->shift_x;
	fdf->matrix_z[y][x].vy += fdf->head->shift_y;
}

void	affine_transformation(t_data *fdf, int x, int y)
{
	fdf->matrix_z[y][x].vx = fdf->matrix_z[y][x].x;
	fdf->matrix_z[y][x].vy = fdf->matrix_z[y][x].y;
	fdf->matrix_z[y][x].vz = fdf->matrix_z[y][x].z;
	transform_zoom(fdf, x, y);
	transform_rotate(fdf, x, y);
	transform_shift(fdf, x, y);
}

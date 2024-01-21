/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:43:27 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/21 18:51:08 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_transform(int key, t_data *fdf)
{
	if (key == UP_KEY)
		fdf->head->shift_y -= 10;
	else if (key == DOWN_KEY)
		fdf->head->shift_y += 10;
	else if (key == RIGHT_KEY)
		fdf->head->shift_x += 10;
	else if (key == LEFT_KEY)
		fdf->head->shift_x -= 10;
	else if (key == IN_KEY)
		fdf->head->zoom += 2;
	else if (key == OUT_KEY)
		fdf->head->zoom -= 2;
	else if (key == ROTATE_R_KEY)
		fdf->head->rotation_y += 10;
	else if (key == ROTATE_L_KEY)
		fdf->head->rotation_y -= 10;
	else if (key == ROTATE_F_KEY)
		fdf->head->rotation_x += 10;
	else if (key == ROTATE_B_KEY)
		fdf->head->rotation_x -= 10;
	else if (key == ROTATE_ZL_KEY)
		fdf->head->rotation_z -= 10;
	else if (key == ROTATE_ZR_KEY)
		fdf->head->rotation_z += 10;
	return (0);
}

int	key_presset(int key, t_data *fdf)
{
	if (key == CLEAR_KEY)
		ft_memset(fdf->head, 0, sizeof(t_transform));
	else if (key == START_KEY)
		default_parameters(fdf);
	return (0);
}

int	key_press(int key, t_data *fdf)
{
	if (key == ESC_KEY)
		close_window(fdf);
	key_transform(key, fdf);
	key_presset(key, fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_wireframe (fdf);
	ft_printf("key = %d\n", key);
	return (0);
}

int	close_window(void *param)
{
	if (param)
		exit(0);
	exit(0);
	return (0);
}

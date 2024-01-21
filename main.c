/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:00:54 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/21 18:48:46 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	default_parameters(t_data *fdf)
{
	fdf->head = ft_calloc(1, sizeof(t_transform));
	ft_memset(fdf->head, 0, sizeof(t_transform));
	fdf->head->shift_x = WINDOW_W / 2 - (fdf->size_x / 2 * ZOOM);
	fdf->head->shift_y = WINDOW_H / 2 - fdf->size_y / 2 * ZOOM;
	fdf->head->zoom = 1;
	fdf->head->rotation_x = ROTATE_X;
	fdf->head->rotation_y = ROTATE_Y;
	fdf->head->rotation_z = ROTATE_Z;
}

int	main(int argc, char **argv)
{
	t_data	fdf;

	if (argc != 2)
		error_exit("argc != 2");
	ft_memset(&fdf, 0, sizeof(t_data));
	fdf.mlx_ptr = mlx_init();
	if (!fdf.mlx_ptr)
		error_exit("mlx_init");
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WINDOW_W, WINDOW_H, "FDF");
	if (!fdf.win_ptr)
		error_exit("mlx_new_window");
	read_map(&fdf, argv[1]);
	default_parameters(&fdf);
	draw_wireframe(&fdf);
	mlx_key_hook(fdf.win_ptr, key_press, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, close_window, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:27:21 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/22 02:22:45 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
// # include <ctype.h>
// # include <string.h>
# include <math.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "./Libft/libft.h"
# include "./Libft/get_next_line.h"
# include "./printf/printf.h"
# include "./minilibx-linux/mlx.h"

# define WINDOW_W 2000
# define WINDOW_H 1000
# define COLOR 0x00FF00
# define ZOOM 1
# define ROTATE_X 0
# define ROTATE_Y 0
# define ROTATE_Z 0
# define UP_KEY 126
# define ESC_KEY 53
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define IN_KEY 30
# define OUT_KEY 42
# define ROTATE_R_KEY 2
# define ROTATE_L_KEY 0
# define ROTATE_F_KEY 13
# define ROTATE_B_KEY 1
# define ROTATE_ZL_KEY 12
# define ROTATE_ZR_KEY 14
# define CLEAR_KEY 29
# define START_KEY 18

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_vector
{
	double		x;
	double		y;
	double		z;
	double		vx;
	double		vy;
	double		vz;
	uint32_t	color;
}				t_vector;

typedef struct s_transform
{
	double				zoom;
	double				shift_x;
	double				shift_y;
	double				rotation_x;
	double				rotation_y;
	double				rotation_z;
	struct s_transform	*next;
	struct s_transform	*prev;
}				t_transform;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	size_t		size_x;
	size_t		size_y;

	t_vector	**matrix_z;
	t_transform	*head;
}				t_data;

int		main(int argc, char **argv);
void	default_parameters(t_data *fdf);
double	to_radians(double degrees);
void	error_exit(char *str);
void	map_display(t_data *fdf, char content);
void	read_map(t_data *fdf, char *file_path);
void	affine_transformation(t_data *fdf, int x, int y);
void	transform_shift(t_data *fdf, int x, int y);
void	transform_rotate(t_data *fdf, int x, int y);
void	transform_zoom(t_data *fdf, int x, int y);
int		draw_wireframe(t_data *fdf);
void	draw_line(t_data *fdf, t_vector *start, t_vector *end);
int		draw_pixel(t_data *fdf, t_vector *change, t_vector *end);
int		create_gradient(int startcolor, int endcolor, int i, int step);
void	extract_rgb(int color, int *r, int *g, int *b);
int		key_transform(int key, t_data *fdf);
int		key_presset(int key, t_data *fdf);
int		key_press(int key, t_data *fdf);
int		close_window(void *param);

#endif

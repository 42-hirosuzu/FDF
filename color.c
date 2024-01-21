/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:36:03 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/10 00:26:40 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	extract_rgb(int color, int *r, int *g, int *b)
{
	*r = (color >> 16) & 0xFF;
	*g = (color >> 8) & 0xFF;
	*b = color & 0xFF;
}

int	create_gradient(int startcolor, int endcolor, int i, int step)
{
	t_color	start;
	t_color	end;
	t_color	ret;

	if (step == 0)
		return (startcolor);
	extract_rgb(startcolor, &start.r, &start.g, &start.b);
	extract_rgb(endcolor, &end.r, &end.g, &end.b);
	ret.r = start.r + (end.r - start.r) * i / step;
	ret.g = start.g + (end.g - start.g) * i / step;
	ret.b = start.b + (end.b - start.b) * i / step;
	return ((ret.r << 16) | (ret.g << 8) | ret.b);
}
	// printf("r = %d,",ret.r);
	// printf("g = %d,",ret.g);
	// printf("b = %d\n,",ret.b);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:49:56 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/10 00:34:01 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(char *str)
{
	if (str)
		ft_printf("Error : %s\n", str);
	else
		ft_printf("Error\n");
	exit (EXIT_FAILURE);
}

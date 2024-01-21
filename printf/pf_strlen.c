/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 06:24:52 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/10/14 08:48:20 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"

size_t	pf_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

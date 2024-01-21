/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:43:30 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/06/04 16:48:40 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	mallocsize;

	if (size != 0 && (size_t)SIZE_MAX / size < count)
		return (NULL);
	if (count == 0 || size == 0)
		mallocsize = 1;
	else
		mallocsize = count * size;
	p = (void *)malloc(mallocsize);
	if (!p)
		return (NULL);
	ft_bzero(p, mallocsize);
	return (p);
}

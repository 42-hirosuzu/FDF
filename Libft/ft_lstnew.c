/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 07:46:32 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/06/06 08:28:19 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

// int main (){
// 	char test[] = "tkodai";
// 	t_list *a;
// 	a = ft_lstnew(test);
// 	printf("test lstnew = %s\n",(char *)a->content);
// 	return(0);
// }
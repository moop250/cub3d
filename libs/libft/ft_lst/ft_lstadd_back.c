/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:44:42 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/08 17:15:01 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
lst: The address of a pointer to the first link of
a list.
new_lst: The address of a pointer to the node to be
added to the list.
Adds the node ’new_lst’ at the end of the list
*/

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*current;

	current = NULL;
	if (*lst == NULL)
		*lst = new_lst;
	else
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new_lst;
	}
}

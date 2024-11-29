/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:45:34 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/08 17:15:17 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Adds the node 'new_lst' at the beginning of the list.

lst: The address of a pointer to the first link of a list.
new_lst: The address of a pointer to the node to be added to the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new_lst)
{
	new_lst->next = *lst;
	*lst = new_lst;
}

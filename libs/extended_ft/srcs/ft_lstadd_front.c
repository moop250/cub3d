/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:54:09 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/07 18:13:51 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_ft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_lst)
{
	new_lst->next = *lst;
	*lst = new_lst;
	return ;
}

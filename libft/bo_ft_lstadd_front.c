/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bo_ft_lstadd_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:19:31 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 14:19:33 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

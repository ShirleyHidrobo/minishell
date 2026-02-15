/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bo_ft_lstdelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:19:08 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 14:19:10 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}

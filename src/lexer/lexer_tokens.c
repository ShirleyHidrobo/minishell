/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:00:46 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 14:00:49 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*token_new(char *value, t_tok_type type)
{
	t_token	*t;

	t = malloc(sizeof(*t));
	if (!t)
		return (NULL);
	t->type = type;
	t->val = value;
	t->next = NULL;
	return (t);
}

void	token_add_back(t_token **lst, t_token *new)
{
	t_token	*cur;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

void	token_list_clear(t_token **lst)
{
	t_token	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free((*lst)->val);
		free(*lst);
		*lst = tmp;
	}
}

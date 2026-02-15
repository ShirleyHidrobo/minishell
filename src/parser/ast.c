/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:58:12 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 13:58:15 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	free_strv(char **v)
{
	size_t	i;

	if (!v)
		return ;
	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}

static void	free_redirs(t_redir *r)
{
	t_redir	*nx;

	while (r)
	{
		nx = r->next;
		free(r->target);
		free(r);
		r = nx;
	}
}

void	free_cmds(t_cmd *c)
{
	t_cmd	*nx;

	if (!c)
		return ;
	while (c)
	{
		nx = c->next;
		free_strv(c->argv);
		free_redirs(c->redirs);
		free(c);
		c = nx;
	}
}

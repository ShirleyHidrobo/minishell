/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:00:00 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 16:18:57 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

void	skip_spaces(const char *s, size_t *i)
{
	while (s[*i] && is_space(s[*i]))
		(*i)++;
}

int	is_op_char(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == ';');
}

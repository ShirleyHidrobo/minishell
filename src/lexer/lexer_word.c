/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:58:58 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 13:59:00 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	ensure_buf_cap(t_wbuf *b, size_t new_len)
{
	char	*new_data;
	size_t	new_cap;

	if (new_len + 1 <= b->cap)
		return (0);
	new_cap = b->cap;
	if (new_cap == 0)
		new_cap = 16;
	while (new_len + 1 > new_cap)
		new_cap *= 2;
	new_data = malloc(new_cap);
	if (!new_data)
		return (-1);
	if (b->data)
	{
		ft_memcpy(new_data, b->data, b->len);
		free(b->data);
	}
	b->data = new_data;
	b->cap = new_cap;
	return (0);
}

static int	word_append_char(t_wbuf *b, char c)
{
	if (ensure_buf_cap(b, b->len + 1) < 0)
		return (-1);
	b->data[b->len] = c;
	b->len++;
	return (0);
}

static int	read_quoted(const char *s, size_t *i, t_wbuf *b)
{
	char	q;

	q = s[*i];
	if (word_append_char(b, q) < 0)
		return (-1);
	(*i)++;
	while (s[*i] && s[*i] != q)
	{
		if (word_append_char(b, s[*i]) < 0)
			return (-1);
		(*i)++;
	}
	if (!s[*i])
		return (-1);
	if (word_append_char(b, q) < 0)
		return (-1);
	(*i)++;
	return (0);
}

int	process_word_char(const char *s, size_t *i, t_wbuf *b)
{
	if (s[*i] == '\'' || s[*i] == '\"')
		return (read_quoted(s, i, b));
	if (word_append_char(b, s[*i]) < 0)
		return (-1);
	(*i)++;
	return (0);
}

char	*read_word(const char *s, size_t *i)
{
	t_wbuf	b;
	int		r;

	b.data = NULL;
	b.len = 0;
	b.cap = 0;
	while (s[*i] && !is_space(s[*i]) && !is_op_char(s[*i]))
	{
		r = process_word_char(s, i, &b);
		if (r < 0)
		{
			free(b.data);
			return (NULL);
		}
	}
	if (!b.data)
		return (ft_strdup(""));
	b.data[b.len] = '\0';
	return (b.data);
}

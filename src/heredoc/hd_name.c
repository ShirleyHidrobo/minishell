/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:06:12 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 14:06:14 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "libft.h"
#include <unistd.h> 

static char	*hd_prefix(void)
{
	char	*pid_s;
	char	*tmp;
	char	*tmp2;

	pid_s = ft_itoa((int)getpid());
	if (!pid_s)
		return (NULL);
	tmp = ft_strjoin(".heredoc_", pid_s);
	free(pid_s);
	if (!tmp)
		return (NULL);
	tmp2 = ft_strjoin(tmp, "_");
	free(tmp);
	return (tmp2);
}

char	*hd_make_name(void)
{
	static int	idx;
	char		*num;
	char		*prefix;
	char		*name;

	prefix = hd_prefix();
	if (!prefix)
		return (NULL);
	num = ft_itoa(idx++);
	if (!num)
		return (free(prefix), NULL);
	name = ft_strjoin(prefix, num);
	free(prefix);
	free(num);
	return (name);
}

char	*hd_unquote_delim(const char *s)
{
	size_t	i;
	size_t	j;
	char	*out;

	if (!s)
		return (NULL);
	out = (char *)malloc(ft_strlen(s) + 1);
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '\'' && s[i] != '\"')
			out[j++] = s[i];
		i++;
	}
	out[j] = '\0';
	return (out);
}

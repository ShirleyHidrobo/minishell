/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:06:39 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 14:12:46 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

int	is_var_start(char c)
{
	if (ft_isalpha((unsigned char)c) || c == '_')
		return (1);
	return (0);
}

int	is_var_char(char c)
{
	if (ft_isalnum((unsigned char)c) || c == '_')
		return (1);
	return (0);
}

char	*exp_get_env_val(const char *name, char **envp)
{
	size_t	len;
	int		i;

	if (!name || !envp)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], name, len)
			&& envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

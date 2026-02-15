/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:08:05 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 14:13:56 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "expand.h"

char	*get_env_val(char **envp, const char *key)
{
	return (exp_get_env_val(key, envp));
}

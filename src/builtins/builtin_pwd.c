/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:08:24 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 14:15:02 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"
#include <errno.h>
#include <stdio.h>

int	builtin_pwd(char **argv)
{
	char	*cwd;

	(void)argv;
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("minishell: pwd");
		return (1);
	}
	write(1, cwd, ft_strlen(cwd));
	write(1, "\n", 1);
	free(cwd);
	return (0);
}

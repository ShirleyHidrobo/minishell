/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:08:34 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 14:15:58 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "exec.h"
#include <limits.h>

static int	ms_exit_code_from_ll(long long v)
{
	unsigned char	c;

	c = (unsigned char)v;
	return ((int)c);
}

static void	exit_error(const char *msg, const char *arg)
{
	write(2, "minishell: exit", 15);
	if (arg)
	{
		write(2, ": ", 2);
		write(2, arg, ft_strlen(arg));
	}
	if (msg)
	{
		write(2, ": ", 2);
		write(2, msg, ft_strlen(msg));
	}
	write(2, "\n", 1);
}

static int	handle_exit_args(char **argv, int last_status, int *should_exit)
{
	long long	v;

	if (!argv[1])
	{
		*should_exit = 1;
		return (last_status);
	}
	if (!ms_atoll_strict(argv[1], &v))
	{
		exit_error("numeric argument required", argv[1]);
		*should_exit = 1;
		return (2);
	}
	if (argv[2])
	{
		exit_error("too many arguments", NULL);
		*should_exit = 0;
		return (1);
	}
	*should_exit = 1;
	return (ms_exit_code_from_ll(v));
}

int	builtin_exit(char **argv, int last_status)
{
	int	status;
	int	should_exit;

	status = handle_exit_args(argv, last_status, &should_exit);
	if (should_exit)
		return (EXIT_REQ_BASE + (status & 255));
	return (status);
}

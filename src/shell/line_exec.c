/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:54:56 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 16:03:21 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*lex_parse_line(char *line)
{
	t_token	*ts;
	t_cmd	*cmds;

	ts = lex_line(line);
	if (!ts)
	{
		write(1, "Syntax Error\n", 13);
		return (NULL);
	}
	cmds = parse_tokens(ts);
	token_list_clear(&ts);
	return (cmds);
}

static int	line_is_blank(char *line)
{
	size_t	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	run_heredocs(t_shell_ctx *ctx)
{
	int	hd;

	hd = setup_heredocs(ctx);
	if (hd == 2)
		return (2);
	if (hd != 0)
	{
		ctx->exit_status = 1;
		return (1);
	}
	return (0);
}

static void	exec_cmds(t_shell_ctx *ctx)
{
	ctx->exit_status = exec_pipeline(ctx);
	free_cmds(ctx->cmds);
	ctx->cmds = NULL;
}

int	process_line(t_shell_ctx *ctx)
{
	int	st;

	if (line_is_blank(ctx->current_subline))
		return (ctx->exit_status);
	ctx->cmds = lex_parse_line(ctx->current_subline);
	if (!ctx->cmds)
		return (2);
	if (expand_all(ctx))
	{
		free_cmds(ctx->cmds);
		ctx->cmds = NULL;
		return (1);
	}
	st = run_heredocs(ctx);
	if (st != 0)
	{
		free_cmds(ctx->cmds);
		ctx->cmds = NULL;
		if (st == 2)
			return (ctx->exit_status);
		return (1);
	}
	exec_cmds(ctx);
	return (ctx->exit_status);
}

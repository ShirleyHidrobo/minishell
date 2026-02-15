/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:52:35 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 15:14:14 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signals.h"
#include <readline/readline.h>

static void	shell_init(char **envp_in, t_shell_ctx *ctx)
{
	ctx->exit_status = 0;
	ctx->prev_fd = -1;
	ctx->pids = NULL;
	ctx->envp = dup_env(envp_in);
	rl_bind_key('\t', rl_insert);
	tcgetattr(STDIN_FILENO, &ctx->term_orig);
	ms_set_termios(0);
	ms_sig_raedline_off();
	set_sig_interactive();
}

static int	shell_loop(t_shell_ctx *ctx)
{
	int	st;

	while (1)
	{
		ctx->line = readline("minishell> ");
		if (!ctx->line)
		{
			write(1, "exit\n", 5);
			st = EXIT_REQ_BASE + (ctx->exit_status & 255);
			break ;
		}
		st = process_pasted_lines(ctx);
		free(ctx->line);
		if (st >= EXIT_REQ_BASE)
		{
			write(1, "exit\n", 5);
			ctx->exit_status = (st - EXIT_REQ_BASE) & 255;
			break ;
		}
	}
	return (0);
}

void	exit_and_clear_ctx(int exit_code, t_shell_ctx *ctx)
{
	free_ctx(ctx);
	exit(exit_code);
}

void	free_ctx(t_shell_ctx *ctx)
{
	free_env(ctx->envp);
	ctx->envp = NULL;
	free_cmds(ctx->cmds);
	if (ctx->current_subline)
		free(ctx->current_subline);
	if (ctx->pids)
		free(ctx->pids);
}

int	main(int argc, char **argv, char **envp_in)
{
	t_shell_ctx	ctx;

	(void)argc;
	(void)argv;
	ft_bzero(&ctx, sizeof(ctx));
	shell_init(envp_in, &ctx);
	shell_loop(&ctx);
	free_ctx(&ctx);
	return (ctx.exit_status);
}

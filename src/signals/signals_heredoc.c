/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:50:50 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 17:21:52 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <readline/readline.h>

void	set_sig_heredoc_child(void)
{
	set_signal_handler(SIGINT, SIG_DFL);
	set_signal_handler(SIGQUIT, SIG_IGN);
}

void	ms_sig_raedline_off(void)
{
	rl_catch_signals = 0;
	rl_catch_sigwinch = 0;
}

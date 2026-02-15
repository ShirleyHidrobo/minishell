/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:20:58 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 16:23:28 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <unistd.h>

extern volatile sig_atomic_t	g_sig;

// extern int						rl_catch_signals;
// extern int						rl_catch_sigwinch;

void							set_signal_handler(int sig,
									void (*handler)(int));
void							set_sig_interactive(void);
void							set_sig_child_default(void);
void							set_sig_ignore(void);
void							set_sig_heredoc_child(void);
void							ms_sig_raedline_off(void);

#endif

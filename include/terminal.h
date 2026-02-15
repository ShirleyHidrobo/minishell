/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:20:16 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 14:20:18 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include <termios.h>
# include <unistd.h>
# include <shell.h>

void	ms_set_termios(int on);
void	ms_restore_termios(t_shell_ctx *ctx);

#endif
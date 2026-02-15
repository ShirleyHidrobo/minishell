/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:22:47 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 14:22:49 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "parser.h"
# include "shell.h"

typedef struct s_hd
{
	int		fd;
	char	*file_name;
	char	*delim;
	int		quoted;
	char	**envp;
	int		last_status;
}			t_hd;

char		*hd_make_name(void);
char		*hd_unquote_delim(const char *s);

int			hd_write_line(int fd, const char *s);

int			hd_read_loop(t_hd *h, t_shell_ctx *ctx);

int			process_heredoc(t_redir *r, t_shell_ctx *ctx);
int			setup_heredocs(t_shell_ctx *ctx);

int			hd_init(t_hd *h, t_redir *r, t_shell_ctx *ctx);
int			hd_make_and_open(t_hd *h);
void		hd_cleanup_parent(t_hd *h);
int			hd_set_target(t_redir *r, char *fname);
void		free_hd(t_hd *hd);
#endif
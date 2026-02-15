/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:22:55 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 15:24:00 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "parser.h"
# include "shell.h"

typedef struct s_exp
{
	char	*buf;
	size_t	len;
	size_t	cap;
}			t_exp;

typedef struct s_expst
{
	t_exp		*e;
	t_shell_ctx	*ctx;
	int			in_s;
}			t_expst;

int		is_var_start(char c);
int		is_var_char(char c);
char	*exp_get_env_val(const char *name, char **envp);

char	*expand_word(const char *s, t_shell_ctx *ctx);

int		expand_all(t_shell_ctx *ctx);

int		grow_buf(t_exp *e, size_t need);
int		append_char(t_exp *e, char c);
int		append_str(t_exp *e, const char *str);
int		expand_status(size_t *i, t_exp *e, t_shell_ctx *ctx);
int		expand_env_var(const char *s, size_t *i, t_exp *e, t_shell_ctx *ctx);

#endif
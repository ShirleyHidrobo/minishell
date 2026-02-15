/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:25:02 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 14:25:03 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "shell.h"

typedef struct s_cmd		t_cmd;
typedef struct s_execctx	t_execctx;

int							builtin_echo(char **argv);
int							builtin_cd(char **argv, char ***envp);
int							builtin_pwd(char **argv);
int							builtin_env(char **argv, char **envp);
int							builtin_export(char **argv, char ***envp);
int							builtin_unset(char **argv, char ***envp);
int							builtin_exit(char **argv, int last_status);

int							is_builtin_name(char *name);
int							exec_builtin(t_cmd *cmd, t_shell_ctx *ctx);
int							is_valid_key(const char *key);
int							ms_atoll_strict(const char *s, long long *out);

#endif
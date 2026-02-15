/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafshar <yafshar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:04:50 by yafshar           #+#    #+#             */
/*   Updated: 2026/02/11 14:04:52 by yafshar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "libft.h"

int	hd_write_line(int fd, const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (write(fd, s, len) < 0)
		return (1);
	if (write(fd, "\n", 1) < 0)
		return (1);
	return (0);
}

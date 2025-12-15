/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhidrob <shhidrob@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:38:21 by shhidrob          #+#    #+#             */
/*   Updated: 2025/12/15 19:47:22 by shhidrob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H


# ifndef FOPEN_MAX 
#  define FOPEN_MAX 42

# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd);
char	*readbuff(int fd, char *buff, char *storage);
char	*extract_line(char *buff);
size_t	ft_gstrlen(char *s);
char	*ft_gstrjoin(char *s1, char *s2);
char	*ft_gstrndup(char *src, size_t n);
void	*ft_gmemmove(void *dest, void *src, size_t n);
char	*ft_gstrdup(char *src);
char	*ft_gstrnjoin(char *s1, char *s2, size_t n);
char	*ft_gstrchr(char *s, int c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhidrob <shhidrob@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:44:41 by shhidrob          #+#    #+#             */
/*   Updated: 2025/12/15 19:37:42 by shhidrob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gstrjoin(char *s1, char *s2)
{
	char		*new_str;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_gstrlen(s1) + ft_gstrlen(s2) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i] = s2[j];
		j++;
		i++;
	}
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_gstrnjoin(char *s1, char *s2, size_t n)
{
	char		*new_str;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_gstrlen(s1) + n + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < n)
	{
		new_str[i] = s2[j];
		j++;
		i++;
	}
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

void	*ft_gmemmove(void *dest, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == dest)
		return (dest);
	else if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else if (src < dest)
		while (n-- > 0)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}

char	*ft_gstrdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((ft_gstrlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_gstrndup(char *src, size_t n)
{
	char		*dest;
	size_t		i;

	i = 0;
	dest = malloc((n + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

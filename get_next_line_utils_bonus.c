/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 04:04:38 by marvin            #+#    #+#             */
/*   Updated: 2021/01/06 04:04:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*c_d;
	unsigned char	*c_s;
	size_t			i;

	c_d = (unsigned char *)dst;
	c_s = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*c_d++ = *c_s++;
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new_s1;

	len = ft_strlen(s1) + 1;
	if (!(new_s1 = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_memcpy(new_s1, s1, len);
	return (new_s1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	j = 0;
	if (!dst && !src)
		return (0);
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize > 0)
	{
		while (src[j] && i < dstsize - 1)
		{
			dst[i++] = src[j++];
		}
	}
	else
		return (s_len);
	dst[i] = '\0';
	if (d_len > dstsize)
		d_len = dstsize;
	return (s_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	result = 0;
	if (s1 != 0 && s2 != 0)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
		if (!result)
			return (NULL);
		if (s1)
			ft_strlcpy(result, s1, len_s1 + 1);
		else
			ft_strlcpy(result, s2, len_s2 + 1);
		if (s1 && s2)
			ft_strlcpy(result + len_s1, s2, len_s2 + 1);
	}
	return (result);
}

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

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new_s1;

	len = ft_strlen(s1) + 1;
	if (!(new_s1 = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	len = 0;
	while (s1[len])
	{
		new_s1[len] = s1[len];
		len++;
	}
	new_s1[len] = '\0';
	return (new_s1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	index;

	s_len = 0;
	while (src[s_len] != '\0')
		s_len++;
	if (dstsize == 0)
		return (s_len);
	index = 0;
	while (src[index] != '\0' && index < (dstsize - 1))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = 0;
	return (s_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t d_len;
	size_t s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = d_len;
	j = 0;
	if (size > 0 && d_len < size - 1)
	{
		while (src[j] && d_len + j < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = 0;
	}
	if (d_len > size)
		d_len = size;
	return (d_len + s_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	result = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (s1 != 0 && s2 != 0)
	{
		if (!(result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
			return (NULL);
		ft_strlcpy(result, s1, len_s1 + 1);
		ft_strlcat(result + len_s1, s2, len_s2 + 1);
	}
	return (result);
}

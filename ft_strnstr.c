/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:17:40 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/02 12:49:09 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		needle_len;
	size_t		max_idx;
	char		*haystack_copy;

	if (ft_strlen(needle) == 0 || !needle || haystack == needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	haystack_copy = (char *)haystack;
	needle_len = ft_strlen(needle);
	max_idx = len - needle_len;
	i = 0;
	while (i < max_idx)
	{
		haystack_copy = ft_memchr(haystack_copy, needle[0], len);
		if (!haystack_copy)
			return (NULL);
		i = (size_t)(haystack_copy - haystack);
		if (!ft_strncmp(haystack_copy, needle, needle_len) && i <= max_idx)
			return ((char *)haystack_copy);
		haystack_copy++;
	}
	return (NULL);
}

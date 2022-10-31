/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:30:03 by tspoof            #+#    #+#             */
/*   Updated: 2022/10/31 11:43:04 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	slen = ft_strlen(s) + 1;
	while (slen >= 0)
	{
		if (s[slen] == c)
		{
			return ((char *)(s + slen));
		}
		slen--;
	}
	return (NULL);
}

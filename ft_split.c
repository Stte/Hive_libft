/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:50:56 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/05 23:12:09 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_all(char **arr)
{
	while (arr)
	{
		free(*arr);
		arr++;
	}
	return (0);
}

int	ft_split_count(const char *s, char c)
{
	int	i;
	int count;

	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i - 1] != c)
			count++;
	}
	return (count);
}

int	ft_splitter(char const *s, char c, char **arr, int split_count)
{
	int		i;
	int		i_prev;
	int		arr_i;
	int		size;

	i = 0;
	i_prev = 0;
	arr_i = 0;
	while (arr_i < split_count)
	{
		while (s[i] && s[i] == c)
			i++;
		i_prev = i;
		while (s[i] && s[i] != c)
			i++;
		size = i - i_prev;
		arr[arr_i] = (char *)malloc((size + 1) * sizeof(char));
		if (!arr[arr_i])
			return (ft_free_all(arr));
		ft_strlcpy(arr[arr_i], s + i_prev, size + 1);
		arr_i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		split_count;

	if (!s)
		return (NULL);
	split_count = ft_split_count(s, c);
	arr = (char **)malloc((split_count + 1) *sizeof(char *));
	if (!arr)
		return (NULL);
	arr[split_count + 1] = NULL;
	if(!ft_splitter(s, c, arr, split_count))
		return (NULL);
	return (arr);
}

// int	main()
// {
// 	char *str = "\0aa\0bbb";
// 	char c = '\0';
// 	char	**expected = ft_split(str, c);
// 	for (int i = 0; expected[i]; i++)
// 	{
// 		if (expected[i] != NULL)
// 			printf("%s", expected[i]);
// 	}
// 	// while (result[i])
// 	// {
// 	// 	free(result[i]);
// 	// 	i++;
// 	// }
// 	// free(result);
// 	return (0);
// }
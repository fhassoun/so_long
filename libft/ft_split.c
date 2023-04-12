/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 07:30:32 by fhassoun          #+#    #+#             */
/*   Updated: 2022/12/10 07:45:10 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static size_t	get_substr_count(char const *str, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*get_substr(char *substr, char const *s, int i, int substr_len)
{
	int	j;

	j = 0;
	while (substr_len > 0)
	{
		substr[j] = s[i - substr_len];
		j++;
		substr_len--;
	}
	substr[j] = '\0';
	return (substr);
}

static char	**alloc_substr(char const *s, char c, char **res, size_t count)
{
	size_t	substr;
	int		i;
	int		substr_len;

	i = 0;
	substr = 0;
	substr_len = 0;
	while (substr < count)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			substr_len++;
		}
		res[substr] = (char *)malloc(sizeof(char) * (substr_len + 1));
		if (!res)
			return (NULL);
		get_substr(res[substr], s, i, substr_len);
		substr_len = 0;
		substr++;
	}
	res[substr] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;

	if (!s)
		return (NULL);
	count = get_substr_count(s, c);
	res = malloc(sizeof(*res) * (count + 1));
	if (!res)
		return (NULL);
	res = alloc_substr(s, c, res, count);
	return (res);
}
/*
int	main(void)
{
	char	**res;
	int		i;
	//char    str[] = "1aaaabc22aabc333abc4444abc55555abc666666";
	char	chr = ' ';

	i = 0;
	res = ft_split(str, chr);
	
	while (*res[i] != '\0')
	{
		ft_putstr_fd(res[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	i = 0;
	while (i < ((get_substr_count(str, chr) + 1)))
	{
		free(res[i]);
		i++;
	}
	free(res);
	
	return (0);
}

*/

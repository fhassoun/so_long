/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:20:05 by fhassoun          #+#    #+#             */
/*   Updated: 2022/12/09 09:52:26 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buf;

	i = 0;
	if (ft_strlen(s) < start)
	{
		buf = malloc(sizeof(char));
		if (!buf)
			return (NULL);
	}
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		buf = malloc (sizeof(*buf) * (len + 1));
		if (!buf)
			return (NULL);
		while (i < len && s[start] != '\0')
			buf[i++] = s[start++];
	}
	buf[i] = '\0';
	return (buf);
}

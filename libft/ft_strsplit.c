/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:13:20 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/28 15:22:03 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_settab(const char *s, char c)
{
	char		**p;
	int			i;
	int			n;
	int			j;

	i = 0;
	j = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && j == 0)
		{
			n++;
			j++;
		}
		if (s[i] == c)
			j = 0;
		i++;
	}
	p = malloc(sizeof(char *) * (n + 1));
	p[n] = NULL;
	return (p);
}

static	char	*ft_cut(size_t beg, size_t end, char const *s)
{
	char		*r;
	size_t		i;

	i = 0;
	r = ft_strnew(end - beg);
	while (beg < end)
	{
		r[i] = s[beg];
		i++;
		beg++;
	}
	return (r);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**p;
	size_t		i;
	size_t		j;
	int			l;

	if (s == NULL)
		return (NULL);
	l = 0;
	i = 0;
	p = ft_settab(s, c);
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		if (s[i])
			p[l++] = ft_cut(i, j, s);
		while (s[i] != c && s[i])
			i++;
	}
	return (p);
}

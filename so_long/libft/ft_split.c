/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:02:21 by rabdel-f          #+#    #+#             */
/*   Updated: 2024/06/19 13:06:10 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(const char *str, char c)
{
	size_t	i;
	int		count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (in_word)
			{
				count++;
				in_word = 0;
			}
		}
		else
			in_word = 1;
		i++;
	}
	if (in_word)
		count++;
	return (count);
}

static	void	do_split(char **list, const char *str, char c)
{
	char	*word_start;
	char	*ptr;
	int		i;
	int		word_length;

	i = 0;
	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr != c)
		{
			word_start = ptr;
			while (*ptr && *ptr != c)
				ptr++;
			word_length = ptr - word_start + 1;
			list[i] = (char *)malloc(word_length);
			ft_strlcpy(list[i], word_start, word_length);
			i++;
		}
		else
			ptr++;
	}
	list[i] = NULL;
}

char	**ft_split(const char *str, char c)
{
	char	**list;

	list = (char **)malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	do_split (list, str, c);
	return (list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:40:40 by rabdel-f          #+#    #+#             */
/*   Updated: 2024/06/19 13:48:12 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buffer, int ch, size_t n)
{
	const char	*str;

	str = buffer;
	while (n-- > 0)
	{
		if (*(unsigned char *)str == (unsigned char)ch)
			return ((void *)str);
		str++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:13:43 by rabdel-f          #+#    #+#             */
/*   Updated: 2024/06/20 13:59:19 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

void	ft_putcharacter_length(char character, int *length);
void	ft_string(char *args, int *length);
void	ft_number(int number, int *length);
void	ft_pointer(size_t pointer, int *length);
void	ft_hexadecimal(unsigned int x, int *length, char x_or_X);
void	ft_unsigned_int(unsigned int u, int *length);
int		ft_printf(const char *string, ...);
#endif
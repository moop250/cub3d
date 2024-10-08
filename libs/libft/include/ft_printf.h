/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:30:32 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/01 20:31:54 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_handle_specifier(const char f, va_list args);
int	ft_handle_char(va_list args);
int	ft_handle_str(va_list args);
int	ft_handle_int(int n);
int	ft_handle_uint(unsigned int n);
int	ft_handle_hex(va_list args, int is_upper);
int	ft_handle_ptr(va_list args);
int	ft_handle_percent(void);
int	ft_putchar(int c);
int	ft_putstr(const char *str);
int	ft_str_length(char *str);
int	ft_isformatspecifier(const char f);

#endif

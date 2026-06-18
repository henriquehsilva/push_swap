/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:32:11 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/18 08:44:42 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* *************************************** */
/* External Libraries                      */
/* *************************************** */

# include "../libft/libft.h"
# include <stdarg.h>
# include <stddef.h>

/* *************************************** */
/* Function list                           */
/* *************************************** */

int		ft_printf(const char *format, ...);
int		handle_conversion(char specifier, va_list *args);
int		ft_putnbr_base_fd(unsigned long long n, char *base, int fd);
int		ft_putnbr_count(int n);

#endif

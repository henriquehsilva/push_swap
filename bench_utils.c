/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:02:27 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/02 12:02:33 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_str(const char *s)
{
	write(2, s, ft_strlen(s));
}

void	put_int(int n)
{
	char	*s;

	s = ft_itoa(n);
	if (!s)
		return ;
	write(2, s, ft_strlen(s));
	free(s);
}

void	put_percent(double ratio)
{
	int	scaled;
	int	whole;
	int	frac;

	scaled = (int)(ratio * 10000.0 + 0.5);
	whole = scaled / 100;
	frac = scaled % 100;
	put_int(whole);
	put_str(".");
	if (frac < 10)
		put_str("0");
	put_int(frac);
	put_str("%\n");
}

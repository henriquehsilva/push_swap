/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:01:55 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/02 12:02:01 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stats	*get_stats(void)
{
	static t_stats	stats;

	return (&stats);
}

void	stats_reset(void)
{
	ft_bzero(get_stats(), sizeof(t_stats));
}

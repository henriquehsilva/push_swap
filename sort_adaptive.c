/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbelas <marbelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:17:18 by marbelas          #+#    #+#             */
/*   Updated: 2026/07/11 11:45:35 by marbelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack *a, t_stack *b)
{
	double	disorder;

	if (is_sorted(a))
		return ;
	disorder = compute_disorder(a);
	if (disorder < DISORDER_LOW)
		sort_simple(a, b);
	else if (disorder < DISORDER_MED)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}

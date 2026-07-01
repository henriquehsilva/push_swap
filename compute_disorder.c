/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbelas <marbelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:27:42 by marbelas          #+#    #+#             */
/*   Updated: 2026/07/01 18:46:09 by marbelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		mistakes;
	int		total_pairs;

	i = a->top;
	j = i->next;
	mistakes = 0;
	total_pairs = 0;
	if (!a || a->size < 2)
		return (0.0);
	while (i)
	{
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
			mistakes++;
		j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / (double)total_pairs);
}

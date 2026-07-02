/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbelas <marbelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:04:23 by marbelas          #+#    #+#             */
/*   Updated: 2026/07/02 07:32:52 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, t_stack *b)
{
	(void)b;
	int	node_1;
	int	node_2;
	int	node_3;

	node_1 = a->top->value;
	node_2 = a->top->next->value;
	node_3 = a->top->next->next->value;
	//213
	if (node_1 > node_2 && node_2 < node_3 && node_1 < node_3)
		sa(a);
	//321
	else if (node_1 > node_2 && node_2 > node_3)
	{
		sa(a);
		rra(a);
	}
	//312
	else if (node_1 > node_2 && node_1 > node_3)
		ra(a);
	//231
	else if (node_1 < node_2 && node_2 > node_3 && node_1 > node_3)
		rra(a);
	//132
	else if (node_1 < node_2 && node_2 > node_3 && node_1 < node_3)
	{
		sa(a);
		ra(a);
	}
}

void	sort_simple(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a, b);
}

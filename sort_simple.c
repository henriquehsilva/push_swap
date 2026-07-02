/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbelas <marbelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:04:23 by marbelas          #+#    #+#             */
/*   Updated: 2026/07/02 10:20:35 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, t_stack *b)
{
	int	node_1;
	int	node_2;
	int	node_3;

	(void)b;
	node_1 = a->top->value;
	node_2 = a->top->next->value;
	node_3 = a->top->next->next->value;
	if (node_1 > node_2 && node_2 < node_3 && node_1 < node_3)
		sa(a);
	else if (node_1 > node_2 && node_2 > node_3)
	{
		sa(a);
		rra(a);
	}
	else if (node_1 > node_2 && node_1 > node_3)
		ra(a);
	else if (node_1 < node_2 && node_2 > node_3 && node_1 > node_3)
		rra(a);
	else if (node_1 < node_2 && node_2 > node_3 && node_1 < node_3)
	{
		sa(a);
		ra(a);
	}
}

static int	min_index(t_stack *a)
{
	t_node	*node;
	int		min_val;
	int		min_idx;
	int		idx;

	node = a->top;
	min_val = node->value;
	min_idx = 0;
	idx = 0;
	while (node)
	{
		if (node->value < min_val)
		{
			min_val = node->value;
			min_idx = idx;
		}
		node = node->next;
		idx++;
	}
	return (min_idx);
}

static void	rotate_to_top(t_stack *a, int idx)
{
	int	i;

	i = 0;
	if (idx <= a->size - idx)
	{
		while (i < idx)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < a->size - idx)
		{
			rra(a);
			i++;
		}
	}
}

void	sort_simple(t_stack *a, t_stack *b)
{
	int	idx;

	if (is_sorted(a))
		return ;
	if (a->size == 2)
	{
		sa(a);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a, b);
		return ;
	}
	while (a->size > 0)
	{
		idx = min_index(a);
		rotate_to_top(a, idx);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbelas <marbelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:25:25 by marbelas          #+#    #+#             */
/*   Updated: 2026/07/11 13:29:46 by marbelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pos(t_stack *b, int target)
{
	int		i;
	t_node	*tmp;

	tmp = b->top;
	i = 0;
	while (tmp->value != target)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	push_a(t_stack *a, t_stack *b)
{
	int	position;
	int	target;

	target = b->size - 1;
	while (b->size > 0)
	{
		if (b->top && b->top->value == target - 1)
		{
			pa(a, b);
			target--;
			if (b->size == 0)
				break ;
		}
		position = get_pos(b, target);
		if (position <= b->size / 2)
			while (b->top->value != target)
				rb(b);
		else
			while (b->top->value != target)
				rrb(b);
		pa(a, b);
		if (a->size > 1 && a->top->value > a->top->next->value)
			sa(a);
		target--;
	}
}

static void	push_logic(t_stack *a, t_stack *b, int *i, int chunk)
{
	if (a->top->value <= *i)
	{
		pb(a, b);
		if (a->top && a->top->value > (*i + chunk))
			rr(a, b);
		else
			rb(b);
		(*i)++;
	}
	else if (a->top->value <= *i + chunk)
	{
		pb(a, b);
		(*i)++;
	}
	else
		ra(a);
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	chunk;
	int	i;
	
	if (is_sorted(a))
		return ;
	i = 0;
	chunk = ft_sqrt(a->size);
	while (a->top)
		push_logic(a, b, &i, chunk);
	push_a(a, b);
}

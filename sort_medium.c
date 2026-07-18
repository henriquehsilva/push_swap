/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:25:25 by marbelas          #+#    #+#             */
/*   Updated: 2026/07/18 09:13:25 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, t_stack *b);

static int	get_pos(t_stack *b, int target)
{
	int		i;
	t_node	*tmp;

	tmp = b->top;
	i = 0;
	while (tmp->value != target)
	{
		tmp = tmp->next;
		i++;
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
		if (b->top && b->top->value == target)
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

static void	check_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2 && !is_sorted(a))
		ra(a);
	else if (a->size == 3)
		sort_three(a, b);
	return ;
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	chunk;
	int	i;

	if (is_sorted(a))
		return ;
	i = 0;
	chunk = ft_sqrt(a->size);
	check_sort(a, b);
	while (a->top)
	{
		push_logic(a, b, &i, chunk);
		i++;
	}
	push_a(a, b);
}

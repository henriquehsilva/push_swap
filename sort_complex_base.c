/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 07:58:56 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/04 08:09:17 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pivot(t_stack *s, int size)
{
	t_node	*mid;
	int		i;

	mid = s->top;
	i = 0;
	while (i < size / 2)
	{
		mid = mid->next;
		i++;
	}
	if ((s->top->value > mid->value) != (s->top->value > s->bottom->value))
		return (s->top->value);
	else if ((mid->value > s->top->value) != (mid->value > s->bottom->value))
		return (mid->value);
	return (s->bottom->value);
}

int	partition(t_stack *active, t_stack *aux, int size, int mode)
{
	int	is_a;
	int	desc;
	int	pivot;
	int	moved;
	int	i;

	is_a = mode & QS_A;
	desc = mode & QS_DESC;
	pivot = get_pivot(active, size);
	moved = 0;
	i = 0;
	while (i < size)
	{
		if ((!desc && active->top->value < pivot)
			|| (desc && active->top->value >= pivot))
		{
			op_push(active, aux, is_a);
			moved++;
		}
		else
			op_rotate(active, is_a);
		i++;
	}
	return (moved);
}

void	sort_two(t_stack *active, int mode)
{
	int	desc;

	desc = mode & QS_DESC;
	if (!desc && active->top->value > active->top->next->value)
		op_swap(active, mode & QS_A);
	else if (desc && active->top->value < active->top->next->value)
		op_swap(active, mode & QS_A);
}

static void	apply_three_case(t_stack *active, int is_a, int n[3])
{
	if (n[0] > n[1] && n[1] < n[2] && n[0] < n[2])
		op_swap(active, is_a);
	else if (n[0] > n[1] && n[1] > n[2])
	{
		op_swap(active, is_a);
		op_reverse_rotate(active, is_a);
	}
	else if (n[0] > n[1] && n[0] > n[2])
		op_rotate(active, is_a);
	else if (n[0] < n[1] && n[1] > n[2] && n[0] > n[2])
		op_reverse_rotate(active, is_a);
	else if (n[0] < n[1] && n[1] > n[2] && n[0] < n[2])
	{
		op_swap(active, is_a);
		op_rotate(active, is_a);
	}
}

void	sort_three_generic(t_stack *active, int mode)
{
	int	n[3];

	n[0] = active->top->value;
	n[1] = active->top->next->value;
	n[2] = active->top->next->next->value;
	if (mode & QS_DESC)
	{
		n[0] = -n[0];
		n[1] = -n[1];
		n[2] = -n[2];
	}
	apply_three_case(active, mode & QS_A, n);
}

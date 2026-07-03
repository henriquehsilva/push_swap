/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:37:50 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/03 06:32:37 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	s->top = second;
	if (s->bottom == first)
		s->bottom = first;
}

void	sa(t_stack *a)
{
	swap(a);
	get_stats()->sa++;
	get_stats()->total++;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	get_stats()->sb++;
	get_stats()->total++;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	get_stats()->ss++;
	get_stats()->total++;
	write(1, "ss\n", 3);
}

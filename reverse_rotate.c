/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 08:18:37 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/03 06:50:53 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	reverse_rotate(t_stack *s)
{
	t_node	*old_bottom;

	if (!s || s->size < 2)
		return ;
	old_bottom = s->bottom;
	s->bottom = old_bottom->prev;
	s->bottom->next = NULL;
	old_bottom->prev = NULL;
	old_bottom->next = s->top;
	s->top->prev = old_bottom;
	s->top = old_bottom;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	get_stats()->rra++;
	get_stats()->total++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	get_stats()->rrb++;
	get_stats()->total++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	get_stats()->rrr++;
	get_stats()->total++;
	write(1, "rrr\n", 4);
}

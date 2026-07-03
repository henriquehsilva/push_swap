/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 08:01:52 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/03 06:50:19 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	t_node	*old_top;

	if (!s || s->size < 2)
		return ;
	old_top = s->top;
	s->top = old_top->next;
	s->top->prev = NULL;
	old_top->next = NULL;
	old_top->prev = s->bottom;
	s->bottom->next = old_top;
	s->bottom = old_top;
}

void	ra(t_stack *a)
{
	rotate(a);
	get_stats()->ra++;
	get_stats()->total++;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	get_stats()->rb++;
	get_stats()->total++;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	get_stats()->rr++;
	get_stats()->total++;
	write(1, "rr\n", 3);
}

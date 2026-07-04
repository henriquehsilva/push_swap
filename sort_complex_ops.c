/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 07:57:35 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/04 07:57:54 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(t_stack *active, int is_a)
{
	if (is_a)
		sa(active);
	else
		sb(active);
}

void	op_rotate(t_stack *active, int is_a)
{
	if (is_a)
		ra(active);
	else
		rb(active);
}

void	op_reverse_rotate(t_stack *active, int is_a)
{
	if (is_a)
		rra(active);
	else
		rrb(active);
}

void	op_push(t_stack *active, t_stack *aux, int is_a)
{
	if (is_a)
		pb(active, aux);
	else
		pa(aux, active);
}

void	op_push_back(t_stack *active, t_stack *aux, int is_a)
{
	if (is_a)
		pa(active, aux);
	else
		pb(aux, active);
}

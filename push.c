/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 07:53:36 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/19 07:59:49 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push(t_stack *s)
{
	if (!s || s->size < 2)
		return ;
}

void	pa(t_stack *a)
{
	push(a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *b)
{
	push(b);
	write(1, "pb\n", 3);
}

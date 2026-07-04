/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 08:00:08 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/04 08:13:46 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_base_case(t_stack *active, int size, int mode)
{
	if (size <= 1)
		return (1);
	if (size == 2)
	{
		sort_two(active, mode);
		return (1);
	}
	if (size == 3)
	{
		sort_three_generic(active, mode);
		return (1);
	}
	return (0);
}

static void	quicksort(t_stack *active, t_stack *aux, int size, int mode)
{
	int	moved;
	int	is_a;
	int	child_mode;

	if (handle_base_case(active, size, mode))
		return ;
	is_a = mode & QS_A;
	moved = partition(active, aux, size, mode);
	child_mode = 0;
	if (!is_a)
		child_mode |= QS_A;
	if (!(mode & QS_DESC))
		child_mode |= QS_DESC;
	quicksort(active, aux, size - moved, mode);
	quicksort(aux, active, moved, child_mode);
	while (moved-- > 0)
		op_push_back(active, aux, is_a);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	quicksort(a, b, a->size, QS_A);
}

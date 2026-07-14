/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbelas <marbelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 18:55:05 by marbelas          #+#    #+#             */
/*   Updated: 2026/07/14 19:11:21 by marbelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	get_rank(int value, int *sorted, int size)
{
	int	i;

	i = 0;
	while (i < size && sorted[i] != value)
		i++;
	return (i);
}

void	normalize_stack(t_stack *a)
{
	int		*sorted;
	t_node	*tmp;
	int		size;
	int		i;

	size = a->size;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return ;
	tmp = a->top;
	i = 0;
	while (tmp)
	{
		sorted[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_int_array(sorted, size);
	tmp = a->top;
	while (tmp)
	{
		tmp->value = get_rank(tmp->value, sorted, size);
		tmp = tmp->next;
	}
	free(sorted);
}

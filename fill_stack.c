/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 08:34:53 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/18 08:35:30 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	valid_number(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	parse_int(const char *s, int *out)
{
	long	n;
	int		i;
	int		sign;

	if (!valid_number(s))
		return (1);
	sign = 1;
	i = 0;
	n = 0;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		n = n * 10 + (s[i++] - '0');
		if (n > (long)INT_MAX + 1)
			return (1);
	}
	n = n * sign;
	if (n > INT_MAX || n < INT_MIN)
		return (1);
	*out = (int)n;
	return (0);
}

static int	has_value(t_stack *s, int value)
{
	t_node	*node;

	node = s->top;
	while (node)
	{
		if (node->value == value)
			return (1);
		node = node->next;
	}
	return (0);
}

int	fill_stack(int argc, char **argv, int start, t_stack *a)
{
	int	i;
	int	value;

	i = start;
	while (i < argc)
	{
		if (parse_int(argv[i], &value) != 0)
			return (1);
		if (has_value(a, value))
			return (1);
		if (stack_append(a, value) != 0)
			return (1);
		i++;
	}
	return (0);
}

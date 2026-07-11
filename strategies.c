/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbelas <marbelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 06:57:47 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/11 13:23:42 by marbelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_stack *a, t_stack *b);
void	sort_medium(t_stack *a, t_stack *b);
void	sort_complex(t_stack *a, t_stack *b);
void	sort_adaptive(t_stack *a, t_stack *b);

static const t_strategy	*get_strategies(void)
{
	static const t_strategy	strategies[] = {
	{"--simple", "Simple", "O(n^2)", sort_simple},
	{"--medium", "Medium", "0(n_ft_sqrt n)", sort_medium},
	{"--complex", "Complex", "O(n log n)", sort_complex},
	{"--adaptive", "Adaptive", "0(n^2), 0(n_sqrt n), O(n log n)", sort_adaptive},
	{NULL, NULL, NULL, NULL}
	};

	return (strategies);
}

const t_strategy	*get_default_strategy(void)
{
	return (&get_strategies()[3]);
}

const t_strategy	*find_strategy(const char *flag)
{
	const t_strategy	*strategies;
	int					i;

	strategies = get_strategies();
	i = 0;
	while (strategies[i].flag)
	{
		if (ft_strncmp(flag, strategies[i].flag,
				ft_strlen(strategies[i].flag) + 1) == 0)
			return (&strategies[i]);
		i++;
	}
	return (NULL);
}

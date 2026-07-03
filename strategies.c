/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 06:57:47 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/03 08:17:43 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_stack *a, t_stack *b);

static const t_strategy	*get_strategies(void)
{
	static const t_strategy	strategies[] = {
	{"--simple", "Simple", "O(n^2)", sort_simple},
	{NULL, NULL, NULL, NULL}
	};

	return (strategies);
}

const t_strategy	*get_default_strategy(void)
{
	return (&get_strategies()[0]);
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

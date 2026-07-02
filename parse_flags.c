/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 08:39:04 by hhonorio          #+#    #+#             */
/*   Updated: 2026/07/02 07:03:45 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_flags(int argc, char **argv, t_opts *opts, int *operands)
{
	int	i;

	i = 1;
	while (i < argc && ft_strncmp(argv[i], "--", 2) == 0)
	{
		opts->strategy = find_strategy(argv[i]);
		if (!opts->strategy)
			return (1);
		i++;
	}
	if (!opts->strategy)
		opts->strategy = get_default_strategy();
	*operands = i;
	return (0);
}

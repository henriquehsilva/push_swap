/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 08:33:27 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/18 08:34:27 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args(int argc, char **argv, t_opts *opts, t_stack *a)
{
	int	operands;

	if (parse_flags(argc, argv, opts, &operands) != 0)
		return (1);
	if (fill_stack(argc, argv, operands, a) != 0)
		return (1);
	normalize_stack(a);
	return (0);
}

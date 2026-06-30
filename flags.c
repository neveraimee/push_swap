/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:44:02 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/29 18:22:32 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_flags(int ac, char **av, t_opts *opts, t_clean *data)
{
	int		i;
	t_stack	*a;
	t_bench	*bench;

	a = data->a;
	bench = data->bench;
	i = 0;
	while (++i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		if (!ft_strcmp("--bench", av[i]))
			opts->bench = 1;
		else if (!ft_strcmp("--adaptive", av[i]))
			opts->strategy = ADAPTIVE;
		else if (!ft_strcmp("--simple", av[i]))
			opts->strategy = SIMPLE;
		else if (!ft_strcmp("--medium", av[i]))
			opts->strategy = MEDIUM;
		else if (!ft_strcmp("--complex", av[i]))
			opts->strategy = COMPLEX;
		else
			exit_error(NULL, bench, a);
		if ((i == 3 && opts->bench == 0) || i == 4)
			exit_error(NULL, bench, a);
	}
}

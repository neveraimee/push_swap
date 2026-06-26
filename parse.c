/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:44:28 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/26 18:08:49 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**avtoarray(int ac, char **av)
{
	int		i;
	int		j;
	char	**array;

	i = 1;
	j = 0;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
		i++;
	if (ac == i + 1)
		array = split(av[i]);
	else
	{
		array = malloc(sizeof(char *) * (ac - i + 1));
		if (!array)
			return (NULL);
		while (i < ac)
		{
			array[j] = ft_strdup(av[i]);
			i++;
			j++;
		}
		array[j] = NULL;
	}
	return (array);
}

void	exit_error(char **array, t_bench *bench, t_stack *a)
{
	if (array)
	{
		freeit(array);
	}
	stack_free(a);
	free(bench);
	write(2, "Error\n", 6);
	exit(1);
}

void	isvalid(char **array, t_bench *bench)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		if (array[i][j] == '-' || array[i][j] == '+')
			j++;
		if (!array[i][j])
			exit_error(array, bench, NULL);
		while (array[i][j])
		{
			if (!ft_isdigit(array[i][j]))
				exit_error(array, bench, NULL);
			j++;
		}
		i++;
	}
	return ;
}

void	isdouble(char **array, t_bench *bench)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i + 1])
	{
		j = i + 1;
		while (array[j])
		{
			if (!ft_strcmp(array[i], array[j]))
				exit_error(array, bench, NULL);
			j++;
		}
		i++;
	}
}

t_stack	*parse_args(int ac, char **av, t_bench *bench)
{
	char	**array;
	t_stack	*stack;

	stack = NULL;
	if (ac < 2)
		return (NULL);
	array = avtoarray(ac, av);
	if (!array)
		return (NULL);
	if (!array[0])
		exit_error(array, bench, NULL);
	isdouble(array, bench);
	isvalid(array, bench);
	stack = create_stack(array, bench);
	freeit(array);
	return (stack);
}

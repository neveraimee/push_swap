/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:26:28 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/25 21:25:47 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	char	*set;
	int		i;

	set = " \f\n\r\t\v";
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]))
			i++;
		if (s[i] && !ft_isspace(s[i]))
			count++;
		while (s[i] && !ft_isspace(s[i]))
			i++;
	}
	return (count);
}

static void	free_on_error(char **array, int index)
{
	if (index == 0)
	{
		free(array);
		return ;
	}
	while (index > 0)
	{
		index--;
		free(array[index]);
	}
	free(array);
}

static void	allocate_str(char const *s, char **array, int index)
{
	int				i;
	unsigned int	start;
	size_t			sublen;

	i = 0;
	start = 0;
	while (s[i])
	{
		sublen = 0;
		while (ft_isspace(s[i]))
			i++;
		if (s[i] && !ft_isspace(s[i]))
		{
			start = i;
			while (s[i] != '\0' && !ft_isspace(s[i]))
			{
				sublen++;
				i++;
			}
			array[index] = ft_substr(s, start, sublen);
			if (!array[index])
				return (free_on_error(array, index));
			index++;
		}
	}
}

char	**split(char const *s)
{
	int		words;
	char	**array;

	if (!s)
		return (NULL);
	words = count_words(s);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	if (words == 0)
	{
		array[0] = NULL;
		return (array);
	}
	allocate_str(s, array, 0);
	array[words] = NULL;
	return (array);
}

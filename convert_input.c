/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:06:18 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/18 11:33:56 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_tab(char **retour, char **argv)
{
	int		i;
	int		j;
	int		index;
	char	**current;

	i = 1;
	index = 0;
	while (argv[i])
	{
		current = ft_split(argv[i], ' ');
		j = 0;
		while (current[j])
		{
			retour[index] = current[j];
			j++;
			index++;
		}
		free(current);
		i++;
	}
	retour[index] = NULL;
	return ;
}

char	**create_tab(char **argv)
{
	int		i;
	int		count;
	char	**retour;

	i = 0;
	count = 0;
	while (argv[i])
	{
		count = count + count_w(argv[i], ' ');
		i++;
	}
	retour = (char **) malloc (sizeof(char *) * (count + 1));
	if (!retour)
		return (NULL);
	fill_tab(retour, argv);
	return (retour);
}

t_list	*create_list(char **tab)
{
	int		i;
	t_list	*start;

	start = ft_lstnew(tab[0]);
	i = 1;
	while (tab[i])
	{
		ft_lstadd_back(&start, ft_lstnew(tab[i]));
		i++;
	}
	return (start);
}

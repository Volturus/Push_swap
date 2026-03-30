/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:23:06 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/13 16:37:45 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*test(int len, t_list *lst, t_list *median_test, t_list *start)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (ft_atoi(lst->content) < ft_atoi(median_test->content))
			count++;
		lst = lst->next;
		i++;
	}
	lst = start;
	if (len % 2 == 0)
	{
		if (count == (len / 2) - 1)
			return (median_test);
	}
	else
	{
		if (count == (len / 2))
			return (median_test);
	}
	return (NULL);
}

t_list	*find_median(t_list *lst, int len)
{
	int		i;
	int		j;
	t_list	*retour;
	t_list	*median_test;
	t_list	*start;

	j = 0;
	start = lst;
	while (j < len)
	{
		i = 0;
		while (i < j)
		{
			lst = lst->next;
			i++;
		}
		median_test = lst;
		lst = start;
		retour = test(len, lst, median_test, start);
		if (retour != NULL)
			return (retour);
		j++;
	}
	return (NULL);
}

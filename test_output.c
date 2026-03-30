/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:46:31 by vmourey           #+#    #+#             */
/*   Updated: 2026/02/25 14:27:01 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	int	last;

	last = ft_atoi(lst->content);
	lst = lst->next;
	while (lst != NULL)
	{
		if (ft_atoi(lst->content) < last)
			return (1);
		last = ft_atoi(lst->content);
		lst = lst->next;
	}
	return (0);
}

int	is_sorted_len(t_list *lst, int len)
{
	int	last;
	int	i;

	last = ft_atoi(lst->content);
	lst = lst->next;
	i = 1;
	while (lst != NULL && i <= len)
	{
		if (ft_atoi(lst->content) < last)
			return (1);
		last = ft_atoi(lst->content);
		lst = lst->next;
		i++;
	}
	return (0);
}

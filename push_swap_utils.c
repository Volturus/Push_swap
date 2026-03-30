/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:04:06 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/18 14:20:01 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_elem_i(t_list *lst, int len)
{
	int	i;

	i = 0;
	if (!lst)
		return (NULL);
	while (lst->next != NULL && i < len)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

int	count_w(const char *s, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*s)
	{
		if (*s != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*s == c)
			x = 0;
		s++;
	}
	return (count);
}

t_list	*find_min1_lst(t_list *searched, t_list *start)
{
	t_list	*lst;
	t_list	*lstmin1;

	lst = start->next;
	lstmin1 = start;
	while (lst != searched)
	{
		lst = lst->next;
		lstmin1 = lstmin1->next;
	}
	return (lstmin1);
}

int	find_int_lst(t_list *searched, t_list *start)
{
	t_list	*lst;
	int		i;

	lst = start;
	i = 1;
	while (lst != searched)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

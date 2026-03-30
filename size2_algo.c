/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size2_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:32:42 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/13 16:12:46 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*size2_algo(t_list *lst, int current_len)
{
	char	*tmp;

	if (is_sorted_len(lst, 2) == 0)
		return (lst);
	else
	{
		tmp = lst->content;
		lst->content = (lst->next)->content;
		(lst->next)->content = tmp;
	}
	move_to_place(1 + current_len - 2, current_len);
	ft_printf("sa\n");
	return (lst);
}

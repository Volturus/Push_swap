/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size2_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:57:06 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/24 12:10:51 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*size2_helper(t_list *start, int total_len, int iteration_start)
{
	char	*tmp;

	if (is_sorted_len(start, 2) == 0)
		return (start);
	else
	{
		tmp = start->content;
		start->content = (start->next)->content;
		(start->next)->content = tmp;
	}
	move_to_place(iteration_start, total_len);
	ft_printf("sa\n");
	return (start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size4_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:45:00 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/27 13:50:36 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	condition1(t_list *start, int current_len)
{
	t_list	*tmp;

	tmp = ((start->next)->next);
	(start->next)->next = start;
	start->next = tmp;
	move_to_place(2 + current_len - 4, current_len - 1);
	ft_printf("pa\n");
}

static void	size4part2(t_list *start, int current_len)
{
	t_list	*tmp;

	if (ft_atoi(start->content) > ft_atoi((start->next)->content) \
&& ft_atoi(start->content) < ft_atoi(((start->next)->next)->content))
		condition1(start, current_len);
	else if (ft_atoi(start->content) \
> ft_atoi((((start->next)->next)->next)->content))
	{
		tmp = (((start->next)->next)->next)->next;
		(((start->next)->next)->next)->next = start;
		start->next = tmp;
		move_to_place(1 + current_len - 4, current_len - 1);
		ft_printf("pa\nra\n");
	}
	else
	{
		tmp = ((start->next)->next)->next;
		((start->next)->next)->next = start;
		start->next = tmp;
		move_to_place(3 + current_len - 4, current_len - 1);
		ft_printf("pa\n");
	}
}

t_list	*size4_algo(t_list *start, t_list *startmin1, int current_len)
{
	t_list	*retour;

	if (is_sorted_len(start, 4) == 0)
		return (start);
	move_to_place(1 + current_len - 4, current_len);
	ft_printf("pb\n");
	if (is_sorted_len(start->next, 3) == 1)
	{
		move_to_place(1 + current_len - 4, current_len - 1);
		size3_algo(start->next, start, current_len - 1);
	}
	if (is_sorted_len(start, 4) == 0)
	{
		move_to_place(1 + current_len - 4, current_len);
		ft_printf("pa\n");
		return (start);
	}
	retour = start->next;
	if (startmin1 != NULL)
		startmin1->next = start->next;
	size4part2(start, current_len);
	return (retour);
}

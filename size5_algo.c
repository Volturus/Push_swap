/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size5_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:36:15 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/27 14:18:31 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	condition1(t_list *start)
{
	t_list	*tmp;

	tmp = ((start->next)->next);
	(start->next)->next = start;
	start->next = tmp;
	move_to_place(2, 4);
	ft_printf("pa\n");
}

static void	condition2(t_list *start)
{
	t_list	*tmp;

	tmp = (((start->next)->next)->next);
	(((start->next)->next)->next) = start;
	start->next = tmp;
	move_to_place(3, 4);
	ft_printf("pa\n");
}

static void	size5part2(t_list *start)
{
	t_list	*tmp;

	if (ft_atoi(start->content) > ft_atoi((start->next)->content) \
&& ft_atoi(start->content) < ft_atoi(((start->next)->next)->content))
		condition1(start);
	else if (ft_atoi(start->content) > ft_atoi(((start->next)->next)->content) \
&& ft_atoi(start->content) < ft_atoi((((start->next)->next)->next)->content))
		condition2(start);
	else if (ft_atoi(start->content) > \
ft_atoi((((start->next)->next)->next)->content) \
&& ft_atoi(start->content) < \
ft_atoi(((((start->next)->next)->next)->next)->content))
	{
		tmp = ((((start->next)->next)->next)->next);
		((((start->next)->next)->next)->next) = start;
		start->next = tmp;
		move_to_place(4, 4);
		ft_printf("pa\n");
	}
	else
	{
		tmp = (((((start->next)->next)->next)->next)->next);
		(((((start->next)->next)->next)->next)->next) = start;
		start->next = tmp;
		move_to_place(1, 5);
		ft_printf("pa\n");
		ft_printf("ra\n");
	}
}

t_list	*size5_algo(t_list *start, t_list *startmin1)
{
	t_list	*retour;

	if (is_sorted_len(start, 5) == 0)
		return (start);
	move_to_place(1, 5);
	ft_printf("pb\n");
	if (is_sorted_len(start->next, 4) == 1)
	{
		move_to_place(1, 5);
		size4_algo(start->next, start, 4);
	}
	if (is_sorted_len(start, 5) == 0)
	{
		move_to_place(1, 5);
		ft_printf("pa\n");
		return (start);
	}
	if (startmin1 != NULL)
		startmin1->next = start->next;
	retour = start->next;
	size5part2(start);
	return (retour);
}

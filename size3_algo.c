/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size3_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:33:07 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/27 13:24:19 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*condition1(t_list *start, t_list *startmin1)
{
	t_list	*retour;
	t_list	*tmp;

	retour = (start->next)->next;
	if (startmin1 != NULL)
		startmin1->next = (start->next)->next;
	tmp = retour->next;
	retour->next = start;
	(start->next)->next = tmp;
	ft_printf("rra\n");
	return (retour);
}

static void	condition2(t_list *lst, t_list *start)
{
	t_list	*tmp;

	tmp = lst->next;
	lst->next = start;
	start->next = tmp;
	ft_printf("ra\n");
}

static void	condition3(t_list *start, t_list *lst, int current_len)
{
	(start->next)->next = start;
	start->next = lst;
	move_to_place(1 + current_len - 3, current_len);
	ft_printf("pb\n");
	move_to_place(2 + current_len - 3, current_len - 1);
	ft_printf("pa\n");
}

static t_list	*condition4(int current_len)
{
	move_to_place(2, current_len);
	ft_printf("sa\n");
	return (NULL);
}

t_list	*size3_algo(t_list *start, t_list *startmin1, int current_len)
{
	t_list	*lst;
	t_list	*retour;

	lst = (start->next)->next;
	if (is_sorted_len(start, 3) == 0)
		return (start);
	if (ft_atoi(start->content) > ft_atoi(((start->next)->next)->content) \
&& ft_atoi(start->content) < ft_atoi((start->next)->content))
		return (condition1(start, startmin1));
	if (ft_atoi(start->next->content) > ft_atoi(((start->next)->next)->content) \
&& ft_atoi(start->next->content) < ft_atoi(start->content) && startmin1 == NULL)
		return (condition4(current_len));
	if (is_sorted_len(start->next, 2) == 1)
		size2_algo(start->next, current_len);
	if (is_sorted_len(start, 3) == 0)
		return (start);
	retour = start->next;
	if (startmin1 != NULL)
		startmin1->next = start->next;
	if (ft_atoi(start->content) > ft_atoi(lst->content))
		condition2(lst, start);
	else
		condition3(start, lst, current_len);
	return (retour);
}

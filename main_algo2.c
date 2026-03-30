/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:34:47 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/18 11:34:47 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*main_condition(t_list *cursor, t_list *pile_b, \
int arg1_move, int arg2_move)
{
	t_list	*tmp;

	move_to_place(arg1_move, arg2_move);
	tmp = cursor->next;
	cursor->next = (cursor->next)->next;
	if (pile_b != NULL)
		ft_lstadd_back(&pile_b, tmp);
	else
		pile_b = tmp;
	tmp->next = NULL;
	ft_printf("pb\n");
	return (pile_b);
}

static t_list	*manage_pivot(t_list *pile_b, t_list *pivotmin1, \
int arg1_move, int arg2_move)
{
	t_list	*pivot;

	move_to_place(arg1_move, arg2_move);
	pivot = pivotmin1->next;
	pivotmin1->next = pivot->next;
	ft_printf("pb\n");
	if (pile_b != NULL)
		ft_lstadd_back(&pile_b, pivot);
	else
		pile_b = pivot;
	pivot->next = NULL;
	return (pile_b);
}

t_list	*store_into_pile_b(int i, t_list *start, int iteration_start, int len)
{
	static int	total_size;
	int			int_pivot;
	t_list		*pile_b;
	t_list		*pivot;

	pile_b = NULL;
	if (!total_size)
		total_size = ft_lstsize(start);
	pivot = find_median(start, len);
	int_pivot = 0;
	while (lst_elem_i(start, i - ft_lstsize(pile_b)) != NULL && i < len)
	{
		if (lst_elem_i(start, i - 1 - ft_lstsize(pile_b))->next == pivot)
			int_pivot = find_int_lst(pivot, start);
		else if (ft_atoi((lst_elem_i(start, i - 1 - \
ft_lstsize(pile_b))->next)->content) < ft_atoi(pivot->content))
			pile_b = main_condition(lst_elem_i(start, i - 1 - \
ft_lstsize(pile_b)), pile_b, iteration_start + i - ft_lstsize(pile_b), \
total_size - ft_lstsize(pile_b));
		i++;
	}
	if (int_pivot != 0)
		pile_b = manage_pivot(pile_b, find_min1_lst(pivot, start), \
int_pivot + iteration_start - 1, total_size - ft_lstsize(pile_b));
	return (pile_b);
}

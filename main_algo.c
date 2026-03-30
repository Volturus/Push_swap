/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:57:34 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/18 14:20:01 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_pa(int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_printf("pa\n");
		i++;
	}
}

static t_list	*retrieve_from_pile_b(t_list *start, t_list *startmin1, \
t_list *pile_b, int skipped)
{
	t_list	*place_to_move;
	t_list	*tmp;

	write_pa(ft_lstsize(pile_b));
	if (lst_elem_i(start, skipped) == start && !startmin1)
	{
		ft_lstlast(pile_b)->next = start;
		start = pile_b;
	}
	else
	{
		if (lst_elem_i(start, skipped) == start && startmin1)
			place_to_move = startmin1;
		else
			place_to_move = find_min1_lst(lst_elem_i(start, skipped), \
start);
		tmp = place_to_move->next;
		place_to_move->next = pile_b;
		ft_lstlast(pile_b)->next = tmp;
		if (place_to_move == startmin1)
			start = pile_b;
	}
	return (start);
}

static t_list	*manip_list(t_list *start, t_list *startmin1, \
int len, int iteration_start)
{
	static int	total_size;
	int			skipped;
	t_list		*pivot;
	t_list		*cursor;
	t_list		*pile_b;

	if (!total_size)
		total_size = ft_lstsize(start);
	skipped = 0;
	pivot = find_median(start, len);
	cursor = start;
	while (ft_atoi(cursor->content) < ft_atoi(pivot->content))
	{
		cursor = cursor->next;
		skipped++;
	}
	pile_b = store_into_pile_b(skipped + 1, start, iteration_start, len);
	if (ft_lstsize(pile_b) >= 1)
	{
		move_to_place(iteration_start + skipped, \
total_size - ft_lstsize(pile_b));
		start = retrieve_from_pile_b(start, startmin1, \
pile_b, skipped);
	}
	return (start);
}

t_list	*quicksort(t_list *start, t_list *startmin1, \
int len, int iteration_start)
{
	static int	total_size;
	int			i;
	t_list		*pivot;

	if (!total_size)
		total_size = ft_lstsize(start);
	pivot = find_median(start, len);
	start = manip_list(start, startmin1, len, iteration_start);
	i = find_int_lst(pivot, start) - 1;
	if (i > 1)
	{
		if (i == 2)
			start = size2_helper(start, total_size, iteration_start);
		else
			start = quicksort(start, startmin1, i, iteration_start);
	}
	if (len - i - 1 > 1)
	{
		if (len - i - 1 == 2)
			size2_helper(pivot->next, total_size, iteration_start + i + 1);
		else
			quicksort(pivot->next, pivot, len - i - 1, iteration_start + i + 1);
	}
	return (start);
}

////// debug to insert inside the function, 
//  test = 0;
// 	ft_printf("\n!!!\n");
// 	printa2 = printa;
// 	cursor = start;
// 	while (test < i)
// 	{
// 		ft_printf("before : %s, test : %d\n", cursor->content, test);
// 		test++;
// 		cursor = cursor->next;
// 	}
// 	test = 0; 
// 	ft_printf("pivot : %s\n", cursor->content); 
// 	ft_printf("pivot : %s\n", pivot->content); 
// 	cursor = cursor->next;
// 	while (test < len - i - 1)
// 	{
// 		ft_printf("after : %s, test : %d\n", cursor->content, test);
// 		test++;
// 		cursor = cursor->next;
// 	}
// 	ft_printf("\n!!!\n");
// 	ft_printf("||||");
// 	ft_printf("\n"); 

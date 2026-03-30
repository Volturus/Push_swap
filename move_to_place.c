/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:06:42 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/13 16:49:46 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	condition1(int move_straight)
{
	int	i;

	i = 0;
	if (move_straight > 0)
	{
		while (i < move_straight)
		{
			i++;
			ft_printf("ra\n");
		}
	}
	else
	{
		while (i < (-1) * (move_straight))
		{
			i++;
			ft_printf("rra\n");
		}
	}
}

static void	condition2(int place_to_move, int go_to_end)
{
	int	i;

	i = 0;
	while (i < go_to_end)
	{
		i++;
		ft_printf("ra\n");
	}
	i = 0;
	while (i < place_to_move)
	{
		i++;
		ft_printf("ra\n");
	}
}

static void	condition3(int previous_placement, int go_from_end)
{
	int	i;

	i = 0;
	while (i < previous_placement)
	{
		i++;
		ft_printf("rra\n");
	}
	i = 0;
	while (i < go_from_end)
	{
		i++;
		ft_printf("rra\n");
	}
}

void	move_to_place(int place_to_move, int current_len)
{
	static int	previous_placement;

	if (!previous_placement)
		previous_placement = 1;
	if (previous_placement > current_len)
		previous_placement = 1;
	if (abs(place_to_move - previous_placement) \
< (current_len - previous_placement + place_to_move) \
&& abs(place_to_move - previous_placement) \
< (current_len - place_to_move + previous_placement))
		condition1(place_to_move - previous_placement);
	else if ((current_len - previous_placement + place_to_move) \
<= (current_len - place_to_move + previous_placement))
		condition2(place_to_move, current_len - previous_placement);
	else
		condition3(previous_placement, current_len - place_to_move);
	previous_placement = place_to_move ;
}

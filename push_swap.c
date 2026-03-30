/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:28:48 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/30 10:49:29 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_list(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (lst->next != NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	free(lst);
}

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

t_list	*choose_algo5(t_list *new_input)
{
	if (ft_atoi(new_input->content) < ft_atoi(new_input->next->content) \
&& ft_atoi(new_input->content) < \
ft_atoi(new_input->next->next->next->next->content) \
&& ft_atoi(new_input->next->content) > \
ft_atoi(new_input->next->next->next->next->content) \
&& ft_atoi(new_input->next->next->content) > \
ft_atoi(new_input->next->next->next->content) \
&& ft_atoi(new_input->content) > \
ft_atoi(new_input->next->next->content))
	{
		ft_printf("sa\nra\npb\nsa\nra\nra\npa\nrra\nrra\n");
		return (NULL);
	}
	if (ft_atoi(new_input->content) < ft_atoi(new_input->next->content) \
&& ft_atoi(new_input->content) < \
ft_atoi(new_input->next->next->content) \
&& ft_atoi(new_input->next->content) > \
ft_atoi(new_input->next->next->content) \
&& ft_atoi(new_input->next->next->next->content) > \
ft_atoi(new_input->next->next->next->next->content) \
&& ft_atoi(new_input->content) > \
ft_atoi(new_input->next->next->next->content))
	{
		ft_printf("ra\nsa\nra\nra\nsa\n");
		return (NULL);
	}
	return (size5_algo(new_input, NULL));
}

t_list	*choose_algo(t_list *new_input)
{
	t_list	*start;

	if (ft_lstsize(new_input) == 2)
		start = size2_algo(new_input, 2);
	else if (ft_lstsize(new_input) == 3)
	{
		if (ft_atoi(new_input->content) > \
ft_atoi(new_input->next->content) && ft_atoi(new_input->content) \
< ft_atoi(new_input->next->next->content))
		{
			ft_printf("sa\n");
			return (NULL);
		}
		start = size3_algo(new_input, NULL, 3);
	}
	else if (ft_lstsize(new_input) == 4)
		start = size4_algo(new_input, NULL, 4);
	else if (ft_lstsize(new_input) == 5)
		start = choose_algo5(new_input);
	else
		start = quicksort(new_input, NULL, ft_lstsize(new_input), 1);
	return (start);
}

int	main(int argc, char **argv)
{
	char	**old_input;
	t_list	*new_input;
	t_list	*start;
	int		test;

	if (argc == 1)
		return (0);
	old_input = create_tab(argv);
	new_input = create_list(old_input);
	test = ft_lst_verif(new_input, ft_lstsize(new_input)+1);
	if (test == 0)
	{
		ft_printf("Error\n");
		free_tab(old_input);
		free_list(new_input);
		return (0);
	}
	start = choose_algo(new_input);
	if (start != NULL)
		move_to_place(1, ft_lstsize(start));
	free_tab(old_input);
	free_list(start);
}

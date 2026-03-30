/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:46:05 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/18 14:28:02 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_string_verif(char *str)
{
	int				i;
	long long int	signe;
	long long int	converted_string;

	i = 0;
	signe = 1;
	converted_string = 0;
	if ((str[i] < 48 || str[i] > 57) && (str[i] != '-') && (str[i] != '+'))
		return (0);
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		converted_string = converted_string * 10 + (str[i] - 48);
		i++;
	}
	if (converted_string * signe > 2147483647 || \
converted_string * signe < -2147483648)
		return (0);
	return (1);
}

static int	ft_duplicate_verif(char **mem)
{
	int	i;
	int	j;

	i = 0;
	while (mem[i])
	{
		if (ft_string_verif(mem[i]) == 0)
			return (0);
		j = 0;
		while (mem[j])
		{
			if (i != j && ft_atoi(mem[i]) == ft_atoi(mem[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_lst_verif(t_list *lst, int array_length)
{
	char	**mem;
	int		i;

	i = 0;
	mem = (char **) malloc (sizeof(char *) * (array_length));
	mem[array_length - 1] = NULL;
	while (lst != NULL)
	{
		mem[i] = lst->content;
		lst = lst->next;
		i++;
	}
	if (ft_duplicate_verif(mem) == 0)
	{
		free(mem);
		return (0);
	}
	else
	{
		free(mem);
		return (1);
	}
}

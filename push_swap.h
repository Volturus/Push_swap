/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourey <vmourey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:57:33 by vmourey           #+#    #+#             */
/*   Updated: 2026/03/18 14:20:01 by vmourey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

void	s(t_list *a);
int		ft_strlen(char const *s);
int		push_swap(char *a);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *src);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		count_w(const char *s, char c);
char	**ft_split(char const *s, char c);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstlastmin1(t_list *lst);
int		ft_lstsize(t_list *lst);
t_list	*lst_elem_i(t_list *lst, int len);
char	**create_tab(char **argv);
void	fill_tab(char **retour, char **argv);
t_list	*create_list(char **retour);
t_list	*quicksort(t_list *start, t_list *startmin1, int len, \
int iteration_start);
int		ft_printf(const char *s, ...);
int		is_sorted(t_list *lst);
int		is_sorted_len(t_list *lst, int len);
void	move_to_place(int place_to_move, int len);
t_list	*size2_algo(t_list *lst, int current_len);
t_list	*size3_algo(t_list *start, t_list *startmin1, int current_len);
t_list	*size4_algo(t_list *start, t_list *startmin1, int current_len);
t_list	*size5_algo(t_list *start, t_list *startmin1);
t_list	*size2_helper(t_list *start, int total_len, int iteration_start);
t_list	*find_median(t_list *lst, int len);
t_list	*find_min1_lst(t_list *searched, t_list *start);
int		find_int_lst(t_list *searched, t_list *start);
int		ft_lst_verif(t_list *lst, int array_length);
t_list	*store_into_pile_b(int i, t_list *start, int iteration_start, int len);

#endif
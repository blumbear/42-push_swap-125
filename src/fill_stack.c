/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:07:45 by tom               #+#    #+#             */
/*   Updated: 2024/04/30 14:29:44 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_stack_b_five(t_list **a, t_list **b)
{
	int max;
	int min;

	max = ft_find_max(a)->content;
	min = ft_find_min(a)->content;
	if ((*a)->content == min || (*a)->content == max)
	{
		if ((*a)->next->content != min && (*a)->next->content != max)
			rotate("a", a, b);
		else
			reverse_rotate("a", a, b);
	}
	push('b', a, b);
	push('b', a, b);
}

int i = 0;
void	ft_place_on_top_second(t_list **a, t_list **b, t_list *min_cost)
{
	set_index(a, b);
	set_mediane(a, b);
	set_target(a, b, 'b');
	set_cost(a, b, 'b');
	min_cost = find_min_cost(b);
	if (*b != min_cost && *a != min_cost->target && min_cost->target->above_mediane && min_cost->above_mediane)
		while (min_cost != *b && min_cost->target != *a)
			rotate("ab", a, b);
	if (*b != min_cost && *a != min_cost->target && !min_cost->target->above_mediane && !min_cost->above_mediane)
		while (min_cost != *b && min_cost->target != *a)
			reverse_rotate("ab", a, b);
	if (*b != min_cost && min_cost->above_mediane)
		while (min_cost != *b)
			rotate("b", a, b);
	if (*a != min_cost->target && min_cost->target->above_mediane)
		while (min_cost->target != *a)
			rotate("a", a, b);
	if (*b != min_cost && !min_cost->above_mediane)
		while (*b != min_cost)
			reverse_rotate("b", a, b);
	if (*a != min_cost->target && !min_cost->target->above_mediane)
		while (min_cost->target != *a)
			reverse_rotate("a", a, b);
}

void	ft_place_on_top_first(t_list **a, t_list **b, t_list *min_cost)
{
	set_index(a, b);
	set_mediane(a, b);
	set_target(a, b, 'a');
	set_cost(a, b, 'a');
	min_cost = find_min_cost(a);
	if (*a != min_cost && *b != min_cost->target && min_cost->target->above_mediane && min_cost->above_mediane)
		while (min_cost != *a && min_cost->target != *b)
			rotate("ab", a, b);
	if (*a != min_cost && *b != min_cost->target && !min_cost->target->above_mediane && !min_cost->above_mediane)
		while (min_cost != *a && min_cost->target != *b)
			reverse_rotate("ab", a, b);
	if (*a != min_cost && min_cost->above_mediane)
		while (min_cost != *a)
			rotate("a", a, b);
	if (*a != min_cost && !min_cost->above_mediane)
		while (min_cost != *a)
			reverse_rotate("a", a, b);
	if (*b != min_cost->target && min_cost->target->above_mediane)
		while (min_cost->target != *b)
			rotate("b", a, b);
	if (*b != min_cost->target && !min_cost->target->above_mediane)
		while (min_cost->target != *b)
			reverse_rotate("b", a, b);
}

void	ft_fill_stack_b(t_list **a, t_list **b, int a_size)
{
	t_list	*min;
	t_list	*max;
	t_list	*min_cost;

	max = ft_find_max(a);
	min = ft_find_min(a);
	min_cost = NULL;
	if ( *a == min || *a == max)
	{
		if ((*a)->next != min && (*a)->next != max)
			rotate("a", a, b);
		else
			reverse_rotate("a", a, b);
	}
	push('b', a, b);
	while (--a_size > 3)
	{
		ft_place_on_top_first(a, b, min_cost);
		push('b', a, b);
	}
}

void	ft_fill_stack_a(char **list, t_list **a, bool splitted)
{
	long int	tmp;
	int			i;

	i = -1;
	while (list[++i])
	{
		tmp = ft_atoi(list[i]);
		if (tmp > MAX_INT || tmp < MIN_INT || ft_strlen(list[i]) > 11)
		{
			if (splitted)
				ft_free_double_array(list);
			ft_error(a, NULL, "The value mist be between MIN_INT and MAX_INT");
		}
		if (!ft_all_isdigit(list[i]))
		{
			if (splitted)
				ft_free_double_array(list);
			ft_error(a, NULL, "The value cant contain any char");
		}
		ft_lstadd_back(a, ft_lstnew((int)tmp));
	}
}

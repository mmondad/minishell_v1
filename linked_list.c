/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:39:20 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/23 11:15:06 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_back(t_list **list, t_list *new_node)
{
	t_list *tmp;
	
	if (!new_node->txt[0])
		return (free(new_node), 0);
	tmp = *list;
	if (*list)
	{
		while ((*list)->next)
			(*list) = (*list)->next;
		(*list)->next = new_node;
		*list = tmp;
	}
	else
		(*list) = new_node;
	return (1);
}

void	new_node(char *str, int type, t_info *info)
{
	t_list *node;
	node = malloc(sizeof(t_list));
	if (!node)
		free_list(info);
	node->next = NULL;
	node->type = type;
	node->txt = str;
	if (add_back(&info->list, node))
		info->lst_size++;
}

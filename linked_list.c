/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:39:20 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/27 20:32:04 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_back(t_list **list, t_list *new_node)
{
	t_list *tmp;

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
	add_back(&info->list, node);
}

void	add_back_p(t_plist **list, t_plist *new_node)
{
	t_plist *tmp;

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
}

t_plist	*new_pnode(t_info *info)
{
	t_plist *node;

	node = malloc(sizeof (t_plist));
	if (!node)
		free_list(info);
	node->parts = NULL;
	node->reds = NULL;
	node->parts = malloc (sizeof (char *) * (info->parts_l + 1));
	if (info->reds_l)
		node->reds = malloc (sizeof (char *) * (info->reds_l + 1));
	if (info->reds_l)
		node->types = malloc(sizeof (int) * (info->reds_l));
	if (!node->parts || !node->types)
		free_list (info);
	node->next = NULL;
	return (node);
}

void	create_plist(t_info *info)
{
	t_list *lst;
	t_plist	*node;

	info->plist = NULL;
	lst = info->list;
	while (lst)
	{
		info->i = 0;
		info->j = 0;
		p_len(info);
		node = new_pnode(info);
		while (lst && lst->type != PIPE)
		{
			if (lst->type > PIPE)
			{
				node->reds[info->i] = lst->txt;
				node->types[info->i++] = lst->type;
				node->reds[info->i] = lst->next->txt;
				node->types[info->i++] = lst->next->type;
				lst = lst->next;
			}
			else
				node->parts[info->j++] = lst->txt;
			lst = lst->next;
		}
		if (node->parts)
			node->parts[info->j] = NULL;
		if (node->reds)
			node->reds[info->i] = NULL;
		add_back_p(&info->plist, node);
		if (lst)
			lst = lst->next;
	}
}

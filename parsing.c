/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:57:53 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/24 13:53:09 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	p_len(t_list *list)
{
	int len;

	len = 0;
	while (list && list->type != PIPE)
	{
		len++;
		list = list->next;
	}
	return (len);
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
		node = new_pnode(info, p_len(lst));
		while (lst && lst->type != PIPE)
		{
			node->parts[info->i] = lst->txt;
			node->types[info->i] = lst->type;
			lst = lst->next;
			info->i++;
		}
		node->parts[info->i] = NULL;
		add_back_p(&info->plist, node);
		if (lst)
			lst = lst->next;
	}
}

int		check_quotes(char *line)
{
	char	tmp;
	int		i;
	int		flag;

	tmp = 0;
	i = -1;
	flag = 0;
	while (line[++i])
	{
		if ((line[i] == '\'' || line[i] == '\"') && !flag)
		{
			tmp = line[i++];
			flag = 1;
		}
		if (line[i] && line[i] == tmp && flag)
			flag = 0;
	}
	return (flag);
}
int check_token(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int	check_sep(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

int main(void)
{
	t_info	info;

	while (1)
	{
		info.line = readline ("minishell-0.0$ ");
		if (info.line)
			add_history(info.line);
		info.tmp_line = info.line;
		while (*info.line && *info.line == ' ')
			info.line++;
		if (!check_quotes(info.tmp_line))
		{
			info.lst_size = 0;
			ft_split(&info);
			create_plist(&info);
			print_list2(info);
			//printf("----------------------\n");
			//print_list(info);
		}
		else
			printf("stx_error\n");
		free_list(&info);
	}
}

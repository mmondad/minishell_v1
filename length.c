/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:29:13 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/27 12:41:47 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	len_f(char *s1, t_split *data)
{
	data->len = 0;
	while (s1[data->i] && !check_sep(s1[data->i]))
	{
		if (s1[data->i] == '\'' || s1[data->i] == '\"')
		{
			data->tmp = s1[data->i++];
			while (s1[data->i] && s1[data->i++] != data->tmp)
				data->len++;
		}
		else
		{
			data->i++;
			data->len++;
		}
	}
}

void	p_len(t_info *info)
{
	t_list *lst;

	lst = info->list;
	info->reds_l = 0;
	info->parts_l = 0;
	while (lst && lst->type != PIPE)
	{
		if (lst->type > PIPE)
		{
			info->reds_l += 2;
			lst = lst->next;
		}
		else
			info->parts_l++;
		lst = lst->next;
	}
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
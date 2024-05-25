/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:29:13 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/25 09:31:48 by mmondad          ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
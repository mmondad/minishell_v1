/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:37:59 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/23 09:30:11 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int len_f(char *s1, t_split data)
{
	data.i = 0;
	data.len = 0;
	while (s1[data.i] && !check_sep(s1[data.i]))
	{
		if (s1[data.i] == '\'' || s1[data.i] == '\"')
		{
			data.tmp = s1[data.i++];
			while (s1[data.i] && s1[data.i++] != data.tmp)
				data.len++;
		}
		else
		{
			data.i++;
			data.len++;
		}
	}
	return (data.len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ss2;
	unsigned char	*ss1;

	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	i = 0;
	while ((ss1[i] || ss2[i]))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(t_info *info, t_split data)
{
	char	*cpy;
	int		len;

	data.j = 0;
	len = len_f(info->line, data);
	cpy = malloc(len + 1);
	if (!cpy)
		free_list(info);
	data.i = 0;
	while (info->line[data.i] && !check_sep(info->line[data.i]))
	{
		if (info->line[data.i] == '\"' || info->line[data.i] == '\'')
		{
			data.tmp = info->line[data.i++];
			while (info->line[data.i] && info->line[data.i++] != data.tmp)
				cpy[data.j++] = info->line[data.i - 1];
		}
		else
			cpy[data.j++] = info->line[data.i++];
	}
	cpy[len] = '\0';
	return (cpy);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:53:20 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/23 10:11:38 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_type(char *token, int *type)
{
		if (ft_strcmp(token, "<<") == 0)
			*type = HEREDOC;
		else if (ft_strcmp(token, ">>") == 0)
			*type = A_RED;
		else if (ft_strcmp(token, ">")== 0)
			*type = O_RED;
		else if (ft_strcmp(token, "<")== 0)
			*type = I_RED;
		else if (ft_strcmp(token, "|")== 0)
			*type = PIPE;
		else
			*type = UNKNOWN;
}

char	*token(char *line, int *type, int *size, t_info *info)
{
	char	tmp;
	int		len;
	char	*token;

	len = 0;
	tmp = line[0];
	while (tmp == line[len])
		len++;
	*size = len;
	token = malloc(len + 1);
	if (!token)
		free_list(info); 
	len = -1;
	while (tmp == line[++len])
		token[len] = line[len];
	token[len] = 0;
	init_type(token, type);
	return (token);
}

int	add_token(t_info *info)
{
	int		i;
	int		type;
	int		size;
	t_list	*node;

	i = 0;
	size = 0;
	while (info->line[i] && info->line[i] == ' ')
		i++;
	if (info->line[i] && check_token(info->line[i]))
	{
		node = new_node(token(info->line + i, &type, &size, info), type, info);
		add_back(&info->list, node);
	}
	while (info->line[i] && info->line[i] == ' ')
		i++;
	return (size + i);
}

void	ft_split(t_info *info)
{
	t_split	data;
	t_list	*node;

	data.i = 0;
	while (*info->line)
	{
		info->line += add_token(info);
		if (*info->line && !check_sep(*info->line))
		{
			node = new_node(ft_strdup(info, data), WORD, info);
			add_back(&info->list, node);
		}
		while (*info->line && !check_sep(*info->line))
		{
			if (*info->line == '\"' ||  *info->line == '\'')
			{
				info->line++;
				while (*info->line && *info->line != '\"' && *info->line != '\'')
					info->line++;
			}
			info->line++;
		}
		info->line += add_token(info);
	}
}

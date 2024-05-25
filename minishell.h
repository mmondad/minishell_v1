/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:36:40 by mmondad           #+#    #+#             */
/*   Updated: 2024/05/25 10:22:35 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>

# define UNKNOWN 0
# define WORD 1
# define PIPE 2
# define HEREDOC 3
# define A_RED 4
# define I_RED 5
# define O_RED 6

typedef struct s_plist
{
	char			**parts;
	int				*types;
	struct s_plist	*next;
}	t_plist;

typedef struct s_list
{
	char			*txt;
	int				type;
	struct s_list	*next;
}	t_list;

typedef struct s_info
{
	int		i;
	char	*line;
	t_list	*list;
	t_plist	*plist;
	char	*tmp_line;
}	t_info;

typedef struct s_split
{
	int		i;
	int		j;
	int		len;
	char	tmp;
}	t_split;

		/*   length   */
int		p_len(t_list *list);
int		ft_strlen(char *str);
void	len_f(char *s1, t_split *data);

		/*   validators   */
int		check_escape(char c);
int		check_token(char c);
int		check_sep(char c);
int		check_quotes(char *line);

		/*   print   */
void	print_list2(t_info info);
void	print_list(t_info info);
void	ft_putstr(char *str, int fd);

		/*   linked_list   */
void	add_back(t_list **list, t_list *new_node);
void	new_node(char *str, int type, t_info *info);
void	create_plist(t_info *info);

void	ft_split(t_info *info);
int		ft_strcmp(const char *s1, const char *s2);
void	free_list(t_info	*info);
char	*ft_strdup(t_info *info, t_split data);
int		stx_errors(t_info info);

#endif

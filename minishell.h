/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:36:40 by mmondad           #+#    #+#             */
/*   Updated: 2024/06/03 12:55:06 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

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
	char			**reds;
	int				*types;
	struct s_plist	*next;
}	t_plist;

typedef struct s_list
{
	char			*txt;
	int				type;
	struct s_list	*next;
}	t_list;

typedef struct s_env
{
	char			*line;
	struct s_env	*next;
}	t_env;

typedef struct s_info
{
	int		i;
	int		j;
	int		parts_l;
	int		reds_l;
	char	*line;
	t_list	*list;
	t_plist	*plist;
	char	*tmp_line;
	char	**penv;
	char	**argv;
	int		argc;
	int		count;
	t_env	*head_e;
	int		quotes;
	int		flag;
}	t_info;


typedef struct s_split
{
	int		i;
	int		j;
	int		len;
	char	tmp;
}	t_split;

		/*   length   */
void	len_f(char *s1, t_split *data);
int		ft_strlen(char *str);
int		until_d(char *str, t_info *info);
void	set_val(char c, t_info *info);
void	p_len(t_list *lst, t_info *info);

		/*   validators   */
int		check_escape(char c);
int		check_token(char c);
int		check_sep(char c);
int		check_quotes(char *line);
int		alpha_n(char c);

		/*   print   */
void	print_list2(t_info info);
void	print_list(t_info info);
void	ft_putstr(char *str, int fd);
void	print_env(t_env *head);

		/*   linked_list   */
void	add_back(t_list **list, t_list *new_node);
void	new_node(char *str, int type, t_info *info);
void	create_plist(t_info *info);
t_env	*new_node_e(void);
void	add_back_p(t_plist **list, t_plist *new_node);
void	add_back_e(t_env **list, t_env *new_node);
t_plist	*new_pnode(t_info *info);
		/*    expand		*/
char	*expand(t_info *info);


char	*ft_strjoin(char *s1, char *s2);
void	ft_split(t_info *info);
int		ft_strcmp(const char *s1, const char *s2);
void	free_list(t_info	*info);
char	*ft_strdup(t_info *info, t_split data);
int		stx_errors(t_info info);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_typedefs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:52:57 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 15:57:18 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPEDEFS_H
# define MINISHELL_TYPEDEFS_H

// Based on the default quantity of envars on the 42 campus iMac;
# define HASH_SIZE 56
# define BUILTIN "echo exit cd export unset pwd env"

typedef struct s_node
{
	char			*key;
	char			*value;
	struct s_node	*next;
}					t_node;

typedef struct s_hash
{
	t_node			*list[HASH_SIZE];
}					t_hash;

typedef struct s_command
{
	int				wr_here;
	int				rd_here;
	char			**argv;
}					t_command;

typedef struct s_pipe
{
	size_t			id;
	size_t			nbr_sons;
	char			**pipeline_rest;
	char			**redirect_rest;
	char			**envp;
	t_hash			*hash;
	t_command		*command;
}					t_pipe;

#endif

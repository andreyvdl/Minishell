/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_typedefs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:05:10 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/26 14:08:03 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPEDEFS_H
# define MINISHELL_TYPEDEFS_H

# define HASH_SIZE 100

typedef struct s_node {
	char			*key;
	char			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_hash {
	t_node	*list[HASH_SIZE];
}	t_hash;

#endif

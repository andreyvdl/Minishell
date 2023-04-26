/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:00:37 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 22:35:29 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include "libft_defines.h"
# include "libft_structs.h"

t_btree			*ft_btree_create_node(void *item);
void			*ft_btree_search_item(t_btree *root, void *data_ref, \
										int (*cmpf)(void *, void *));
void			ft_btree_apply_infix(t_btree *root, void (*applyf)(void *));
void			ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void			ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void			ft_btree_insert_data(t_btree **root, void *item, \
								int (*cmpf)(void *, void *));

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprime(int nb);
int				ft_isprint(int c);
int				ft_isupper(int c);

char			*ft_itoa(int n);
char			*ft_itob(int nbr);
char			*ft_itoh(int n);
char			*ft_itoo(int n);
int				ft_atoi(const char *nptr);
int				ft_btoi(const char *binary);
int				ft_htoi(const char *hexadecimal);
int				ft_otoi(const char *octal);

int				ft_printf(const char *string, ...);
int				ft_printf_fd(int file_descriptor, const char *string, ...);
int				ft_printf_ln(const char *string, ...);

char			*get_next_line(int fd);

t_list			*ft_list_at(t_list *begin_list, size_t nbr);
t_list			*ft_list_find(t_list *begin_list, void *data_ref, \
								int (*cmp)(void *, void *));
t_list			*ft_list_push_strs(size_t size, char **strs);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
							void (*del)(void *));
t_list			*ft_lstnew(void *content);
void			ft_list_foreach_if(t_list *begin_list, void (*f)(void *), \
									void *data_ref, int (*cmp)(void *, void *));
void			ft_list_remove_if(t_list **begin_list, void *data_ref, \
									int (*cmp)(void *, void *), \
									void (*free_fct)(void *));
void			ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *));
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstmerge(t_list **begin_list1, t_list *begin_list2);
void			ft_lstreverse(t_list **begin_list);
size_t			ft_lstsize(t_list *lst);

int				ft_absolute_number(int number);
unsigned int	ft_factorial(unsigned int n);
unsigned int	ft_next_prime(int nb);
double			ft_power(double number, int exponent);
unsigned int	ft_termial(unsigned int n);

void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_free(void **pointer);
void			ft_free_matrix(void ***matrix);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_swap(void **pointer1, void **pointer2);

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char *str);
void			ft_putstr_fd(char *s, int fd);

char			**ft_matrixdup(char **matrix);
char			**ft_split(char const *s, char c);
char			*ft_strcapitalize(char *str);
char			*ft_strcat(char *dest, char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, char *src);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strlowcase(char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *str);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strupcase(char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strcmp(char *s1, char *s2);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

int				ft_tolower(int c);
int				ft_toupper(int c);

#endif

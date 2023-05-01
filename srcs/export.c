#include "../includes/minishell.h"

static int syntax_error(char *str)
{
	if (!(*str == '_' || isalpha(*str)))
		return (-1);
	while (*++str)
	if (!isalnum(*str) && *str != '_')
		return (-1);
	return (1);
}

static char	*extract_variable(char *str)
{
	int i = 0;
	printf("varible = %s\n", str);
	while (str[i] && str[i] != '=')
		i++;
	str[i] = '\0';
	return (str);
}

static char	*extract_value(char *str)
{
	while (*str && *str != '=' && !(*str >= ' ' && *str <= '\t'))
		str++;
	return (str + 1);
}

void	export(char *str, t_hash *hash)
{
	char	*existing_value;
	char	*variable;
	char	*value;

	while (*str && (*str != ' ' && *str != '\t'))
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;

	variable = ft_strdup(extract_variable(str));
	if (syntax_error(variable) != 1)
		return ((void)printf("[export:`%s`:not a valid identifier]\n", str));

	value = extract_value(str);
	existing_value = search(hash, variable);
	if (existing_value == NULL)
		insert_node(hash, variable, value);
	else
		insert_node(hash, variable, value);
	printf("Exported %s=%s\n", variable, value);
}
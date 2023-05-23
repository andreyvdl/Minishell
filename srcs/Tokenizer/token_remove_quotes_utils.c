#include "../../includes/minishell.h"

static void value_size(char *str, size_t *index, size_t *counter)
{
    size_t  var_len;

    var_len = 0;
    (*index)++;
    if (!(str[*index] >= '0' && str[*index] <= '9'))
    {
        if (str[*index] == '?')
        {
            (*counter) += ft_strlen(search(g_shell.hash, "?"));
            (*index);
            while ((ft_isalpha(str[*index]) || str[*index] == '_') && \
            str[*index] != '\0')
                (*index)++;
        }
        else
        {
            while ()
        }
}

static void count_quotes(char *str, size_t *index, size_t *counter, char ref)
{
    (*index)++;
    (*counter)++;
    if (ref == '\'')
        while (str[*index] != ref)
        {
            (*counter)++;
            (*index)++;
        }
    else
    {
        while (str[*index] != ref)
        {
            if (str[*index] == '$')
                value_size(str, index, counter);
            else
            {
                (*counter)++;
                (*index)++;
            }
        }
    }
}

size_t	get_edit_size(char *str)
{
	size_t	index;
	size_t	counter;

	index = 0;
	counter = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\'' || str[index] == '\"')
			count_quotes(str, &index, &counter, str[index]);
		else if (str[index] == '$')
			value_size(str, &index, &counter);
		else
        {
            counter++;
			index++;
        }
	}
	return (counter);
}
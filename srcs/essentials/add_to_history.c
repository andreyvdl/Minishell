#include "../../includes/minishell.h"

void	add_to_history(char *pipeline)
{
	if (*pipeline != '\0')
		add_history(pipeline);
}

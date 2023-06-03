#include "../../includes/minishell.h"

int	filename_too_big(char *filename)
{
	size_t	counter;

	if (filename != NULL)
		while (*filename)
		{
			counter = 0;
			while (filename[counter] != '\0' && filename[counter] != '/')
				counter++;
			if (counter > FILENAME_MAX_LEN)
				return (TRUE);
			else if (filename[counter] == '\0')
				return (FALSE);
			filename += counter + 1;
		}
	return (FALSE);
}

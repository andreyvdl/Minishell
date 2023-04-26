#include "../includes/minishell.h"

unsigned int hash_code(char *key)
{
	unsigned long	hash = 5381;
	unsigned int	c;
	while (*key){
		c = *key;
		hash = ((hash << 5) + hash) + c;
		key++;
	}
	return (hash % HASH_SIZE);
}

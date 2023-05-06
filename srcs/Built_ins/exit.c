#include "../../includes/minishell.h"

/*
casos a tratar:
exit | tem q dar certo, retorna 0
exit "42" | tem q dar certo, retorna 42
exit "-42" | tem q dar certo, retorna 214 (pq o status eh um unsigned char)
exit "42 " | tem q dar certo, retorna 42
exit " 42" | tem q dar certo, retorna 42
exit " 42 " | tem q dar certo, retorna 42
exit "42 42" | tem q dar error `numeric argument`, retorna 2
exit "" | tem q dar error `numeric argument`, retorna 2
exit "   " | tem q dar error `numeric argument`, retorna 2
exit a | tem q dar error `numeric argument`, retorna 2
exit 42a | tem q dar error `numeric argument`, retorna 2
exit a42 | tem q dar error `numeric argument`, retorna 2
exit 42a42 | tem q dar error `numeric argument`, retorna 2
exit 42 42 | tem q dar error `too many arguments`, n sai e o status fica 1
exit 9223372036854775807 | tem q dar certo, retorna 255
exit -9223372036854775808 | tem q dar certo, retorna 0
exit 9223372036854775808 | tem q dar error `numeric argument`, retorna 2
exit -9223372036854775809 | tem q dar error `numeric argument`, retorna 2
exit 00000000000000000000000000000000009223372036854775807
exit "\t\t\t\t\t\r\v\v\v\f\n -000000000000000000000092233720368547758078         \t\t\t\t\t\t    "
*/

/*
void	mini_exit(char *input, t_hash *hash)
{
	while (*input && ft_isspace)
		input++;
	if (*input == '\0')
	{
		free_hash(hash);
		exit(0);
	}
	if (exit_validate(input))
	{

	}
	else
	{
		ft_printf_fd(2, "exit\nminishell: exit: %s: numeric argument required" \
		"\n", input);
		free_hash(hash);
		exit(2);
	}
}
*/
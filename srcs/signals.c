#include "../includes/minishell.h"

static void	re_print_prompt(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	set_up_signals(void)
{
	signal(SIGINT, re_print_prompt);
	signal(SIGQUIT, SIG_IGN);
}

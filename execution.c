#include "shell.h"

int new_process(char *mini_path, char **tokens)
{
	pid_t process_id;
	int state, exe_state;
	char **envp = environ;

	if (mini_path == NULL)
		return (-1);

	process_id = fork();

	if (process_id == -1)
	{
		perror("Error on fork: ");
		exit(3);
	}
	if (process_id == 0)
	{
		exe_state = execve(mini_path, tokens, envp);
		if (exe_state == -1)
			return (-1);
	}
	else
		wait(&state);

	return (0);
}

#include "shell.h"

/**
 * new_process - Executes a command.
 *
 * @mini_path: Path to command.
 * @tokens: Pointer to array of tokens.
 *
 * Description: This function creates a child process
 * if the path to a given command exist and executes it.
 *
 * Return: -1 if execuion fails or 0 if not.
 *
 */

int new_process(char *mini_path, char **tokens)
{
	pid_t process_id;
	int state = 0, exe_state = 0;
	char **envp = environ;

	if (mini_path == NULL)
		return (0);

	process_id = fork();

	if (process_id == -1)
	{
		perror("sh: Error");
		exit(3);
	}
	if (process_id == 0)
	{
		exe_state = execve(mini_path, tokens, envp);
		if (exe_state == -1)
		{
			perror("sh: Error");
			exit(14);
		}
	}
	else
		wait(&state);

	return (0);
}

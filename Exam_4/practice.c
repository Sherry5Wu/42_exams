#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void	err_msg(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	cd(char **av, int i)
{
	if (i != 2)
		return err_msg("error: cd: bad arguments\n"), 1;
	if (chdir(av[1]) == -1)
		return err_msg("error: cd: cannot change directory to "),err_msg(av[1]), err_msg("\n"), 1;
	return (0);
}

void	set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe)
	{
		if (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
			err_msg("error: fatal\n"), exit(1);
	}
}

int exe(char **av, int i, char **envp)
{
	int	has_pipe, fd[2], pid, status;

	has_pipe = av[i] && !strcmp(av[i], "|");
	if (!has_pipe && !strcmp(*av, "cd"))
		return (cd(av, i));
	if (has_pipe && pipe(fd) == -1)
		err_msg("error: fatal\n"), exit(1);
	if ((pid = fork()) == -1)
		err_msg("error: fatal\n"), exit(1);
	if (!pid)
	{
		av[i] = 0;
		set_pipe(has_pipe, fd, 1);
		if ( !strcmp(*av, "cd"))
			exit(cd(av, i));
		execve(*av, av, envp);
		err_msg("error: cannot execute "),err_msg(*av),err_msg("\n"),exit(1);
	}
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return WIFEXITED(status)&& WEXITSTATUS(status);
}

// int	exe(char **argv, int i, char **envp)
// {
// 	int has_pipe, fd[2], pid, status;
// 	has_pipe = argv[i] && !strcmp(argv[i], "|");

// 	if (!has_pipe && !strcmp(*argv, "cd"))
// 		return cd(argv, i);
// 	if (has_pipe && pipe(fd) == -1)
// 		err_msg("error: fatal\n"), exit(1);
// 	if ((pid = fork()) == -1)
// 		err_msg("error: fatal\n"), exit(1);
// 	if (!pid)
// 	{
// 		argv[i] = 0;
// 		set_pipe(has_pipe, fd, 1);
// 		if (!strcmp(*argv, "cd"))
// 			exit(cd(argv, i));
// 		execve(*argv, argv, envp);
// 		err_msg("error: cannot execute "), err_msg(*argv), err_msg("\n"), exit(1);
// 	}
// 	waitpid(pid, &status, 0);
// 	set_pipe(has_pipe, fd, 0);
// 	return WIFEXITED(status) && WEXITSTATUS(status);
// }

int	main(int ac, char **av, char **envp)
{
	(void)ac;

	int i = 0, status = 0;
	while (av[i])
	{
		av += i + 1;
		i  = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (i)
			status = exe(av, i, envp);
	}
	return (status);
}

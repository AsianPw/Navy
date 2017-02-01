#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "my.h"

int	g_pid;

void	handleSignal(int sig, siginfo_t *info, void *context)
{
  if (sig == SIGUSR1)
    g_pid = info->si_pid;
  if (context != NULL)
    return ;
}

int	game(int argc)
{
  int	state;

  state = 0;
  while (!state)
    {
      if (argc != 0)
	state = 1;
    }
  return (0);
}


int			connection(int argc, char **argv)
{
  struct sigaction	action;

  printf("my_pid: %i\n", getpid());
  action.sa_sigaction = &handleSignal;
  action.sa_flags = SA_SIGINFO;
  if (argc == 2)
    {
      printf("waiting for enemy connexion...\n");
      sigaction(SIGUSR1, &action, NULL);
      pause();
      kill(g_pid, SIGUSR1);
      printf("enemy connected\n\n");
    }
  else if (argc == 3)
    {
      kill(atoi(argv[1]), SIGUSR1);
      sigaction(SIGUSR1, &action, NULL);
      pause();
      printf("Connected\n\n");
    }
  game(argc);
  return (0);
}

char	*load_map(char *file)
{
  int	fd;
  char	*coord;
  char	*map;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  if ((coord = malloc(sizeof(char) * 4 * 8 + 1)) == NULL)
    return (NULL);
  read(fd, coord, 32);
  close(fd);
  if ((fd = open("map/EmptyMap.txt", O_RDONLY)) == -1)
    return (NULL);
  if ((map = malloc(sizeof(char) * 18 * 10)) == NULL)
    return (NULL);
  read(fd, map, 18 * 10);
  close(fd);
  //  coord_to_map();
  free(coord);
  return (map);
}


int	main(int argc, char **argv)
{
  char	*map;
  
  if (argc != 2 && argc != 3)
    return (84);
  if ((map = load_map(argv[argc - 1])) == NULL)
    return (84);
  printf("%s\n", map);
  connection(argc, argv);
  free(map);
  return (EXIT_SUCCESS);
}

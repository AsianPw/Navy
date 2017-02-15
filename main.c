/*
** main.c for main in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Mon Jan 30 12:32:49 2017 Sadisadou
** Last update Wed Feb 15 15:45:29 2017 Brice Lang-Nguyen
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "navy.h"

void	my_help()
{
  my_printf("USAGE\n\t   ./navy [first_player_pid] navy_positions\n\n");
  my_printf("DESCRIPTION\n\t   first_player_pid  only for the 2nd player,\
  pid of the first player,\n\t   navy_positions    file representing the \
positions of the ships.\n");
}

int	player1(int fd)
{
  char*	buff;

  if ((buff = malloc(sizeof(char) * 32)) == NULL)
    return (84);
  if (read(fd, buff, 31) == -1)
    {
      my_strerror("Can't read pos file.\n");
      return (84);
    }
  buff[31] = '\0';
  if (check_map(buff))
    game1(buff);
  else
    {
      my_strerror("Error with the pos file.\n");
      return (84);
    }
  free(buff);
  return (0);
}

int	player2(int fd, char* pid)
{
  int	pid1;
  char*	buff;

  pid1 = my_getnbr(pid);
  if ((buff = malloc(sizeof(char) * 32)) == NULL)
    return (84);
  if (read(fd, buff, 31) == -1)
    {
      my_strerror("Can't read pos file.\n");
      return (84);
    }
  buff[31] = '\0';
  if (check_map(buff))
    game2(buff, pid1);
  else
    {
      my_strerror("Error with the pos file.\n");
      return (84);
    }
  free(buff);
  return (0);
}

int	main(int ac, char** av)
{
  int	fd;

  if (ac == 2 && !my_strcmp(av[1], "-h"))
    my_help();
  else if (ac == 2)
    {
      if (openerr(fd = open(av[1], O_RDONLY)) == -1)
	return (84);
      if (player1(fd) == 1)
	return (1);
    }
  else if (ac == 3 && my_str_isnum(av[1]))
    {
      if (openerr(fd = open(av[2], O_RDONLY)) == -1)
	return (84);
      if (player2(fd, av[1]) == 1)
	return (1);
    }
  else
    {
      my_strerror("Wrong numbers/types of params.\n");
      return (84);
    }
  return (0);
}

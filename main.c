/*
** main.c for main in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Mon Jan 30 12:32:49 2017 Sadisadou
** Last update Mon Jan 30 22:16:01 2017 Sadisadou
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

  buff = malloc(sizeof(char) * 32);
  read(fd, buff, 31);
  buff[31] = '\0';
  if (check_map(buff))
    ;
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
      if ((fd = open(av[1], O_RDONLY)) == -1)
	return (84);
      else
	player1(fd);
    }
  else if (ac == 3 && my_str_isnum(av[1]))
    ;//player2();
  else
    my_strerror("Wrong numbers/types of params.\n");
  return (0);
}

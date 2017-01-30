/*
** main.c for main in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Mon Jan 30 12:32:49 2017 Sadisadou
** Last update Mon Jan 30 14:50:56 2017 Sadisadou
*/

#include "navy.h"

int	main(int ac, char** av)
{
  if (ac == 2 && !my_strcmp(av[1], "-h"))
    {
      my_printf("USAGE\n\t   ./navy [first_player_pid] navy_positions\n\n");
      my_printf("DESCRIPTION\n\t   first_player_pid  only for the 2nd player,\
  pid of the first player,\n\t   navy_positions    file representing the \
positions of the ships.\n");
    }
  return (0);
}

/*
** map.c for map in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Fri Feb  3 19:12:44 2017 Sadisadou
** Last update Fri Feb  3 19:46:10 2017 Sadisadou
*/

#include "navy.h"

char**	map_pos(char** map, char* pos)
{
  char**	posi;

  posi = my_str_to_wordtab(pos, ':');
  my_printf("%s\n", posi[0]);
  return (map);
}

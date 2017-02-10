/*
** free.c for free in /home/sadisadou/PSU/PSU_2016_navy
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Fri Feb  3 19:26:04 2017 Sadisadou
** Last update Fri Feb 10 16:06:33 2017 Sadisadou
*/

#include <stdlib.h>

void    my_free(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

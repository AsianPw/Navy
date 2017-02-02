/*
** core.c for core in /home/sadisadou/PSU/PSU_2016_navy/src
**
** Made by Sadisadou
** Login   <bastien.guillaumat@epitech.eu@epitech.net>
**
** Started on  Thu Feb  2 14:40:53 2017 Sadisadou
** Last update Thu Feb  2 14:43:59 2017 Sadisadou
*/

#include "navy.h"

void    map()
{
  int   i;

  i = 0;
  my_printf(" |A B C D E F G H\n-+---------------\n");
  while (i < 8)
    {
      my_printf("%d|\n", i+1);
      i++;
    }
}

void	aff1()
{
  my_printf("my positions:\n");
  map();
  my_printf("\n\nennemy's positions:\n");
  map();
}

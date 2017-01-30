/*
** my_isneg.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 18:46:53 2017 Brice Lang-Nguyen
** Last update Fri Jan 27 18:49:11 2017 Brice Lang-Nguyen
*/

#include "lib.h"

int	my_isneg(int n)
{
  if (n < 0)
    {
      my_putchar('N');
      return (1);
    }
  else if (n >= 0)
    {
      my_putchar('P');
      return (0);
    }
  return (-1);
}

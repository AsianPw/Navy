/*
** my_power_rec.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 19:27:14 2017 Brice Lang-Nguyen
** Last update Sun Jan 29 01:33:57 2017 Brice Lang-Nguyen
*/

#include "lib.h"

int	my_power_rec(int nb, int power)
{
  int	n1;
  int	n2;

  if (nb < 0)
    return (0);
  if (power == 0)
    return (1);
  n2 = my_power_rec(nb, power - 1);
  n1 = nb * n2;
  if ((n1 / nb) != n2)
    return (0);
  else
    return (n1);
}

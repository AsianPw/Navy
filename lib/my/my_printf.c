/*
** my_printf.c for my_printf in /home/Sadisadou/PSU/PSU_2016_my_printf
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Fri Nov 11 14:02:39 2016 Bastien Guillaumat
** Last update Thu Jan 19 19:14:11 2017 Sadisadou
*/

#include "my_printf.h"
#include <stdio.h>
#include <stdarg.h>

t_flags flags[FLAGS] =
  {
    {'%', aff_perc},
    {'s', aff_str},
    {'S', aff_Str},
    {'c', aff_char},
    {'i', aff_nbr},
    {'d', aff_nbr},
    {'u', aff_uns},
    {'x', aff_hex},
    {'X', aff_heX},
    {'o', aff_oct},
    {'b', aff_bin},
    {'p', aff_point},
    {'e', aff_err},
  };

int	flags_comp(const char *s, int i, va_list arg)
{
  int	j;

  j = 0;
  while (j < FLAGS)
    {
      if (s[i] == flags[j].fonction_name)
	flags[j].fonction(arg);
      j++;
    }
  return (0);
}

int	my_printf(const char *s, ...)
{
  va_list	arg;
  int		i;

  i = 0;
  if (s == NULL)
    {
      my_strerror("String empty");
      return (84);
    }
  va_start(arg, s);
  while (s[i] != '\0')
    {
      if (s[i] == '%' )
	{
	  flags_comp(s, i+1, arg);
	  i++;
	}
      else
	my_putchar(s[i]);
      i++;
    }
  va_end(arg);
  return (0);
}

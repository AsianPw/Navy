/*
** my_putchar.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine/src
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 18:36:20 2017 Brice Lang-Nguyen
** Last update Fri Feb 17 15:55:28 2017 Brice Lang-Nguyen
*/

#include "lib.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
  return ;
}

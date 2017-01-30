/*
** my_putchar.c for my_putchar in /home/Sadisadou/CPool_Day07/lib/my
**
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
**
** Started on  Tue Oct 11 17:25:29 2016 Bastien Guillaumat
** Last update Sat Dec  3 17:26:35 2016 Bastien Guillaumat
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

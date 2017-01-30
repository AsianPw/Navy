/*
** error.c for error in /home/Sadisadou/CPool_infinadd
** 
** Made by Bastien Guillaumat
** Login   <Sadisadou@epitech.net>
** 
** Started on  Fri Oct 28 13:00:12 2016 Bastien Guillaumat
** Last update Fri Oct 28 19:04:54 2016 Bastien Guillaumat
*/

#include <unistd.h>

void	my_error(char c)
{
  write(2, &c, 1);
}

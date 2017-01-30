/*
** error.c for lib_epitech in /home/brice/Documents/lib_epitech_piscine
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Sun Jan 29 00:57:22 2017 Brice Lang-Nguyen
** Last update Sun Jan 29 18:30:00 2017 Brice Lang-Nguyen
*/

#include "lib.h"

void	error(char *msg)
{
  if ((write(2, msg, my_strlen(msg))) == -1)
    exit(84);
  exit(84);
}

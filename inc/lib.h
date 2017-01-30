/*
** lib.h for lib_epitech in /home/brice/Documents/lib_epitech_piscine
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Fri Jan 27 18:40:36 2017 Brice Lang-Nguyen
** Last update Sun Jan 29 21:25:17 2017 Brice Lang-Nguyen
*/

#ifndef __LIB__
#define __LIB__

#include <stdlib.h>
#include <unistd.h>

#define ERROR_WRITE "WRITE : Impossible to write\n"
#define ERROR_CPY "STRCPY : The dest string is lower than src string !\n"
#define ERROR_ALLOC "Problem with alloc\n"

/*----------------------Definition of the boolean------------------------*/

typedef enum
  {
    false,
    true
  } Bool;

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
/*                                                                       */
/*                                                                       */
/*                                                                       */
/*                            Basics function                            */
/*                                                                       */
/*                                                                       */
/*                                                                       */
/*-----------------------------------------------------------------------*/
/*
**  copy a string to another string
**  @param: dest = the destination string
**  @param: src = the original string
**  @return: the new string
*/
char	*my_strcpy(char *dest, char *src);

/*-----------------------------------------------------------------------*/
/*
**  copy n bytes of a string to another string
**  @param: dest = the destination string
**  @param: src = the original string
**  @param: n = number of bytes to copy
**  @return: the new string
*/
char	*my_strncpy(char *dest, char *src, int n);

/*-----------------------------------------------------------------------*/
/*
**  Find a str in another
**  @param: the string to analyze
**  @param: the string to find
**  @return: returns a pointer to the first occurrence
*/
char	*strstr(char *str, char *to_find);

/*-----------------------------------------------------------------------*/
/*
**  reverse a string
**  @param: the string to reverse
**  @return: the reverse string
*/
char	*my_revstr(char *str);

/*-----------------------------------------------------------------------*/
/*
**  check if a int is neg or not
**  @param: nb = the int to check
**  @return: 0 if is positive or 1 if is negative
*/
int	my_isneg(int nb);

/*-----------------------------------------------------------------------*/
/*
**  Converts a character string to an integer
**  @param: str = string to convert
**  @return: convert str to integer or 0 if the string is too large for a int
*/
int	my_getnbr(char *str);

/*-----------------------------------------------------------------------*/
/*
**  Display a integer
**  @param: nb = interger to display
**  @return: nothing
*/
int	my_put_nbr(int nb);

/*-----------------------------------------------------------------------*/
/*
**  Display a string
**  @param: str = string to display
**  @return: nothing
*/
int	my_putstr(char *str);

/*-----------------------------------------------------------------------*/
/*
**  Calcul the power (n) of nb
**  @param: nb = Number to be raised to power
**  @param: power = power to raised the number
**  @return: the number raised to power
*/
int	my_power_rec(int nb, int power);

/*-----------------------------------------------------------------------*/
/*
**  Check if a string is only composed by number
**  @param: str = str to check
**  @return: true if is true, or false if isn't true
*/
int	my_str_isalpha(char *str);

/*-----------------------------------------------------------------------*/
/*
**  Compare 2 string
**  @param: s1 = string to compare
**  @param: s2 = string to find
**  @return: 0 if is true or another integer if false
*/
int	my_strcmp(char *s1, char *s2);

/*-----------------------------------------------------------------------*/
/*
**  Compares n bytes of 2 character strings
**  @param: s1 = string to compare
**  @param: s2 = string to find
**  @return: 0 if is true or another integer if false
*/

int	my_strncmp(char *s1, char *s2, int n);

/*-----------------------------------------------------------------------*/
/*
**  Calcul the length of a string
**  @param: str = string where it is desired to determine the length
**  @return: the length of the string
*/

int	my_strlen(char *str);

/*-----------------------------------------------------------------------*/
/*
**  write a character on the standard output
**  @param: c = character
**  @return: nothing
 */
void	my_putchar(char c);

/*-----------------------------------------------------------------------*/
/*
**  exit the program after write the error msg
**  @param: msg = message error
**  @return: nothing
 */
void	error(char *msg);

/*-----------------------------------------------------------------------*/

#endif /* __LIB__ */

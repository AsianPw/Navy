/*
** crypt.c for navy in /home/brice/Documents/PSU/PSU_2016_navy/test/binary
** 
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
** 
** Started on  Thu Feb  2 22:50:44 2017 Brice Lang-Nguyen
** Last update Thu Feb  2 23:20:42 2017 Brice Lang-Nguyen
*/

int	int_to_bin(int nb)
{
  char	str[20];
  int	rem;
  int	bin;
  int	i;
  int	j;

  bin = 0;
  i = 1;
  j = 0;
  while (nb != 0)
    {
      rem = nb % 2;
      nb = nb / 2;
      bin += (rem * i);
      str[j++] = rem + '0';
      i *= 10;
    }
  //revt_str
  printf("str: %s\n", str);
  return (bin);
}

char	*bin_crypt(int nb)
{
  int	bin;
  
  bin = int_to_bin(nb);
  printf("%i\n", bin);
  return (0);
}

int	main(int argc, char **argv)
{
  bin_crypt(19);
  return (0);
}

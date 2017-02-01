#include <signal.h>
#include <stdio.h>
#include <unistd.h>


int	main(void)
{
  struct sigaction	action;
  int	i;

  i = 0;
  printf("my_pid: %i\n", getpid());
  while (1)
    {
      if (sigaction(SIGUSR1, SIG_IGN, NULL))
	{
	  printf("hey !!! ");
	  i++;
	}
      pause();
    }
  printf("\n\n%i\n", i);
  return (0);
}

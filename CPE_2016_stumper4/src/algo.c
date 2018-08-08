/*
** algo.c for algo in /home/jeremy.elkaim/CPE_2016_stumper4/src
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Wed May 10 15:25:57 2017 jeremy elkaim
** Last update Thu May 11 08:52:40 2017 jeremy elkaim
*/

#include "gol.h"
#include <unistd.h>

void	game(char **av)
{
  int	i;
  int	index;
  int	sidesquare;
  int	t;

  t = 0;
  i = 0;
  index = 0;
  sidesquare = 0;
  while (av[i] != NULL)
    {
      while (av[i][index] != '\0')
	{
	  if (t == 0)
	    {
	      if (av[i + 1] != NULL && av[i + 1][index] == '*')
		{
		  sidesquare = sidesquare + 1;
		}
	      if (av[i][index + 1] == '*')
		{
		  sidesquare = sidesquare + 1;
		}
	      if (i >= 1 && av[i - 1][index + 1] == '*')
		{
		  sidesquare = sidesquare + 1;
		}
	      if (index >= 1 && i >= 1 && av[i - 1][index - 1] == '*')
		{
		  sidesquare = sidesquare + 1;
		}
	      if (av[i + 1] != NULL && av[i + 1][index + 1] == '*')
		{
		  sidesquare = sidesquare + 1;
		}
	      if (index >= 1 && av[i][index - 1] == '*')
		{
		  sidesquare = sidesquare + 1;
		}
	      if (av[i + 1] != NULL && index >= 1
		  && av[i + 1][index - 1] == '*')
		{
		  sidesquare = sidesquare + 1;
		}
	      if (i >= 1 && av[i - 1][index] == '*')
		{
		  sidesquare = sidesquare + 1;
		}
	      t = 1;
	    }
	  else if (t == 1)
	    {
	      if (av[i][index] == '.' && sidesquare == 3)
		{
		  av[i][index] = 'N';
		  index = index + 1;
		  sidesquare = 0;
		}
	      t = 2;
	    }
	  else if (t == 2)
	    {
	      if (av[i][index] == '*' && sidesquare >= 4
		  || av[i][index] == '*' && sidesquare <= 8)
		{
		  av[i][index] = 'M';
		  index = index + 1;
		  sidesquare = 0;
		}
	      if (av[i][index] == '*' && (sidesquare == 0
					  || sidesquare == 1))
		{
		  av[i][index] = 'I';
		  index = index + 1;
		  sidesquare = 0;
		}
	    }
	  else
	    index = index + 1;
	}
      i = i + 1;
    }
}

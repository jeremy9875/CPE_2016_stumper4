/*
** main.c for main in /home/jeremy.elkaim/CPE_2016_stumper4
** 
** Made by jeremy elkaim
** Login   <jeremy.elkaim@epitech.net>
** 
** Started on  Wed May 10 14:25:29 2017 jeremy elkaim
** Last update Wed May 10 17:44:51 2017 jeremy elkaim
*/

#include <unistd.h>
#include <fcntl.h>
#include "gol.h"

int	my_getnbr(char *str)
{
  int	i;
  int	val;

  i = 0;
  val = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  val *= 10;
	  val += str[i] - 48;
	}
      else
	return (0);
      i++;
    }
  return (val);
}

int	parsefile(char **av)
{
  int	fd;
  int	len;
  int	turn;
  char	**tab;

  len = turn = 0;
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (84);
  turn = my_getnbr(av[2]);
  if ((len = read_file(fd)) <= 0)
    return (84);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (84);
  if ((tab = get_tab(fd, len)) == (char **) NULL)
    {
      close(fd);
      return (84);
    }
  else if (turn == 0)
    my_showtab(tab);
  else
    {
      while (turn != 0)
	{
	  game(tab);
	  turn = turn - 1;
	}
      my_showtab(tab);
    }
  close(fd);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 3)
    return (parsefile(av));
  else
    return (84);
  return (0);
}

/*
** str.c for gameoflife in /home/Spiki/Colles/CPE_2016_stumper4/src
** 
** Made by Filliat Etienne
** Login   <Spiki@epitech.net>
** 
** Started on  Wed May 10 14:37:45 2017 Filliat Etienne
** Last update Wed May 10 14:42:40 2017 Filliat Etienne
*/

#include <unistd.h>

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void		my_putstr(int fd, char *str)
{
  write(fd, str, my_strlen(str));
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}


void		my_showtab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(1, tab[i]);
      my_putchar('\n');
      i++;
    }
}

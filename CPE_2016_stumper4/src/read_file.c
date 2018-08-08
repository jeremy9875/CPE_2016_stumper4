/*
** read_file.c for gameoflife in /home/Spiki/Colles/CPE_2016_stumper4/src
** 
** Made by Filliat Etienne
** Login   <Spiki@epitech.net>
** 
** Started on  Wed May 10 12:37:56 2017 Filliat Etienne
** Last update Wed May 10 16:45:59 2017 jeremy elkaim
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "gol.h"

int		get_nb_lines(char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	count++;
      i++;
    }
  return (count);
}

int		get_nb_col(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\n')
    i++;
  return (i);
}

int		read_file(int fd)
{
  int		i;
  int		len;
  int		count;
  char		*buff;

  i = 0;
  count = 0;
  if ((buff = malloc(sizeof(char) * 11)) == NULL)
    return (-1);
  buff[11] = '\0';
  while ((len = read(fd, buff, 10)) != 0)
    {
      while (buff[i] != '\0')
	{
	  count++;
	  i++;
	}
      free(buff);
      buff = malloc(sizeof(char) * 11);
      buff[11] = '\0';
      i = 0;
    }
  free (buff);
  close(fd);
  return (count);
}

char		**make_tab(int line, int col, char *buffer)
{
  int		i;
  int		x;
  int		y;
  char		**tab;

  i = x = y = 0;
  if ((tab = malloc(sizeof(char *) * (line + 1))) == NULL)
    return (NULL);
  if ((tab[0] = malloc(sizeof(char *) * (col + 1))) == NULL)
    return (NULL);
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	{
	  tab[x++][y] = '\0';
	  if ((tab[x] = malloc(sizeof(char *) * (col + 1))) == NULL)
	    return (NULL);
	  i++;

	  y = 0;
	}
      tab[x][y++] = buffer[i++];
    }
  tab[x] = NULL;
  return (tab);
}

char		**get_tab(int fd, int len)
{
  int		line;
  int		col;
  char		**tab;
  char		*buff;

  line = 0;
  col = 0;
  if ((buff = malloc(sizeof(char) * (len + 1))) == NULL)
    return ((char **) NULL);
  buff[len + 1] = '\0';
  if (read(fd, buff, len + 1) == -1)
    return ((char **) NULL);
  line = get_nb_lines(buff);
  col = get_nb_col(buff);
  if ((tab = make_tab(line, col, buff)) != NULL)
    return (tab);
  else
    return ((char **) NULL);
}

/*
** gol.h for gameoflife in /home/Spiki/Colles/CPE_2016_stumper4/include
** 
** Made by Filliat Etienne
** Login   <Spiki@epitech.net>
** 
** Started on  Wed May 10 13:58:31 2017 Filliat Etienne
** Last update Wed May 10 16:45:02 2017 jeremy elkaim
*/

#ifndef GOL_H_
# define GOL_H_

void		my_showtab(char **);
int		get_nb_line(char *);
void		game(char **av);
int		get_nb_col(char *);
int		read_file(int);
char		**make_tab(int, int, char *);
char		**get_tab(int, int);

#endif /* !GOL_H_ */

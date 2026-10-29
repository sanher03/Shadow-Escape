/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 30-11-2020
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "graphic_engine.h"
#include "game.h"
#include "command.h"
#include "game_rules.h"

/**
 * Private functions
 */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);
void game_loop_run(Game **game, Graphic_engine *gengine, FILE *f);
void game_loop_cleanup(Game *game, Graphic_engine *gengine);

/**
 * @brief Receives the arguments and starts the program
 *
 * main Checks the arguments, initializes the game pointer
 * and starts the loop of the game
 *
 * @date Unknown
 * @author: Profesores PPROG
 *
 * @param argc number of arguments
 * @param argv pointer to the strings passed as arguments
 *
 * @return 0, 1 in case of error
 */
int main(int argc, char *argv[])
{
  Game *game = NULL;
  Graphic_engine *gengine;
  FILE *f = NULL;
  Command *cmd = NULL;

  if (argc < 2 || argc == 3 || (argc == 4 && strcmp(argv[2], "-l") != 0))
  {
    fprintf(stderr, "Use: %s <game_data_file> or %s <game_data_file> -l <log_file_name>\n", argv[0], argv[0]);
    return 1;
  }

  if (argc == 4)
  {
    f = fopen(argv[3], "w");
    if (f == NULL)
    {
      fprintf(stderr, "Se produjo un error al intentar abrir el fichero de LOG: %s\n", argv[3]);
      return 1;
    }
  }

  if (game_create(&game) == ERROR)
  {
    return 1;
  }

  if ((cmd = command_create()) == ERROR)
  {
    return 1;
  }

  if (game_set_cmd(game, cmd) == ERROR)
  {
    return ERROR;
  }

  srand(time(NULL));

  if (!game_loop_init(game, &gengine, argv[1]))
  {
    game_loop_run(&game, gengine, f);
    game_loop_cleanup(game, gengine);
  }

  command_destroy(cmd);

  if (argc == 4)
  {
    fclose(f);
  }

  return 0;
}

/**
 * @brief Inititalizes the loop of the game
 *
 * game_loop_init Calls the routine that creates the game from the
 * file and creates the game engine
 *
 * @date Unknown
 * @author: Profesores PPROG
 *
 * @param game pointer to the game structure
 * @param gengine double pointer to the graphic engine to be created
 * @param file_name string containing the name of the data file
 *
 * @return 0, 1 in case of error
 */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name)
{
  if (game_create_from_file(game, file_name) == ERROR)
  {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL)
  {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }

  return 0;
}

/**
 * @brief Runs the game loop
 *
 * game_loop_run Paints the graphic engine that corresponds to the command
 * and updates it when the game is not over and the command differs from EXIT
 *
 * @date Unknown
 * @author: Profesores PPROG
 *
 * @param game pointer to the game structure
 * @param gengine pointer to the graphic engine to be modified
 * @param f pointer to the file
 *
 */
void game_loop_run(Game **game, Graphic_engine *gengine, FILE *f)
{
  int n;
  while ((command_get_cmd(game_get_cmd((*game))) != EXIT))
  {
    graphic_engine_paint_game(gengine, (*game), game_get_cmd((*game)));
    if (game_is_over((*game)))
      break;
    command_get_user_input(game_get_cmd((*game)));
    game_update(game, game_get_cmd((*game)), f);
    if (command_get_status(game_get_cmd(*game)) == OK)
    {
      n = game_get_ncomands((*game));
      n++;
      game_set_ncomands((*game), n);
    }
    game_rules_update((*game));
  }
}

/**
 * @brief Cleans the game loop
 *
 * game_loop_cleanup destroys the game structure and the graphic engine
 *
 * @date Unknown
 * @author: Profesores PPROG
 *
 * @param game pointer to the game structure
 * @param gengine pointer to the graphic engine to be modified
 *
 */
void game_loop_cleanup(Game *game, Graphic_engine *gengine)
{
  game_destroy(game);
  graphic_engine_destroy(gengine);
}

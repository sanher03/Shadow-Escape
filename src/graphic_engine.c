/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "graphic_engine.h"
#include "libscreen.h"
#include "command.h"
#include "space.h"
#include "types.h"
#include "player.h"

#define ROWS 35    /*!< Rows of the game screen*/
#define COLUMNS 150 /*!< Columns of the game screen*/

#define MAX_STR 1005    /*!< Maximum lenght of a string*/
#define ENEMY_STR 7     /*!< Length of the enemy string*/
#define END_MID_SP 29   /*!< End of the space where the player is*/
#define BEGIN_LEFT_SP 9 /*!< Begin of the space to the left*/
#define END_LEFT_SP 15  /*!< End of the space to the left*/
#define ELLIPSES 3      /*!< Suspension points*/
#define END_SP_STR 43   /*!< Last position of the painting of the spaces*/

/**
 * @brief The Graphic_engine structure
 *
 * It stores information of the Graphic_engine
 */
struct _Graphic_engine
{
  Area *map;      /*!< Pointer to the map area*/
  Area *descript; /*!< Pointer to the description area*/
  Area *help;     /*!< Pointer to the help area*/
  Area *feedback; /*!< Pointer to the banner area*/
  Area *objects;  /*!< Pointer to the objects area*/
  Area *title;    /*!< Pointer to the title area*/
  Area *command;  /*!< Pointer to the title area*/ 
};

/**
 * graphic_engine_create Allocates memory for the structure, initializes the screen and all
 * the areas contained in the graphic engine
 */
Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
  {
    return ge;
  }

  screen_init(ROWS, COLUMNS);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
  {
    return NULL;
  }

  ge->map = screen_area_init(1, 1, 79, 25);
  ge->title = screen_area_init(81, 1, 68, 5);
  ge->descript = screen_area_init(81, 7, 33, 19);
  ge->help = screen_area_init(1, 27, 73, 3);
  ge->feedback = screen_area_init(1, 31, 148, 3);
  ge->objects = screen_area_init(75, 27, 74, 3);
  ge->command = screen_area_init(116, 7, 33, 19);

  return ge;
}

/**
 * graphic_engine_destroy Calls the functions that destroy all the areas of the
 * structure and frees the memory allocated
 */
void graphic_engine_destroy(Graphic_engine *ge)
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);
  screen_area_destroy(ge->objects);
  screen_area_destroy(ge->title);
  screen_area_destroy(ge->command);

  screen_destroy();
  free(ge);
}

/**
 * graphic_engine_paint_game Obtains the loccation of the player and prints
 * the areas that surround him and the rest of options that are shown in the game interface
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game, Command *cmd)
{
  Id id_act = NO_ID, id;
  char str[MAX_STR], str_obj[WORD_SIZE], str_aux[WORD_SIZE], **gdesc, string[DLG_LENGHT];
  extern char *cmd_to_str[N_CMD][N_CMDT], *space_to_str[N_STATUS];
  Id *objects;
  int n_obj, i, j;
  Object **g_objs;

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  strcpy(str_aux, "\0");
  for (i = 0; i < GDESC_MAX; i++)
  {
    strcat(str_aux, "-");
  }
  sprintf(str, " +%s+ ", str_aux);
  screen_area_puts(ge->map, str);
  id_act = player_get_location(game_get_player(game));
  if (space_get_light(game_get_space(game, id_act)))
  {
    sprintf(str, " |%s", space_get_name(game_get_space(game, id_act)));
    j = strlen(str);
    for (; j < GDESC_MAX + 2; j++)
    {
      strcat(str, " ");
    }
    strcat(str, "|");
    screen_area_puts(ge->map, str);
    gdesc = space_get_gdesc(game_get_space(game, id_act));
    for (i = 0; i < NUM_GDESC - 1; i++)
    {
      sprintf(str, " |%s", gdesc[i]);
      j = strlen(str);
      for (; j < GDESC_MAX + 2; j++)
      {
        strcat(str, " ");
      }
      strcat(str, "|");
      screen_area_puts(ge->map, str);
    }
  }
  else
  {
    for (i = 0; i < NUM_GDESC; i++)
    {
      sprintf(str, " |");
      j = strlen(str);
      for (; j < GDESC_MAX + 2; j++)
      {
        strcat(str, "*");
      }
      strcat(str, "|");
      screen_area_puts(ge->map, str);
    }
  }
  sprintf(str, " +%s+ ", str_aux);
  screen_area_puts(ge->map, str);

  screen_area_clear(ge->title);
  sprintf(str, "         ___ _  ____ ___ _____  _  _______ _______ ________");
  screen_area_puts(ge->title, str);
  sprintf(str, "         | _\\||_|\\  \\|  \\|   ||| \\ | __\\ _\\| __\\  \\| . \\ __\\");
  screen_area_puts(ge->title, str);
  sprintf(str, "         [__ \\ _ | . \\ . \\ . ||\\ / |  ][__ \\ \\_| . \\ __/  ]_");
  screen_area_puts(ge->title, str);
  sprintf(str, "         |___// |//\\_/___/___//\\/  |___/___/___//\\_//  |___/");
  screen_area_puts(ge->title, str);


  screen_area_clear(ge->command);
  sprintf(str, " Command you can use:");
  screen_area_puts(ge->command, str);
  screen_area_puts(ge->command, " ");
  for (i = EXIT + 1; i < N_CMD; i++)
  {
    sprintf(str, " - %s or %s", cmd_to_str[i][TRUE], cmd_to_str[i][FALSE]);
    screen_area_puts(ge->command, str);
  }

  /* Paint in the objects area */
  screen_area_clear(ge->objects);
  sprintf(str, " Objects in the space: ");
  screen_area_puts(ge->objects, str);
  strcpy(str, " ");
  n_obj = space_get_num_obj(game_get_space(game, id_act));
  objects = space_get_object_set(game_get_space(game, id_act));
  g_objs = game_get_objects(game);
  for (i = 0; i < MAX_OBJECTS; i++)
  {
    for (j = 0; j < n_obj; j++) 
    {
      if (object_get_id(g_objs[i]) == objects[j])
      {
        if (object_get_hidden(g_objs[i]) != TRUE)
        {
          sprintf(str_aux, "- %s    ", object_get_name(g_objs[i]));
          strcat(str, str_aux);
        }
      }
    }
  }
  free(objects);
  screen_area_puts(ge->objects, str);

  /* Paint in the description area */
  
  screen_area_clear(ge->descript);
  sprintf(str, " Player health: %d", player_get_health(game_get_player(game)));
  screen_area_puts(ge->descript, str);
  screen_area_puts(ge->descript, "        ");
  if (enemy_get_health(game_get_enemy(game)) > 0)
  {
    sprintf(str, " Enemy health: %d", enemy_get_health(game_get_enemy(game)));
  }
  else
  {
    sprintf(str, " Enemy: Dead");
  }
  screen_area_puts(ge->descript, str);
  screen_area_puts(ge->descript, "        ");

  n_obj = player_get_num_objects(game_get_player(game));
  objects = player_get_object_set(game_get_player(game));
  if (n_obj > 0)
  {
    sprintf(str, " Inventory:");
    screen_area_puts(ge->descript, str);
    for (i = 0; i < n_obj; i++)
    {
      sprintf(str_obj, " - %s", game_get_obj_name(game, objects[i]));
      screen_area_puts(ge->descript, str_obj);
    }
  }
  else
  {
    sprintf(str, " Inventory: Empty");
    screen_area_puts(ge->descript, str);
  }
  free(objects);
  

  screen_area_clear(ge->help);  
  sprintf(str, " Descriptions:");
  screen_area_puts(ge->help, str);
  sprintf(str, " - %s - %s", space_get_name(game_get_space(game, id_act)), space_get_description(game_get_space(game, id_act)));
  screen_area_puts(ge->help, str);
  if (command_get_cmd(cmd) == INSPECT && command_get_status(cmd) == OK)
  {
    if (!strcasecmp(command_get_name(cmd), space_to_str[DIRS]) || !strcasecmp(command_get_name(cmd), space_to_str[CMDL]))
    {
      if (space_get_light(game_get_space(game, id_act)))
      {
        sprintf(str, " - %s - %s", space_get_name(game_get_space(game, id_act)), space_get_det_descr(game_get_space(game, id_act)));
      }
      else
      {
        sprintf(str, " - You cannot see anything");
      }
    }
    else
    {
      id = game_get_obj_id_with_name(game, command_get_name(cmd));
      if (space_get_light(game_get_space(game, id_act)))
      {
        sprintf(str, " - %s - %s", command_get_name(cmd), object_get_description(game_get_obj(game, id)));
      }
      else
      {
        sprintf(str, " - You cannot see anything");
      }
    }
    screen_area_puts(ge->help, str);
  }  

  /* Paint in the feedback area */
  screen_area_clear(ge->feedback);
  screen_area_puts(ge->feedback, " Actions: ");
  game_get_dialogue(game, string);
  sprintf(str, " - ");
  strcat(str, string);
  screen_area_puts(ge->feedback, str);
  

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}

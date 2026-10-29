/**
 * @brief It implements the routine in charge of loading the spaces
 *
 * @file game_management.c
 * @author Ignacio Sánchez
 * @version 3.0
 * @date 06-02-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_management.h"
#include "space.h"

/**
 * game_management_load_spaces Opens the file and loads the the information read
 * to the spaces of the game
 */
STATUS game_management_load_spaces(Game *game, char *filename)
{
  /*Reads each one of the lines of the data file and initializes
  the space with its corresponding values*/
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "", descr[DESCR_SIZE] = "", det_des[DESCR_SIZE] = "";
  char *toks = NULL, **gdesc;
  Id id = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  int i;
  int light;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  gdesc = space_gdesc_create();


  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      strcpy(descr, toks);
      toks = strtok(NULL, "|");
      strcpy(det_des, toks);  
      toks = strtok(NULL, "|");
      light = atoi(toks);
      for (i = 0; i < NUM_GDESC; i++){  
        toks = strtok(NULL, "@");
        if (strcmp(toks, "\n") == 0) 
        {
          for (; i < NUM_GDESC; i++)
          {
            strcpy(gdesc[i], " ");
          }
          break;
        }
        else if (toks != NULL) {
          strcpy(gdesc[i], toks);
        }
      }
#ifdef DEBUG
      printf("Leido: %ld|%s|%s\n", id, name, gdesc[0]);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_description(space, descr);
        space_set_det_descr(space, det_des);
        space_set_gdesc(space, gdesc);
        space_set_light(space, light);
        game_add_space(game, space);
      }
    }
  }

  space_gdesc_destroy(gdesc);

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/**
 * game_management_load_objects Opens the file and loads the the information read
 * to the objects of the game
 */
STATUS game_management_load_objects(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char description[WORD_SIZE] = "";
  char *toks = NULL;
  Object *object = NULL;
  STATUS status = OK;
  Id id, location, dependency, open;
  Space *space = NULL;
  int hidden, movable, illuminate, turnedon;
  T_ObjType type;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(description, toks);
      toks = strtok(NULL, "|");
      hidden = atoi(toks);
      toks = strtok(NULL, "|");
      movable = atoi(toks);
      toks = strtok(NULL, "|");
      dependency = atol(toks);
      toks = strtok(NULL, "|");
      open = atol(toks);
      toks = strtok(NULL, "|");
      illuminate = atoi(toks);
      toks = strtok(NULL, "|");
      turnedon = atoi(toks);
      toks = strtok(NULL, "|");
      type = atoi(toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, name, location);
#endif

      object = object_create(id);

      if (object != NULL)
      {
        object_set_name(object, name);
        object_set_description(object, description);
        if (location != NO_ID)
        {
          space = game_get_space(game, location);
          space_add_object(space, id);
        }
        else
        {
          player_add_object(game_get_player(game), id);
          printf("Added to the inventory\n");
        }
        object_set_hidden(object, hidden);
        object_set_movable(object, movable);
        object_set_dependency(object, dependency);
        object_set_open(object, open);
        object_set_illuminate(object, illuminate);
        object_set_turnedon(object, turnedon);
        object_set_type(object, type);
        game_add_object(game, object);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/**
 * game_management_load_links Opens the file and loads the the information read
 * to the links of the spaces
 */
STATUS game_management_load_links(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Link *link = NULL;
  STATUS status = OK;
  LINKSTATUS st = OPENED;
  Id id, origin, destination;
  DIRECTION dir;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#l:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      origin = atol(toks);
      toks = strtok(NULL, "|");
      destination = atoi(toks);
      toks = strtok(NULL, "|");
      dir = atoi(toks);
      toks = strtok(NULL, "|");
      st = atoi(toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%d|%d\n", id, name, origin, destination, dir, st);
#endif

      link = link_create(id);

      if (link != NULL)
      {
        link_set_name(link, name);
        link_set_origin(link, origin);
        link_set_destination(link, destination);
        link_set_direction(link, dir);
        link_set_status(link, st);
        game_add_link(game, link);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/**
 * game_management_load_player Opens the file and loads the the information read
 * to the player of the game
 */
STATUS game_management_load_player(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Player *player = NULL;
  STATUS status = OK;
  Id id, location;
  int health = 0, max_objs;
  Inventory *inv = NULL;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#p:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      health = atoi(toks);
      toks = strtok(NULL, "|");
      max_objs = atoi(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%d|%d\n", id, name, location, health, max_objs);
#endif

      player = player_create(id);

      if (player != NULL)
      {
        player_set_name(player, name);
        player_set_location(player, location);
        player_set_health(player, health);
        inv = player_get_inventory(player);
        inventory_set_max_objs(inv, max_objs);
        game_add_player(game, player);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/**
 * game_management_load_enemy Opens the file and loads the the information read
 * to the enemy of the game
 */
STATUS game_management_load_enemy(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Enemy *enemy = NULL;
  STATUS status = OK;
  Id id, location;
  int health = 0;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#e:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      health = atoi(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%d\n", id, name, location, health);
#endif

      enemy = enemy_create(id);

      if (enemy != NULL)
      {
        enemy_set_name(enemy, name);
        enemy_set_location(enemy, location);
        enemy_set_health(enemy, health);
        game_add_enemy(game, enemy);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/**
 * game_management_save Opens the file and saves the current state 
 * of the game into the specified file
 */
STATUS game_management_save (Game *game, const char *filename)
{
  FILE *f;
  int i;
  Object **obj;
  Space **sp;
  Dialogue **dlg;

  f = fopen(filename, "w+");
  if (!f)
  {
    return ERROR;
  }

  player_print_to_save(game_get_player(game), f);
  enemy_print_to_save(game_get_enemy(game), f);
  sp = game_get_spaces(game);
  for (i = 0; i < MAX_SPACES && sp[i] != NULL; i++)
  {
    space_print_to_save(sp[i], f);
  }
  obj = game_get_objects(game);
  for (i = 0; i < MAX_OBJECTS && obj[i] != NULL; i++)
  {
    object_print_to_save(game_get_object_location(game, object_get_id(obj[i])), obj[i], f);
  }
  dlg = game_get_dialogues(game);
  for (i = 0; i < MAX_DLG && dlg[i] != NULL; i++)
  {
    dialogue_print_to_save(dlg[i], f);
  }

  fclose(f);

  return OK;
}


/**
 * game_management_save Opens the file and loads the state 
 * of a game from the specified file
 */
STATUS game_management_load (Game **game, Command *cmd)
{
  if (game_destroy((*game)) == ERROR)
    return ERROR;

  if (game_create(game) == ERROR)
    return ERROR;
  
  if (game_create_from_file((*game), command_get_name(cmd)) == ERROR)
    return ERROR;

  game_set_cmd((*game), cmd);

  return OK;
}

/**
 * game_management_load_dialogues Opens the file and loads the the information read
 * to the dialogues of the game
 */
STATUS game_management_load_dialogues(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char str[DLG_LENGHT] = "";
  char *toks = NULL;
  Dialogue *dlg = NULL;
  STATUS status = OK;
  T_Command cmd;
  int reps;


  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#d:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      cmd = atoi(toks);
      toks = strtok(NULL, "|");
      status = atoi(toks);
      toks = strtok(NULL, "|");
      reps = atoi(toks);
      toks = strtok(NULL, "|");
      strcpy(str, toks);
      
#ifdef DEBUG
      printf("Leido: %d|%d|%s|%d\n", cmd, status, str, reps);
#endif

      dlg = dialogue_create();

      if (dlg != NULL)
      {
        dialogue_set_str(dlg, str);
        dialogue_set_status(dlg, status);
        dialogue_set_cmd(dlg, cmd);
        dialogue_set_reps(dlg, reps);
        game_add_dialogue(game, dlg);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }
  else
  {
    status = OK;
  }

  fclose(file);

  return status;
}


/**
 * @brief It implements the game interface and all the associated calls
 * for each command
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 3.0
 * @date 26-01-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "game.h"
#include "game_management.h"
#include "inventory.h"
#include "object.h"
#include "game_rules.h"

/**
 * @brief The game structure
 *
 * It stores information of the game
 */
struct _Game
{
  Player *player;               /*!< Pointer to the player structure that stores the info of the game's player */
  Object *objects[MAX_OBJECTS]; /*!< Array of that contains all the objects of the game*/
  Space *spaces[MAX_SPACES];    /*!< Array of pointers to space structures which contains all the spaces the game manages*/
  Enemy *enemy;                 /*!< Pointer to the player structure that stores the info of the game's enemy */
  Command *cmd;                 /*!< Pointer to the command of the game*/
  Dialogue *dlg[MAX_DLG];       /*!< Array that contains all the posible dialogues*/
  int ncommands;                /*!< Number of commands executed */
};

/**
   Private functions
*/
Id game_get_space_id_at(Game *game, int position);

/**
 * @brief executes the routine to do if unknown is introduced
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_unknown(Game *game, Command *command);

/**
 * @brief executes the routine to do if exit is introduced
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_exit(Game *game, Command *command);

/**
 * @brief executes the routine to do if take is introduced
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_take(Game *game, Command *command);

/**
 * @brief executes the routine to do if drop is introduced
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_drop(Game *game, Command *command);

/**
 * @brief executes the routine to do if attack is introduced
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_attack(Game *game, Command *command);

/**
 * @brief executes the routine to do if shoot is introduced
 * @author: Fabio Desio
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_shoot(Game *game, Command *command);

/**
 * @brief executes the routine to do if stab is introduced
 * @author: Fabio Desio
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_stab(Game *game, Command *command);

/**
 * @brief executes the routine to do if move is introduced
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_move(Game *game, Command *command);

/**
 * @brief executes the routine to do if inspect is introduced
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_inspect(Game *game, Command *command);

/**
 * @brief executes the routine to drop depencencies
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param dep Id of the object dependency
 * @param command pointer to the command
 * @return void
 */
void _game_command_drop_dependencies(Game *game, Id dep, Command *command);

/**
 * @brief executes the routine to do if turnon is introduced
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_turnon(Game *game, Command *command);

/**
 * @brief executes the routine to do if turnoff is introduced
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_turnoff(Game *game, Command *command);

/**
 * @brief executes the routine to do if open is introduced
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_open(Game *game, Command *command);

/**
 * @brief executes the routine to do if save is introduced
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_save(Game *game, Command *command);

/**
 * @brief executes the routine to do if load is introduced
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param command pointer to the command
 * @return void
 */
void game_command_load(Game **game, Command *command);

/**
   Game interface implementation
*/

/**
 * game_create Allocates memory for the data structure by calling to create functions of its fields and initializes them
 */
STATUS game_create(Game **game)
{
  int i;

  (*game) = (Game *)malloc(sizeof(Game));
  if (game == NULL)
  {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES; i++)
  {
    (*game)->spaces[i] = NULL;
  }

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    (*game)->objects[i] = NULL;
  }

  for (i = 0; i < MAX_DLG; i++)
  {
    (*game)->dlg[i] = NULL;
  }

  (*game)->player = NULL;
  (*game)->enemy = NULL;
  (*game)->cmd = NULL;
  (*game)->ncommands = 0;

  return OK;
}

/**
 * game_create_from_file Creates game from external file and locates player and object
 */
STATUS game_create_from_file(Game *game, char *filename)
{
  if (game == NULL)
  {
    return ERROR;
  }

  if (game_management_load_spaces(game, filename) == ERROR)
  {
    return ERROR;
  }

  if (game_management_load_links(game, filename) == ERROR)
  {
    return ERROR;
  }

  if (game_management_load_player(game, filename) == ERROR)
  {
    return ERROR;
  }

  if (game_management_load_objects(game, filename) == ERROR)
  {
    return ERROR;
  }

  if (game_management_load_enemy(game, filename) == ERROR)
  {
    return ERROR;
  }

  if (game_management_load_dialogues(game, filename) == ERROR)
  {
    return ERROR;
  }

  return OK;
}

STATUS game_set_cmd(Game *game, Command *cmd)
{
  if (game == NULL || cmd == NULL)
    return ERROR;

  game->cmd = cmd;

  return OK;
}

/**
 * game_destroy Destroys data structure by calling destroy functions of its fields
 */
STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    object_destroy(game->objects[i]);
  }

  for (i = 0; i < MAX_DLG && game->dlg[i] != NULL; i++)
  {
    dialogue_destroy(game->dlg[i]);
  }

  player_destroy(game->player);

  enemy_destroy(game->enemy);

  game->cmd = NULL;

  free(game);

  return OK;
}

/**
 * game_get_cmd acceses the structure and gets the command
 */
Command *game_get_cmd(Game *game)
{
  if (game == NULL)
  {
    return NULL;
  }

  return game->cmd;
}

/**
 * game_get_enemy acceses the structure and gets the enemy
 */
Enemy *game_get_enemy(Game *game)
{
  if (game == NULL)
  {
    return NULL;
  }

  return game->enemy;
}

/**
 * game_get_player acceses the structure and gets the player
 */
Player *game_get_player(Game *game)
{
  if (game == NULL)
  {
    return NULL;
  }

  return game->player;
}

/**
 * game_get_ncommands acceses the structure and gets the player
 */
int game_get_ncomands(Game *game)
{
  if (game == NULL)
  {
    return -1;
  }

  return game->ncommands;
}

STATUS game_set_ncomands(Game *game, int ncomands)
{
  if (game == NULL || ncomands < 0)
  {
    return ERROR;
  }

  game->ncommands = ncomands;

  return OK;
}

/**
 * game_get_object_with_name loops through the objects of the game to find the one with the given name
 */
Id game_get_object_with_name(Game *game, char *name)
{
  int i;

  if (game == NULL || name == NULL)
  {
    return NO_ID;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (strcmp(object_get_name(game->objects[i]), name) == 0)
    {
      return object_get_id(game->objects[i]);
    }
  }

  return NO_ID;
}

/**
 * game_get_space_id_at Gets an space's id upon its position
 */
Id game_get_space_id_at(Game *game, int position)
{
  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

/**
 * game_get_space Gets an space in the game upon its id
 */
Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID || game == NULL)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

/**
 * game_get_object_location Gets the object's location id in the game using an appropiate getter function
 */
Id game_get_object_location(Game *game, Id object)
{
  int i = 0;

  if (game == NULL)
  {
    return NO_ID;
  }

  /*Check the spaces to see where the object is*/
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_has_object_id(game->spaces[i], object) == TRUE)
    {
      return space_get_id(game->spaces[i]);
    }
  }

  return NO_ID;
}

/**
 * game_update Changes the game's actions upon different commands
 */
STATUS game_update(Game **game, Command *cmd, FILE *f)
{
  extern char *status_to_str[N_STATUS], *dir_to_str[N_DIR][N_CMDT];
  DIRECTION dir;
  int i;

  if (game == NULL)
  {
    return ERROR;
  }

  switch (command_get_cmd(cmd))
  {
  case UNKNOWN:
    game_command_unknown((*game), cmd);
    if (f != NULL)
    {
      fprintf(f, "unknown: %s\n", status_to_str[command_get_status(cmd)]);
    }
    break;

  case EXIT:
    game_command_exit((*game), cmd);
    if (f != NULL)
    {
      fprintf(f, "exit: %s\n", status_to_str[command_get_status(cmd)]);
    }
    break;

  case TAKE:
    game_command_take((*game), cmd);
    if (f != NULL)
    {
      fprintf(f, "take %s: %s\n", command_get_name(cmd), status_to_str[command_get_status(cmd)]);
    }
    break;

  case DROP:
    game_command_drop((*game), cmd);
    if (f != NULL)
    {
      fprintf(f, "drop %s: %s\n", command_get_name(cmd), status_to_str[command_get_status(cmd)]);
    }
    break;

  case ATTACK:
    game_command_attack((*game), cmd);
    if (f != NULL)
    {
      fprintf(f, "attack: %s\n", status_to_str[command_get_status(cmd)]);
    }
    break;

  case SHOOT:
    game_command_shoot((*game), cmd);
    if (f != NULL)
    {
      fprintf(f, "shoot: %s\n", status_to_str[command_get_status(cmd)]);
    }
    break;

  case STAB:
    game_command_stab((*game), cmd);
    if (f != NULL)
    {
      fprintf(f, "stab: %s\n", status_to_str[command_get_status(cmd)]);
    }
    break;

  case MOVE:
    game_command_move((*game), cmd);
    if (f != NULL)
    {
      dir = UNKN;
      while (dir == UNKN && i < N_DIR)
      {
        if (!strcasecmp(command_get_name(cmd), dir_to_str[i][DIRS]) || !strcasecmp(command_get_name(cmd), dir_to_str[i][CMDL]))
        {
          dir = i + N;
          fprintf(f, "move %s: %s\n", dir_to_str[i][CMDL], status_to_str[command_get_status(cmd)]);
        }
        else
        {
          i++;
        }
      }
      if (i == N_DIR)
      {
        fprintf(f, "move %s: %s\n", command_get_name(cmd), status_to_str[command_get_status(cmd)]);
      }
    }
    break;

  case INSPECT:
    game_command_inspect((*game), cmd);
    if (f != NULL)
    {
      fprintf(f, "inspect %s: %s\n", command_get_name(cmd), status_to_str[command_get_status(cmd)]);
    }
    break;

  case TURNON:
    game_command_turnon((*game), cmd);
    if (f != NULL)
    {
      fprintf(f, "turnon %s: %s\n", command_get_name(cmd), status_to_str[command_get_status(cmd)]);
    }
    break;

  case TURNOFF:
    game_command_turnoff((*game), cmd);
    if (f != NULL)
    {
      fprintf(f, "turnoff %s: %s\n", command_get_name(cmd), status_to_str[command_get_status(cmd)]);
    }
    break;

  case OPEN:
    game_command_open((*game), cmd);
    if (f != NULL)
    {
      fprintf(f, "open %s with %s: %s\n", command_get_link(cmd), command_get_name(cmd), status_to_str[command_get_status(cmd)]);
    }
    break;

  case SAVE:
    game_command_save((*game), cmd);
    if (f != NULL)
    {
      fprintf(f, "save %s: %s\n", command_get_name(cmd), status_to_str[command_get_status(cmd)]);
    }
    break;

  case LOAD:
    game_command_load(game, cmd);
    if (f != NULL)
    {
      fprintf(f, "load %s: %s\n", command_get_name(cmd), status_to_str[command_get_status(cmd)]);
    }
    break;

  default:
    break;
  }

  return OK;
}

/**
 * game_print_data Prints the basic game design and calls other print functions
 */
void game_print_data(Game *game)
{
  int i = 0;

  if (game == NULL)
  {
    return;
  }

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  player_print(game->player);

  return;
}

/**
 * game_is_over Checks if the game has finished
 */
BOOL game_is_over(Game *game)
{
  /*Error control*/
  if (game == NULL)
  {
    return FALSE;
  }

  if (player_get_health(game->player) == 0)
  {
    fprintf(stdout, "\n\n\n---- You have died.\n");
    fprintf(stdout, "---- ¡¡¡GAME OVER!!! \n");
    return TRUE;
  }
  else if (player_get_location(game->player) == 30)
  {
    fprintf(stdout, "\n\n\n---- You have got the information and you have escaped.\n");
    fprintf(stdout, "---- ¡¡¡YOU HAVE COMPLETED THE GAME!!! \n");
    return TRUE;
  }
  else if (game->ncommands > 100)
  {
    fprintf(stdout, "\n\n\n---- The time has expired. You couldn't sabe millions of people.\n");
    fprintf(stdout, "---- ¡¡¡GAME OVER!!! \n");
    return TRUE;
  }

  return FALSE;
}

/**
   Calls implementation for each action
*/

/**
 * game_command_unknown the command could not be identified
 */
void game_command_unknown(Game *game, Command *command)
{
  /*Error control*/
  if (game == NULL || command == NULL)
  {
    return;
  }

  command_set_status(command, ERROR);
}

/**
 * game_command_unknown the user has exited the game
 */
void game_command_exit(Game *game, Command *command)
{
  /*Error control*/
  if (game == NULL || command == NULL)
  {
    return;
  }
}

/**
 * game_command_take Makes the player take the object in the game
 */
void game_command_take(Game *game, Command *command)
{
  /*Gets the location of the player, checks if the player has an object, gets the id of
  the object if the space has one, and sets the player's object to it while setting the
  object of the space to NO_ID*/

  int i;
  Object *obj;
  Inventory *inv;
  Id space_id = NO_ID, id, dep;

  space_id = player_get_location(game->player);

  if (NO_ID == space_id)
  {
    command_set_status(command, ERROR);
    return;
  }

  id = game_get_obj_id_with_name(game, command_get_name(command));

  if (space_has_object_id(game_get_space(game, space_id), id) == FALSE)
  {
    command_set_status(command, ERROR);
    return;
  }

  /* We identify the object */
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (object_get_id(game->objects[i]) == id)
    {
      break;
    }
  }

  obj = game->objects[i];

  /* Check if the object is movable */
  if (object_get_movable(obj) == FALSE)
  {
    command_set_status(command, ERROR);
    return;
  }

  inv = player_get_inventory(game->player);

  /* Check for dependencies */
  dep = object_get_dependency(obj);

  if ((inventory_has_obj(inv, dep) == FALSE) && dep != NO_ID)
  {
    command_set_status(command, ERROR);
    return;
  }

  if (player_add_object(game->player, id) == ERROR)
  {
    command_set_status(command, ERROR);
    return;
  }

  space_del_object(game_get_space(game, space_id), id);

  command_set_status(command, OK);

  return;
}

/**
 * game_get_obj_id_with_name Loops trough the game objects to
 * find the id of the object with the given name
 */
Id game_get_obj_id_with_name(Game *game, const char *name)
{
  int i;

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (strcasecmp(object_get_name(game->objects[i]), name) == 0)
    {
      return object_get_id(game->objects[i]);
    }
  }

  return NO_ID;
}

/**
 *  _game_command_drop_dependencies Drops further object dependencies by looping
 *  through them
 */
void _game_command_drop_dependencies(Game *game, Id dep, Command *command)
{
  int i;
  Id space_id = NO_ID, dep2;
  Object *obj;

  if (dep == NO_ID)
  {
    return;
  }

  space_id = player_get_location(game->player);

  if (space_id == NO_ID)
  {
    return;
  }

  /* We get the object of the dependency */
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (object_get_dependency(game->objects[i]) == dep)
    {
      if (!inventory_has_obj(player_get_inventory(game->player), object_get_id(game->objects[i])))
      {
        return;
      }
    
      obj = game->objects[i];
    
      /* We check for further dependencies and drop them recursively */
      dep2 = object_get_id(obj);
    
      if (dep2 != NO_ID)
      {
        _game_command_drop_dependencies(game, dep2, command);
      }
    
      space_add_object(game_get_space(game, space_id), dep2);
    
      player_del_object(game->player, dep2);
    }
  }

  command_set_status(command, OK);

  return;
}

/**
 * game_command_drop Makes the player drop the object in the game
 */
void game_command_drop(Game *game, Command *command)
{
  /*Gets the location of the player, checks if the player has an object and gets the id of
  the object if the player has one. Lastly, checks that the space has no objects and sets
  the player's object to NO_ID while setting the object of the space to the id of the object*/
  int i;
  Id id, space_id = NO_ID;

  space_id = player_get_location(game->player);

  if (NO_ID == space_id)
  {
    command_set_status(command, ERROR);
    return;
  }

  id = game_get_obj_id_with_name(game, command_get_name(command));

  if (!inventory_has_obj(player_get_inventory(game->player), id))
  {
    command_set_status(command, ERROR);
    return;
  }

  /* We get the object */
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (object_get_id(game->objects[i]) == id)
    {
      break;
    }
  }

  /* Check for dependencies */
  
  _game_command_drop_dependencies(game, id, command);

  space_add_object(game_get_space(game, space_id), id);

  player_del_object(game->player, id);

  command_set_status(command, OK);

  return;
}
/**
 * game_command_attack genereates a random number between 0 and 9,
 * if the number is greater than 4 the the player wins, otherwise he loses
 */
void game_command_attack(Game *game, Command *command)
{
  int n, hp;

  if (player_get_location(game->player) != enemy_get_location(game->enemy))
  {
    command_set_status(command, ERROR);
    return;
  }

  if (enemy_get_health(game->enemy) == 0)
  {
    command_set_status(command, ERROR);
    return;
  }

  n = rand();

  n %= 10;

  #ifdef DEBUG
      n = 5;
  #endif

  if (n > 4)
  {
    hp = enemy_get_health(game->enemy) - 1;
    enemy_set_health(game->enemy, hp);
  }
  else
  {
    hp = player_get_health(game->player) - 1;
    player_set_health(game->player, hp);
  }

  command_set_status(command, OK);

  return;
}

/**
 * game_command_shoot genereates a random number between 0 and 9,
 * if the number is greater than 2 the the player kills the enemy, otherwise he loses
 */
void game_command_shoot(Game *game, Command *command)
{
  int n, hp, i;

  if (player_get_location(game->player) != enemy_get_location(game->enemy))
  {
    command_set_status(command, ERROR);
    return;
  }

  if (enemy_get_health(game->enemy) == 0)
  {
    command_set_status(command, ERROR);
    return;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (object_get_type(game->objects[i]) == GUN)
    {
      break;
    }
  }

  /* todo: números mágicos */
  if (inventory_has_obj(player_get_inventory(game->player), object_get_id(game->objects[i])) == FALSE)
  {
    command_set_status(command, ERROR);
    return;
  }

  n = rand();

  n %= 10;

  #ifdef DEBUG
      n = 3;
  #endif

  if (n > 2)
  {
    hp = 0;
    enemy_set_health(game->enemy, hp);
  }
  else
  {
    hp = player_get_health(game->player) - 1;
    player_set_health(game->player, hp);
  }

  command_set_status(command, OK);

  return;
}

/**
 * game_command_stab genereates a random number between 0 and 9,
 * if the number is greater than 4 the the player stabs the enemy, otherwise he loses
 */
void game_command_stab(Game *game, Command *command)
{
  int n, hp, i;

  if (player_get_location(game->player) != enemy_get_location(game->enemy))
  {
    command_set_status(command, ERROR);
    return;
  }

  if (enemy_get_health(game->enemy) == 0)
  {
    command_set_status(command, ERROR);
    return;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (object_get_type(game->objects[i]) == KNIFE)
    {
      break;
    }
  }

  /* todo: números mágicos */
  if (inventory_has_obj(player_get_inventory(game->player), object_get_id(game->objects[i])) == FALSE)
  {
    command_set_status(command, ERROR);
    return;
  }

  n = rand();

  n %= 10;

  #ifdef DEBUG
      n = 5;
  #endif

  if (n > 4)
  {
    hp = enemy_get_health(game->enemy) - 3;
    if (hp <= 0)
    {
      hp = 0;
    }
    enemy_set_health(game->enemy, hp);
  }
  else
  {
    hp = player_get_health(game->player) - 1;
    player_set_health(game->player, hp);
  }

  command_set_status(command, OK);

  return;
}

/**
 * game_add_spaces Reaches the last postition of the space array and
 * assigns it to the space passed as argument
 */
STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;

  if (space == NULL || game == NULL)
  {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

/**
 * game_add_object Reaches the last postition of the object array and
 * assigns it to the object passed as argument
 */
STATUS game_add_object(Game *game, Object *object)
{
  int i = 0;

  if (game == NULL || object == NULL)
  {
    return ERROR;
  }

  while (i < MAX_OBJECTS && game->objects[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->objects[i] = object;

  return OK;
}

/**
 * game_add_dialogue Reaches the last postition of the dialogue array and
 * assigns it to the dialogue passed as argument
 */
STATUS game_add_dialogue(Game *game, Dialogue *dialogue)
{
  int i = 0;

  if (game == NULL || dialogue == NULL)
  {
    return ERROR;
  }

  while (i < MAX_DLG && game->dlg[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_DLG)
  {
    return ERROR;
  }

  game->dlg[i] = dialogue;

  return OK;
}

/**
 * game_add_player Assigns the player pointer of the game
 * to the player passed as argument
 */
STATUS game_add_player(Game *game, Player *player)
{
  if (game == NULL || player == NULL)
  {
    return ERROR;
  }

  game->player = player;

  return OK;
}

/**
 * game_add_enemy Assigns the enemy pointer of the game
 * to the enemy passed as argument
 */
STATUS game_add_enemy(Game *game, Enemy *enemy)
{
  if (game == NULL || enemy == NULL)
  {
    return ERROR;
  }

  game->enemy = enemy;

  return OK;
}

/**
 * game_add_link Assigns the link pointer of the argument to the
 * space link that corresponds
 */
STATUS game_add_link(Game *game, Link *link)
{
  int i;

  if (game == NULL || link == NULL)
  {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_get_id(game->spaces[i]) == link_get_origin(link))
    {
      space_add_link(game->spaces[i], link);
      return OK;
    }
  }

  return ERROR;
}

/**
 * game_get_objects_ids_in_map counts the number of enemies not possesed
 * by the player and allocates memory for an array that stores all the
 * corresponding ids
 */
Id *game_get_objects_ids_in_map(Game *game, int *i)
{
  int j, k, num, flag = 0, n;
  Id *objs, *objects;

  if (game == NULL)
  {
    return NULL;
  }

  (*i) = 0;
  k = 0;

  num = player_get_num_objects(game->player);

  objects = player_get_object_set(game->player);

  while (game->objects[k] != NULL)
  {
    for (j = 0, flag = 0; j < num; j++)
    {
      if (object_get_id(game->objects[k]) == objects[j])
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
    {
      (*i)++;
    }
    k++;
  }

  if ((*i) == 0)
  {
    return NULL;
  }

  objs = (Id *)malloc((*i) * sizeof(Id));

  if (objs == NULL)
  {
    return NULL;
  }

  j = 0;
  k = 0;
  n = 0;

  while (game->objects[j] != NULL)
  {
    for (k = 0, flag = 0; k < num; k++)
    {
      if (object_get_id(game->objects[j]) == objects[k])
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
    {
      objs[n] = object_get_id(game->objects[j]);
      n++;
    }
    j++;
  }

  free(objects);

  return objs;
}

/**
 * game_get_connection_status checks if the link of a determined direction
 * is closed or opened
 */
LINKSTATUS game_get_connection_status(Game *game, Id space_act, DIRECTION direction)
{
  Space *space = NULL;
  Link *link = NULL;
  LINKSTATUS st;

  if (game == NULL || space_act == NO_ID)
  {
    return CLOSED;
  }

  space = game_get_space(game, space_act);

  link = space_get_link_with_direction(space, direction);

  st = link_get_status(link);

  return st;
}

/**
 * game_get_connection returns the id of the space that is connected to the
 * origin by the given direction
 */
Id game_get_connection(Game *game, Id space_act, DIRECTION direction)
{
  Space *space = NULL;
  Link *link = NULL;
  Id dest;

  if (game == NULL || space_act == NO_ID)
  {
    return NO_ID;
  }

  space = game_get_space(game, space_act);

  link = space_get_link_with_direction(space, direction);

  dest = link_get_destination(link);

  return dest;
}

/**
 * game_get_obj loops through the objects of the game and returns the object with the given id
 */
Object *game_get_obj(Game *game, Id obj_id)
{
  int i;

  if (obj_id == NO_ID || game == NULL)
  {
    return NULL;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (object_get_id(game->objects[i]) == obj_id)
    {
      return game->objects[i];
    }
  }

  return NULL;
}

/**
 * game_get_obj_name loops through the objects of the game and returns the name of the object with the given id
 */
char *game_get_obj_name(Game *game, Id obj_id)
{
  int i;

  if (obj_id == NO_ID || game == NULL)
  {
    return NULL;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (object_get_id(game->objects[i]) == obj_id)
    {
      return object_get_name(game->objects[i]);
    }
  }

  return NULL;
}

/**
 * game_command_move generic command to move the player in any direction asked
 */
void game_command_move(Game *game, Command *command)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  extern char *dir_to_str[N_DIR][N_CMDT];
  DIRECTION dir;
  int i = 0, j = 0, n_obj, light = 0;
  Id *set;

  space_id = player_get_location(game->player);

  if (NO_ID == space_id)
  {
    command_set_status(command, ERROR);
    return;
  }

  dir = UNKN;
  while (dir == UNKN && i < N_DIR)
  {
    if (!strcasecmp(command_get_name(command), dir_to_str[i][DIRS]) || !strcasecmp(command_get_name(command), dir_to_str[i][CMDL]))
    {
      dir = i + N;
    }
    else
    {
      i++;
    }
  }

  if (game_get_connection_status(game, space_id, dir) == CLOSED)
  {
    command_set_status(command, ERROR);
    return;
  }

  set = space_get_object_set(game_get_space(game, space_id));
  n_obj = space_get_num_obj(game_get_space(game, space_id));
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    for (j = 0; j < n_obj; j++)
    {
      if (object_get_id(game->objects[i]) == set[j] && object_get_movable(game->objects[i]) == FALSE && object_get_illuminate(game->objects[i]) == TRUE && object_get_turnedon(game->objects[i]) == TRUE)
      {
        light = 1;
      }
    }
  }
  free(set);

  current_id = game_get_connection(game, space_id, dir);
  if (current_id != NO_ID)
  {
    player_set_location(game->player, current_id);
    command_set_status(command, OK);
    if (!light)
    {
      set = player_get_object_set(game->player);
      n_obj = player_get_num_objects(game->player);
      for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
      {
        for (j = 0; j < n_obj; j++)
        {
          if (object_get_id(game->objects[i]) == set[j] && object_get_illuminate(game->objects[i]) == TRUE && object_get_turnedon(game->objects[i]) == TRUE)
          {
            space_set_light(game_get_space(game, space_id), FALSE);
            space_set_light(game_get_space(game, current_id), TRUE);
          }
        }
      }
      free(set);
    }
  }
  else
  {
    command_set_status(command, ERROR);
  }

  return;
}

/**
 * game_command_inspect command to inspect either an object or a space
 */
void game_command_inspect(Game *game, Command *command)
{
  Id id = NO_ID;
  Id space_id, *set;
  extern char *space_to_str[N_CMDT];
  int n_obj = 0, i, j;

  space_id = player_get_location(game->player);

  if (NO_ID == space_id)
  {
    command_set_status(command, ERROR);
    return;
  }

  if (!strcasecmp(command_get_name(command), space_to_str[DIRS]) || !strcasecmp(command_get_name(command), space_to_str[CMDL]))
  {
    set = space_get_object_set(game_get_space(game, space_id));
    n_obj = space_get_num_obj(game_get_space(game, space_id));
    for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
    {
      for (j = 0; j < n_obj; j++)
      {
        if (object_get_id(game->objects[i]) == set[j])
        {
          object_set_hidden(game->objects[i], FALSE);
        }
      }
    }
    free(set);

    command_set_status(command, OK);
    return;
  }

  id = game_get_obj_id_with_name(game, command_get_name(command));

  if (inventory_has_obj(player_get_inventory(game->player), id) == FALSE && space_has_object_id(game_get_space(game, space_id), id) == FALSE)
  {
    command_set_status(command, ERROR);
    return;
  }

  command_set_status(command, OK);
  return;
}

/**
 * game_command_turnon checks if an object can be turned on and lights it up
 */
void game_command_turnon(Game *game, Command *command)
{
  Id space_id, id;
  int i;
  BOOL illuminate;

  space_id = player_get_location(game->player);

  if (NO_ID == space_id)
  {
    command_set_status(command, ERROR);
    return;
  }

  id = game_get_obj_id_with_name(game, command_get_name(command));

  if (!inventory_has_obj(player_get_inventory(game->player), id) && space_has_object_id(game_get_space(game, space_id), id) == FALSE)
  {
    command_set_status(command, ERROR);
    return;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (object_get_id(game->objects[i]) == id)
    {
      break;
    }
  }

  illuminate = object_get_illuminate(game->objects[i]);

  if (illuminate == FALSE)
  {
    command_set_status(command, ERROR);
    return;
  }

  if (!inventory_has_obj(player_get_inventory(game->player), id) && object_get_movable(game->objects[i]) == TRUE)
  {
    command_set_status(command, ERROR);
    return;
  }

  if (object_get_turnedon(game->objects[i]) == FALSE)
  {
    object_set_turnedon(game->objects[i], TRUE);
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
      if (space_get_id(game->spaces[i]) == space_id)
      {
        break;
      }
    }
    space_set_light(game->spaces[i], TRUE);
    command_set_status(command, OK);
  }
  else
  {
    command_set_status(command, ERROR);
  }

  return;
}

/**
 * game_command_turnoff checks and turns off an object if it can be done
 */
void game_command_turnoff(Game *game, Command *command)
{
  Id space_id, id;
  int i;
  BOOL illuminate;

  space_id = player_get_location(game->player);

  if (NO_ID == space_id)
  {
    command_set_status(command, ERROR);
    return;
  }

  id = game_get_obj_id_with_name(game, command_get_name(command));

  if (!inventory_has_obj(player_get_inventory(game->player), id) && space_has_object_id(game_get_space(game, space_id), id) == FALSE)
  {
    command_set_status(command, ERROR);
    return;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (object_get_id(game->objects[i]) == id)
    {
      break;
    }
  }

  illuminate = object_get_illuminate(game->objects[i]);

  if (illuminate == FALSE)
  {
    command_set_status(command, ERROR);
    return;
  }

  if (object_get_turnedon(game->objects[i]) == TRUE)
  {
    object_set_turnedon(game->objects[i], FALSE);
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
      if (space_get_id(game->spaces[i]) == space_id)
      {
        break;
      }
    }
    space_set_light(game->spaces[i], FALSE);
    command_set_status(command, OK);
  }
  else
  {
    command_set_status(command, ERROR);
  }

  return;
}

/**
 * game_command_open checks and opens a links if it is closed
 */
void game_command_open(Game *game, Command *command)
{
  Id space_id, id;
  int i;
  Link *l;

  space_id = player_get_location(game->player);

  if (NO_ID == space_id)
  {
    command_set_status(command, ERROR);
    return;
  }

  id = game_get_obj_id_with_name(game, command_get_name(command));

  if (id == NO_ID)
  {
    command_set_status(command, ERROR);
    return;
  }

  if (!inventory_has_obj(player_get_inventory(game->player), id))
  {
    command_set_status(command, ERROR);
    return;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    if (object_get_id(game->objects[i]) == id)
    {
      break;
    }
  }

  l = space_get_link_with_name(game_get_space(game, space_id), command_get_link(command));

  if (object_get_open(game->objects[i]) == NO_ID || object_get_open(game->objects[i]) != link_get_id(l))
  {
    command_set_status(command, ERROR);
    return;
  }

  link_set_status(l, OPENED);
  command_set_status(command, OK);

  return;
}

/**
 * game_command_save save the state of the game into a file
 */
void game_command_save(Game *game, Command *command)
{
  command_set_status(command, game_management_save(game, command_get_name(command)));
}

/**
 * game_command_load loads the state of a game from a fiven file
 */
void game_command_load(Game **game, Command *command)
{
  command_set_status(command, game_management_load(game, command));
}

/**
 * game_get_spaces returns the array of space in the game
 */
Space **game_get_spaces(Game *game)
{
  if (game == NULL)
  {
    return NULL;
  }

  return game->spaces;
}

/**
 * game_get_objects returns the array of object in the game
 */
Object **game_get_objects(Game *game)
{
  if (game == NULL)
  {
    return NULL;
  }

  return game->objects;
}

/**
 * game_get_dialogue loops through the game dialogues and returns the str with the corresponding dialogue
 */
STATUS game_get_dialogue(Game *game, char *str)
{
  int i, j, k;
  char *str_aux;
  extern char *dir_to_str[N_DIR][N_CMDT];
  DIRECTION dir;

  if (game == NULL || str == NULL)
    return ERROR;

  for (i = 0; i < MAX_DLG && game->dlg[i] != NULL; i++)
  {
    if (command_get_cmd(game->cmd) == dialogue_get_cmd(game->dlg[i]) && command_get_status(game->cmd) == dialogue_get_status(game->dlg[i]) && command_get_reps(game->cmd) == dialogue_get_reps(game->dlg[i]))
    {
      str_aux = dialogue_get_str(game->dlg[i]);
      break;
    }
  }

  strcpy(str, "\0");
  for (i = 0, k = 0; (size_t)k < strlen(str_aux); i++, k++)
  {
    if (str_aux[k] == '*')
    {
      if (command_get_cmd(game->cmd) == MOVE)
      {
        dir = UNKN;
        j = 0;
        while (dir == UNKN && j < N_DIR)
        {
          if (!strcasecmp(command_get_name(game->cmd), dir_to_str[j][DIRS]) || !strcasecmp(command_get_name(game->cmd), dir_to_str[j][CMDL]))
          {
            dir = j + N;
            strcat(str, dir_to_str[j][CMDL]);
          }
          else
          {
            j++;
          }
        }
      }
      else if (command_get_cmd(game->cmd) == INSPECT)
      {
        strcat(str, space_get_name(game_get_space(game, player_get_location(game->player))));
      }
      else
      {
        strcat(str, command_get_name(game->cmd));
      }
    }
    else if (str_aux[k] == '#')
    {
      strcat(str, command_get_link(game->cmd));
      i += strlen(command_get_link(game->cmd)) - 1;
    }
    else
    {
      strcat(str, &str_aux[k]);
      str[i + 1] = '\0';
    }
  }

  return OK;
}

/**
 * game_get_objects returns the array of dialogues in the game
 */
Dialogue **game_get_dialogues(Game *game)
{
  if (game == NULL)
  {
    return NULL;
  }

  return game->dlg;
}
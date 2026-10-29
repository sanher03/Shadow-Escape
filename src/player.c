/**
 * @brief It implements the player module
 *
 * @file player.c
 * @author Fabio Desio
 * @version 2.0
 * @date 06-02-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"

/**
 * @brief The player structure
 *
 * It stores information of the different players managed by the game
 */
struct _Player
{
  Id id;                    /*!< Id of the player*/
  char name[WORD_SIZE + 1]; /*!< Name of the object*/
  Id location;              /*!< Id of the space where the player is located*/
  Inventory *inventory;     /*!< Inventory of the player */
  int health;               /*!< Health points of the player */
};

/**
 * player_create Allocates memory for the data structure and initializes its fields
 */
Player *player_create(Id id)
{
  Player *player = NULL;

  if (id == NO_ID)
  {
    return NULL;
  }

  player = (Player *)malloc(sizeof(Player));
  if (player == NULL)
  {
    return NULL;
  }

  player->id = id;
  player->name[0] = '\0';
  player->location = NO_ID;
  player->inventory = inventory_create();
  player->health = 1;

  return player;
}

STATUS player_add_object(Player *player, Id object)
{
  if (player == NULL || object == NO_ID)
  {
    return ERROR;
  }
  
  return inventory_add_object (player->inventory, object);
}

STATUS player_del_object(Player *player, Id object)
{
  if (player == NULL || object == NO_ID)
  {
    return ERROR;
  }
  
  return inventory_del_object (player->inventory, object);
}

Inventory *player_get_inventory(Player *player)
{
  if (player == NULL)
  {
    return NULL;
  }

  return player->inventory;
}

/**
 * player_destroy Frees the allocated memory of the given player
 */
STATUS player_destroy(Player *player)
{
  if (player == NULL)
  {
    return ERROR;
  }

  inventory_destroy(player->inventory);

  free(player);

  return OK;
}

/**
 * object_get_id Acesses the player structure to get the id
 */
Id player_get_id(Player *player)
{
  if (player == NULL)
  {
    return NO_ID;
  }

  return player->id;
}

/**
 * player_get_id Acesses the player structure to get the id
 */
const char *player_get_name(Player *player)
{
  if (player == NULL)
  {
    return NULL;
  }

  return player->name;
}

/**
 * player_get_id Acesses the player structure to get the location id
 */
Id player_get_location(Player *player)
{
  if (player == NULL)
  {
    return NO_ID;
  }

  return player->location;
}

/**
 * player_get_object Acesses the player structure to get the player health
 */
int player_get_health(Player *player)
{

  if (player == NULL)
  {
    return NO_ID;
  }

  return player->health;
}

STATUS player_set_health(Player *player, int health)
{
  if (player == NULL)
  {
    return ERROR;
  }

  player->health = health;

  return OK;
}

/**
 * player_set_name Copies the string given to the name field of the player
 * be copied
 */
STATUS player_set_name(Player *player, char *name)
{
  if (player == NULL || name == NULL)
  {
    return ERROR;
  }

  strcpy(player->name, name);

  return OK;
}

/**
 * player_set_location Assigns the location field of the player to the id given
 */
STATUS player_set_location(Player *player, Id location)
{
  if (player == NULL)
  {
    return ERROR;
  }

  player->location = location;

  return OK;
}

/**
 * player_print Acesses the player structure to print all its fields
 */
STATUS player_print(Player *player)
{
  if (player == NULL)
  {
    return ERROR;
  }

  /*Print the fields that correspond to the player*/
  fprintf(stdout, "--> Player (Id: %ld; Name: %s; Location: %ld; Health: %d)\n", player->id, player->name, player->location, player->health);

  fprintf(stdout, "--> Inventory: ");

  inventory_print(player->inventory);

  return OK;
}

/** space_get_object_set allocates the memory for the set of objects and initializes it with the ids
 */
Id *player_get_object_set(Player *player)
{
  int n_ids, i;
  Id *objects;

  if (!player)
  {
    return NULL;
  }

  n_ids = set_get_n_ids(inventory_get_object_set(player->inventory));

  if (n_ids == NO_ID)
  {
    return NULL;
  }

  objects = (Id *)malloc(n_ids * sizeof(Id));

  if (objects == NULL)
  {
    return NULL;
  }

  for (i = 0; i < n_ids; i++)
  {
    objects[i] = set_get_pos_id(inventory_get_object_set(player->inventory), i);
  }

  return objects;
}

int player_get_num_objects(Player *player)
{

  if (!player)
  {
    return 0;
  }

  return set_get_n_ids(inventory_get_object_set(player->inventory));
}

STATUS player_print_to_save(Player *player, FILE *file)
{
  if (!player || !file)
  {
    return ERROR; 
  }

  fprintf(file, "#p:%ld|%s|%ld|%d|%d|\n", player->id, player->name, player->location, player->health, inventory_get_max_objs(player->inventory));

  return OK;
}

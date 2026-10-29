/**
 * @brief It implements the enemy module
 *
 * @file enemy.c
 * @author Ignacio Sánchez
 * @version 2.0
 * @date 20-02-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enemy.h"

/**
 * @brief The set structure
 *
 * It stores information of the different sets managed by the game
 */
struct _Enemy
{
  Id id;                /*!< Id of the enemy */
  char name[WORD_SIZE]; /*!< Name of the enemy */
  Id location;          /*!< Location of the enemy */
  int health;           /*!< Health points of the enemy */
};

/**
 * enemy_create allocates memory for the enemy structure and initializes its values
 */
Enemy *enemy_create(Id id)
{
  Enemy *enemy;

  enemy = (Enemy *)malloc(sizeof(Enemy));

  if (enemy == NULL)
  {
    return NULL;
  }

  enemy->id = id;
  enemy->name[0] = '\0';
  enemy->location = NO_ID;
  enemy->health = 5;

  return enemy;
}

/**
 * enemy_destroy frees the memory allocated for the structure
 */
STATUS enemy_destroy(Enemy *enemy)
{
  if (enemy == NULL)
  {
    return ERROR;
  }

  free(enemy);

  return OK;
}

/**
 * enemy_get_id acceses the id of the enemy and returns it
 */
Id enemy_get_id(Enemy *enemy)
{
  if (enemy == NULL)
  {
    return NO_ID;
  }

  return enemy->id;
}

/**
 * enemy_get_name acceses the name of the enemy and returns it
 */
char *enemy_get_name(Enemy *enemy)
{
  if (enemy == NULL)
  {
    return NULL;
  }

  return enemy->name;
}

/**
 * enemy_get_location acceses the location of the enemy and returns it
 */
Id enemy_get_location(Enemy *enemy)
{
  if (enemy == NULL)
  {
    return NO_ID;
  }

  return enemy->location;
}

/**
 * enemy_get_health acceses the health of the enemy and returns it
 */
int enemy_get_health(Enemy *enemy)
{
  if (enemy == NULL)
  {
    return -1;
  }

  return enemy->health;
}

/**
 * enemy_set_name acesses the enemy and sets the name to the given value
 */
STATUS enemy_set_name(Enemy *enemy, char *name)
{
  if (enemy == NULL || name == NULL)
  {
    return ERROR;
  }

  strcpy(enemy->name, name);

  return OK;
}

/**
 * enemy_set_location acesses the enemy and sets the location to the given value
 */
STATUS enemy_set_location(Enemy *enemy, Id location)
{
  if (enemy == NULL)
  {
    return ERROR;
  }

  enemy->location = location;

  return OK;
}

/**
 * enemy_set_health acesses the enemy and sets the health to the given value
 */
STATUS enemy_set_health(Enemy *enemy, int health)
{
  if (enemy == NULL)
  {
    return ERROR;
  }

  enemy->health = health;

  return OK;
}

/**
 * enemy_print prints the info contained in all the fields of the enemy
 */
STATUS enemy_print(Enemy *enemy)
{
  if (enemy == NULL)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Enemy (Id: %ld; Name: %s; Location: %ld; Health: %d)\n", enemy->id, enemy->name, enemy->location, enemy->health);

  return OK;
}

STATUS enemy_print_to_save(Enemy *enemy, FILE *file)
{
  if (!enemy || !file)
  {
    return ERROR; 
  }

  fprintf(file, "#e:%ld|%s|%ld|%d|\n", enemy->id, enemy->name, enemy->location, enemy->health);

  return OK;
}

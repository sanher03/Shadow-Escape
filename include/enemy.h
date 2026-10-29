/**
 * @brief It defines the enemy interface
 *
 * @file enemy.h
 * @author Ignacio Sánchez
 * @version 2.0
 * @date 20-02-2023
 * @copyright GNU Public License
 */
#ifndef ENEMY_H
#define ENEMY_H

#include "types.h"

typedef struct _Enemy Enemy; /*!< Definition of the enemy structure */

/**
 * @brief Creates the data structure of a Enemy
 * @author: Ignacio Sánchez
 *
 * @return pointer to the structure
 */
Enemy *enemy_create(Id id);

/**
 * @brief frees the enemy structure
 * @author: Ignacio Sánchez
 *
 * @param enemy pointer to the enemy
 * @return OK, ERROR in case of error
 */
STATUS enemy_destroy(Enemy *enemy);

/**
 * @brief get the id of the enemy
 * @author: Ignacio Sánchez
 *
 * @param enemy pointer to the enemy
 * @return id of the enemy
 */
Id enemy_get_id(Enemy *enemy);

/**
 * @brief get the name of the enemy
 * @author: Ignacio Sánchez
 *
 * @param enemy pointer to the enemy
 * @return name of the enemy
 */
char *enemy_get_name(Enemy *enemy);

/**
 * @brief get the location of the enemy
 * @author: Ignacio Sánchez
 *
 * @param enemy pointer to the enemy
 * @return location of the enemy
 */
Id enemy_get_location(Enemy *enemy);

/**
 * @brief get the health of the enemy
 * @author: Ignacio Sánchez
 *
 * @param enemy pointer to the enemy
 * @return health of the enemy
 */
int enemy_get_health(Enemy *enemy);

/**
 * @brief Sets the name field of the player to the one given
 * @author: Ignacio Sánchez
 *
 * @param enemy pointer to the enemy to modify
 * @param name string containing name
 * @return OK, ERROR in case of error
 */
STATUS enemy_set_name(Enemy *enemy, char *name);

/**
 * @brief Sets the location field of the player to the one given
 * @author: Ignacio Sánchez
 *
 * @param enemy pointer to the enemy to modify
 * @param location id of the location
 * @return OK, ERROR in case of error
 */
STATUS enemy_set_location(Enemy *enemy, Id location);

/**
 * @brief Sets the health field of the player to the one given
 * @author: Ignacio Sánchez
 *
 * @param enemy pointer to the enemy to modify
 * @param health health to be set
 * @return OK, ERROR in case of error
 */
STATUS enemy_set_health(Enemy *enemy, int health);

/**
 * @brief prints the information of the enemy structure
 * @author: Ignacio Sánchez
 *
 * @param enemy pointer to the enemy
 * @return OK, ERROR in case of error
 */
STATUS enemy_print(Enemy *enemy);

/**
 * @brief writes the state of the enemy to the file
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param enemy pointer to the enemy
 * @param file pointer to the file
 * @return OK, ERROR if an error occurred
 */
STATUS enemy_print_to_save(Enemy *enemy, FILE *file);

#endif

/**
 * @brief It defines the player interface
 *
 * @file player.h
 * @author Fabio Desio
 * @version 2.0
 * @date 06-02-2023
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "inventory.h"

typedef struct _Player Player; /*!< Definition of the player structure */

/**
 * @brief Creates the data structure of a player
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param id of the player
 * @return pointer to the structure
 */
Player *player_create(Id id);

/**
 * @brief Adds an object to the player inventory
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param player pointer to the player to modify
 * @param object id of the object
 * @return OK, ERROR in case of error
 */
STATUS player_add_object(Player *player, Id object);

/**
 * @brief Delete an object from the player inventory
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param player pointer to the player to modify
 * @param object id of the object
 * @return OK, ERROR in case of error
 */
STATUS player_del_object(Player *player, Id object);

/**
 * @brief Destroys the given player
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param player pointer to the player to destroy
 * @return OK, ERROR in case of error
 */
STATUS player_destroy(Player *player);

/*SETTERS*/
/**
 * @brief Sets the name field of the player to the one given
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param player pointer to the player to modify
 * @param name pointer to the string to be copied
 * @return OK, ERROR in case of error
 */
STATUS player_set_name(Player *player, char *name);

/**
 * @brief Sets the location field of the player to the one given
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param player pointer to the player to modify
 * @param location id of the location
 * @return OK, ERROR in case of error
 */
STATUS player_set_location(Player *player, Id location);

/**
 * @brief Sets the health field of the player to the one given
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param player pointer to the player to modify
 * @param health value of the health
 * @return OK, ERROR in case of error
 */
STATUS player_set_health(Player *player, int health);

/*GETTERS*/
/**
 * @brief Obtains the id of a player
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param player pointer to the player
 * @return id of the player
 */
Id player_get_id(Player *player);

/**
 * @brief Obtains the name of a player
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param player pointer to the player
 * @return pointer to the string that contains the name
 */
const char *player_get_name(Player *player);

/**
 * @brief Obtains the id of the space where the player is located
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param player pointer to the player
 * @return id of the space where the player is
 */
Id player_get_location(Player *player);

/**
 * @brief Obtains the health of the player
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param player pointer to the player
 * @return id of the object the player is carrying
 */
int player_get_health(Player *player);

/**
 * @brief Prints the info of an player
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param player pointer to the player
 * @return OK, ERROR in case of error
 */
STATUS player_print(Player *player);

/**
 * @brief Gets the inventory of the player
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param player pointer to the player
 * @return pointer to the inventory
 */
Inventory *player_get_inventory(Player *player);

/**
 * @brief returns an array with the ids in the inventory of the player
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param player pointer to the player
 * @return array of ids
 */
Id *player_get_object_set(Player *player);

/**
 * @brief returns the number of objects in the inventory of the player
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param player pointer to the player
 * @return number of objects
 */
int player_get_num_objects(Player *player);

/**
 * @brief writes the state of the player to the file
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param player pointer to the player
 * @param file pointer to the file
 * @return OK, ERROR if an error occurred
 */
STATUS player_print_to_save(Player *player, FILE *file);

#endif
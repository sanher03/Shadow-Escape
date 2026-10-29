/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"

#include "player.h"
#include "object.h"
#include "enemy.h"
#include "link.h"
#include "dialogue.h"

typedef struct _Game Game; /*!< Definition of the game structure */

/**
 * @brief Creates the data structure of an object
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game data structure to fill
 * @return OK, ERROR in case of error
 */
STATUS game_create(Game **game);

/**
 * @brief Creates game from external file
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game
 * @param filename string containing the file's name
 * @return OK, ERROR in case of error
 */
STATUS game_create_from_file(Game *game, char *filename);

/**
 * @brief Function in charge of basic game functionality
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to game
 * @param cmd introduced by the user
 * @param f pointer to the file
 * @return OK, ERROR in case of error
 */
STATUS game_update(Game **game, Command *cmd, FILE *f);

/**
 * @brief Frees game's memory
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game to destroy
 * @return OK, ERROR in case of error
 */
STATUS game_destroy(Game *game);

/**
 * @brief Checks whether if game is over or not
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game to check
 * @return FALSE, TRUE if the game is over
 */
BOOL game_is_over(Game *game);

/**
 * @brief Prints the game's design
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game to print
 * @return void
 */
void game_print_data(Game *game);

/**
 * @brief Sets the game command to a given pointer
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game to print
 * @param cmd pointer to the command
 * @return OK, ERROR in case of errors
 */
STATUS game_set_cmd(Game *game, Command *cmd);

/*GETTERS*/

/**
 * @brief Gets space upon its id inside of the game
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to game
 * @param id of the space to find
 * @return pointer to the structure
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief Gets the command of the game
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game
 * @return pointer to the command
 */
Command *game_get_cmd(Game *game);

/**
 * @brief Gets the enemy of the game
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game
 * @return pointer to the enemy
 */
Enemy *game_get_enemy(Game *game);

/**
 * @brief Gets the player of the game
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game
 * @return pointer to the player
 */
Player *game_get_player(Game *game);

/**
 * @brief Gets the number of commands of the game
 *
 * @date 15/02/2023
 * @author: Álvaro de Santos
 *
 * @param game pointer to the game
 * @return number of commands
 */
int game_get_ncomands(Game *game);

/**
 * @brief Sets the number of commands of the game
 *
 * @date 15/02/2023
 * @author: Álvaro de Santos
 *
 * @param game pointer to the game
 * @param ncomands number of commands to set
 * @return OK, ERROR if an error occured
 */
STATUS game_set_ncomands(Game *game, int ncomands);

/**
 * @brief Gets the object of the game with an specific name
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game
 * @param name pointer to the name
 * @return id of the object
 */
Id game_get_object_with_name(Game *game, char *name);

/**
 * @brief Gets the object's location inside of the game
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game
 * @param object id of the object
 * @return object's id
 */
Id game_get_object_location(Game *game, Id object);

/*SETTERS*/

/**
 * @brief Adds the space to the game structure
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param space pointer to the space to be added
 * @return OK, ERROR in case of error
 */
STATUS game_add_space(Game *game, Space *space);

/**
 * @brief Adds the object to the game structure
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param object pointer to the object to be added
 * @return OK, ERROR in case of error
 */
STATUS game_add_object(Game *game, Object *object);

/**
 * @brief Adds the player to the game structure
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param player pointer to the player to be added
 * @return OK, ERROR in case of error
 */
STATUS game_add_player(Game *game, Player *player);

/**
 * @brief Adds the enemy to the game structure
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param enemy pointer to the enemy to be added
 * @return OK, ERROR in case of error
 */
STATUS game_add_enemy(Game *game, Enemy *enemy);

/**
 * @brief Adds the link to the corresponding space
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param link pointer to the link to be added
 * @return OK, ERROR in case of error
 */
STATUS game_add_link(Game *game, Link *link);

/**
 * @brief Adds the dialogue to the game structure
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param dialogue pointer to the dialogue to be added
 * @return OK, ERROR in case of error
 */
STATUS game_add_dialogue(Game *game, Dialogue *dialogue);

/**
 * @brief returns an array of ids in the space and the number of them
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param i pointer to store the number of objects
 * @return array of ids
 */
Id *game_get_objects_ids_in_map(Game *game, int *i);

/**
 * @brief returns the id of the object with the given name
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param name pointer to the name
 * @return if of the object
 */
Id game_get_obj_id_with_name(Game *game, const char *name);

/**
 * @brief returns the status of a link
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param space_act id of the actual space
 * @param direction direction of the link
 * @return status of the link
 */
LINKSTATUS game_get_connection_status(Game *game, Id space_act, DIRECTION direction);

/**
 * @brief returns the destination of a link
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param space_act id of the actual space
 * @param direction direction of the link
 * @return destination of the link
 */
Id game_get_connection(Game *game, Id space_act, DIRECTION direction);

/**
 * @brief returns the name of an object
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param obj_id id of the object
 * @return name of the object
 */
char *game_get_obj_name(Game *game, Id obj_id);

/**
 * @brief returns an object
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param obj_id id of the object
 * @return object
 */
Object *game_get_obj(Game *game, Id obj_id);

/**
 * @brief Gets the spaces of the game
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game
 * @return pointer to the spaces
 */
Space **game_get_spaces(Game *game);

/**
 * @brief Gets the objects of the game
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game
 * @return pointer to the objects
 */
Object **game_get_objects(Game *game);

/**
 * @brief Gets the dialogue of a command
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game
 * @param str pointer to the string to modify
 * @return OK, ERROR in case of error
 */
STATUS game_get_dialogue(Game *game, char *str);

/**
 * @brief Gets the dialogue array
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game
 * @return array of dialogues
 */
Dialogue **game_get_dialogues(Game *game);

#endif

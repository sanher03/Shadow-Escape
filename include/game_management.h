/**
 * @brief It defines the game_management interface
 *
 * @file game_management.h
 * @author Ignacio Sánchez
 * @version 2.0
 * @date 06-02-2023
 * @copyright GNU Public License
 */

#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include "game.h"

/**
 * @brief Loads the spaces from the data file to the game
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param filename name of the data file
 * @return OK, ERROR in case of error
 */
STATUS game_management_load_spaces(Game *game, char *filename);

/**
 * @brief Loads the objects from the data file to the game
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param filename name of the data file
 * @return OK, ERROR in case of error
 */
STATUS game_management_load_objects(Game *game, char *filename);

/**
 * @brief Loads the links from the data file to the game
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param filename name of the data file
 * @return OK, ERROR in case of error
 */
STATUS game_management_load_links(Game *game, char *filename);

/**
 * @brief Loads the player from the data file to the game
 *
 * @date 25/03/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param filename name of the data file
 * @return OK, ERROR in case of error
 */
STATUS game_management_load_player(Game *game, char *filename);

/**
 * @brief Loads the enemy from the data file to the game
 *
 * @date 25/03/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param filename name of the data file
 * @return OK, ERROR in case of error
 */
STATUS game_management_load_enemy(Game *game, char *filename);

/**
 * @brief Saves the state of the game to the file
 *
 * @date 25/03/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param filename name of the data file
 * @return OK, ERROR in case of error
 */
STATUS game_management_save(Game *game, const char *filename);

/**
 * @brief Loads the state of the game from the file
 *
 * @date 25/03/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param cmd name command of the game
 * @return OK, ERROR in case of error
 */
STATUS game_management_load(Game **game, Command *cmd);

/**
 * @brief Loads the dialogues from the data file to the game
 *
 * @date 25/03/2023
 * @author: Ignacio Sánchez
 *
 * @param game pointer to the game structure
 * @param filename name of the data file
 * @return OK, ERROR in case of error
 */
STATUS game_management_load_dialogues(Game *game, char *filename);

#endif

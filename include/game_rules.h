/**
 * @brief It defines the interface for game rules
 * @file game_rules.h
 * @author Fabio Desio and Álvaro de Santos
 * @version 1.0
 * @date 6/05/2023
 * @copyright GNU Public License
 */

#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "types.h"
#include "game.h"

#define NUM_RAND_RULES 2 /*!< Number of random rules*/

/**
 * @brief Updates the game according to the rules
 *
 * @date 6/05/2023
 * @author Fabio Desio and Álvaro de Santos
 *
 * @param game pointer to the game data structure
 * @return void
 */
void game_rules_update(Game *game);

/**
 * @brief Applies the rule to move player to a random space
 *
 * @date 6/05/2023
 * @author Fabio Desio and Álvaro de Santos
 *
 * @param game pointer to the game data structure
 * @return void
 */
void game_rules_TOFF_SPACES(Game *game);

/**
 * @brief Applies the rule to take food from a space
 *
 * @date 6/05/2023
 * @author Fabio Desio and Álvaro de Santos
 *
 * @param game pointer to the game data structure
 * @return void
 */
void game_rules_TAKE_FOOD(Game *game);

/**
 * @brief Applies the rule to take a potion from a space
 *
 * @date 6/05/2023
 * @author Fabio Desio and Álvaro de Santos
 *
 * @param game pointer to the game data structure
 * @return void
 */
void game_rules_TAKE_POTION(Game *game);

/**
 * @brief Applies the rule to add a shield to the player
 *
 * @date 6/05/2023
 * @author Fabio Desio and Álvaro de Santos
 *
 * @param game pointer to the game data structure
 * @return void
 */
void game_rules_ADD_SHIELD(Game *game);

/**
 * @brief Applies the rule to increase the health points of the enemy
 *
 * @date 6/05/2023
 * @author Fabio Desio and Álvaro de Santos
 *
 * @param game pointer to the game data structure
 * @return void
 */
void game_rules_HPUP_ENEMY(Game *game);

/**
 * @brief Applies the rule to increase the player's inventory capacity
 *
 * @date 6/05/2023
 * @author Fabio Desio and Álvaro de Santos
 *
 * @param game pointer to the game data structure
 * @return void
 */
void game_rules_UP_INVENTORY(Game *game);

#endif
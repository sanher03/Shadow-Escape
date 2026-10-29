/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

typedef struct _Graphic_engine Graphic_engine; /*!< Definition of the graphic_engine structure */

/**
 * @brief Creates the data structure of the graphic engine
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @return pointer to the structure
 */
Graphic_engine *graphic_engine_create();

/**
 * @brief Destroys the data structure of the graphic engine
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param ge pointer to the graphic engine to be destroyed
 * @return void
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief Paints the game interface in the terminal
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param ge pointer to the graphic engine
 * @param game pointer to the game
 * @param cmd pointer to the command
 * @return void
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game, Command *cmd);

#endif

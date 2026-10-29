/**
 * @brief It implements the dialogue interpreter interface
 *
 * @file dialogue.h
 * @author Ignacio Sánchez
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */
#ifndef DIALOGUE_H
#define DIALOGUE_H

#include "types.h"
#include "command.h"

#define MAX_DLG 100 /*!< Maximum number of dialogues the game can have*/

#define DLG_LENGHT 100 /*!< Maximum length of the string that contains the dialogue*/

typedef struct _Dialogue Dialogue; /*!< Definition of the dialogue structure */

/**
 * @brief creates the data structure
 * @author: Ignacio Sánchez
 *
 * @return pointer to the dialogue structure
 */
Dialogue *dialogue_create();

/**
 * @brief frees the dialogue structure
 * @author: Ignacio Sánchez
 *
 * @param dialogue pointer to the dialogue
 * @return OK, ERROR in case of error
 */
STATUS dialogue_destroy(Dialogue *dialogue);

/**
 * @brief get the cmd of the dialogue
 * @author: Ignacio Sánchez
 *
 * @param dialogue pointer to the dialogue
 * @return cmd of the dialogue
 */
T_Command dialogue_get_cmd(Dialogue *dialogue);

/**
 * @brief get the str of the dialogue
 * @author: Ignacio Sánchez
 *
 * @param dialogue pointer to the dialogue
 * @return pointer to the str of the dialogue
 */
char *dialogue_get_str(Dialogue *dialogue);

/**
 * @brief set the str of the dialogue
 * @author: Ignacio Sánchez
 *
 * @param dialogue pointer to the dialogue
 * @param str pointer to the string to be set
 * @return OK, ERROR if error occured
 */
STATUS dialogue_set_str(Dialogue *dialogue, char *str);

/**
 * @brief get the reps of the dialogue
 * @author: Ignacio Sánchez
 *
 * @param dialogue pointer to the dialogue
 * @return reps of the dialogue
 */
int dialogue_get_reps(Dialogue *dialogue);

/**
 * @brief set the reps of the dialogue
 * @author: Ignacio Sánchez
 *
 * @param dialogue pointer to the dialogue
 * @param reps reps to be set
 * @return OK, ERROR if error occured
 */
STATUS dialogue_set_reps(Dialogue *dialogue, int reps);

/**
 * @brief get the status of the dialogue
 * @author: Ignacio Sánchez
 *
 * @param dialogue pointer to the dialogue
 * @return status of the dialogue
 */
STATUS dialogue_get_status(Dialogue *dialogue);

/**
 * @brief sets the status of a dialogue to a specified value
 * @author: Ignacio Sánchez
 *
 * @param dialogue pointer to the dialogue
 * @param status status to set
 * @return OK, ERROR in case of error
 */
STATUS dialogue_set_status(Dialogue *dialogue, STATUS status);

/**
 * @brief sets the cmd of a dialogue to a specified value
 * @author: Ignacio Sánchez
 *
 * @param dialogue pointer to the dialogue
 * @param cmd cmd to set
 * @return OK, ERROR in case of error
 */
STATUS dialogue_set_cmd(Dialogue *dialogue, T_Command cmd);

/**
 * @brief prints the information of a dialogue
 * @author: Ignacio Sánchez
 *
 * @param dialogue pointer to the dialogue
 * @return OK, ERROR in case of error
 */
STATUS dialogue_print(Dialogue *dialogue);

/**
 * @brief writes the state of the dialogue to the file
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param dialogue pointer to the dialogue
 * @param file pointer to the file
 * @return OK, ERROR if an error occurred
 */
STATUS dialogue_print_to_save(Dialogue *dialogue, FILE *file);

#endif

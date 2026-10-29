/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Ignacio Sánchez
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */
#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

#define N_CMDT 2 /*!< Total type of commands*/

#define N_CMD 15 /*!< Total number of commands*/

#define N_DIR 6 /*!< Total number of directions*/

#define N_STATUS 2 /*!< Total number of status values*/

typedef struct _Command Command; /*!< Definition of the command structure */

/**
 * @brief Possible types of command
 */
typedef enum enum_CmdType
{
  CMDS, /*!< Command is a string*/
  CMDL  /*!< Command is a letter*/
} T_CmdType;

/**
 * @brief Possible types of command
 */
typedef enum enum_DirType
{
  DIRS, /*!< Direction is a string*/
  DIRL  /*!< Direction is a letter*/
} T_DirType;

/**
 * @brief Possible values of command
 */
typedef enum enum_Command
{
  NO_CMD = -1, /*!< No command*/
  UNKNOWN,     /*!< Direction not recognized*/
  EXIT,        /*!< Exit the game*/
  TAKE,        /*!< Take an object*/
  DROP,        /*!< Drop an object*/
  ATTACK,      /*!< Attack the enemy*/
  MOVE,        /*!< Move in a direction*/
  INSPECT,     /*!< Obtain an object's or space's description*/
  TURNON,      /*!< Turn on an object*/
  TURNOFF,     /*!< Turn off an object*/
  OPEN,        /*!< Open a link*/
  SAVE,        /*!< Save the state of the game*/
  LOAD,        /*!< Load the state of the game*/
  SHOOT,       /*!< Shoot the enemy (with the gun)*/
  STAB         /*!< Stab the enemy (with the knife)*/
} T_Command;

/**
 * @brief creates the data structure
 * @author: Ignacio Sánchez
 *
 * @return pointer to the command structure
 */
Command *command_create();

/**
 * @brief frees the command structure
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @return OK, ERROR in case of error
 */
STATUS command_destroy(Command *command);

/**
 * @brief get the cmd of the command
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @return cmd of the command
 */
T_Command command_get_cmd(Command *command);

/**
 * @brief get the name of the command
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @return pointer to the name of the command
 */
char *command_get_name(Command *command);

/**
 * @brief set the name of the command
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @param name pointer to the string to be set
 * @return OK, ERROR if error occured
 */
STATUS command_set_name(Command *command, char *name);

/**
 * @brief get the last_cmd of the command
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @return last_cmd of the command
 */
T_Command command_get_last_cmd(Command *command);

/**
 * @brief set the last_cmd of the command
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @param last_cmd pointer to the string to be set
 * @return OK, ERROR if error occured
 */
STATUS command_set_last_cmd(Command *command, T_Command last_cmd);

/**
 * @brief get the reps of the command
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @return reps of the command
 */
int command_get_reps(Command *command);

/**
 * @brief set the reps of the command
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @param reps pointer to the string to be set
 * @return OK, ERROR if error occured
 */
STATUS command_set_reps(Command *command, int reps);

/**
 * @brief get the link of the command
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @return pointer to the link of the command
 */
char *command_get_link(Command *command);

/**
 * @brief set the link of the command
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @param link pointer to the string to be set
 * @return OK, ERROR if error occured
 */
STATUS command_set_link(Command *command, char *link);

/**
 * @brief get the status of the command
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @return status of the command
 */
STATUS command_get_status(Command *command);

/**
 * @brief sets the status of a command to a specified value
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @param status status to set
 * @return OK, ERROR in case of error
 */
STATUS command_set_status(Command *command, STATUS status);

/**
 * @brief sets the cmd of a command to a specified value
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @param cmd cmd to set
 * @return OK, ERROR in case of error
 */
STATUS command_set_cmd(Command *command, T_Command cmd);

/**
 * @brief gets the command introduced by the user
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 */
void command_get_user_input(Command *command);

/**
 * @brief prints the information of a command
 * @author: Ignacio Sánchez
 *
 * @param command pointer to the command
 * @return OK, ERROR in case of error
 */
STATUS command_print(Command *command);

#endif
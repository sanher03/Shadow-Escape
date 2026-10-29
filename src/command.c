/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "command.h"

#define CMD_LENGHT 30 /*!< Maximum length of the string that contains the command*/

/**
 * @brief The command structure
 *
 * It stores information of the command introduced by the user
 */
struct _Command
{
  T_Command cmd;        /*!< value of the command */
  char name[WORD_SIZE]; /*!< name of the command */
  char link[WORD_SIZE]; /*!< name of the link if specified */
  STATUS status;        /*!< status of the command */
  T_Command last_cmd;   /*!< last command executed*/
  int reps;             /*!< number of times the command failed*/
};

char *cmd_to_str[N_CMD]
                [N_CMDT] = {{"", "No command"},
                            {"", "Unknown"},
                            {"e", "Exit"},
                            {"t", "Take"},
                            {"d", "Drop"},
                            {"a", "Attack"},
                            {"m", "Move"},
                            {"i", "Inspect"},
                            {"ton", "Turnon"},
                            {"toff", "Turnoff"},
                            {"o", "Open"},
                            {"s", "Save"},
                            {"ld", "Load"},
                            {"sh", "Shoot"},
                            {"st", "Stab"}}; /*!<Command that can be introduced by the user*/

char *dir_to_str[N_DIR]
                [N_CMDT] = {{"n", "north"},
                            {"s", "south"},
                            {"e", "east"},
                            {"w", "west"},
                            {"u", "up"},
                            {"d", "down"}}; /*!<Direction that can be introduced by the user*/

char *status_to_str[N_STATUS] = {"ERROR", "OK"}; /*!<Converts the status to a string*/

char *space_to_str[N_STATUS] = {"space", "s"}; /*!<Converts the space to a string*/

/** command_create allocates memory for the data structure
 */
Command *command_create()
{
  Command *command;

  command = (Command *)malloc(sizeof(Command));

  if (command == NULL)
  {
    return NULL;
  }

  command->cmd = NO_CMD;
  command->name[0] = '\0';
  command->link[0] = '\0';
  command->status = ERROR;
  command->last_cmd = NO_CMD;
  command->reps = 0;

  return command;
}

/** command_destroy frees the memory allocated for the data structure
 */
STATUS command_destroy(Command *command)
{
  if (command == NULL)
  {
    return OK;
  }

  free(command);

  return OK;
}

/** command_get_cmd acceses the command and gets the cmd
 */
T_Command command_get_cmd(Command *command)
{

  if (command == NULL)
  {
    return NO_CMD;
  }

  return command->cmd;
}

/** command_get_name acceses the command and gets the name
 */
char *command_get_name(Command *command)
{
  if (command == NULL)
  {
    return NULL;
  }

  return command->name;
}

/** command_get_id acceses the command and gets the id
 */
STATUS command_set_name(Command *command, char *name)
{
  if (command == NULL || name == NULL)
  {
    return ERROR;
  }

  strcpy(command->name, name);

  return OK;
}

/** command_get_link acceses the command and gets the link
 */
char *command_get_link(Command *command)
{
  if (command == NULL)
  {
    return NULL;
  }

  return command->link;
}

/** command_get_id acceses the command and gets the id
 */
STATUS command_set_link(Command *command, char *link)
{
  if (command == NULL || link == NULL)
  {
    return ERROR;
  }

  strcpy(command->link, link);

  return OK;
}

/** command_get_status acceses the command and gets the status
 */
STATUS command_get_status(Command *command)
{
  if (command == NULL)
  {
    return ERROR;
  }

  return command->status;
}

/** command_set_status acesses the command and sets the status to the given value
 */
STATUS command_set_status(Command *command, STATUS status)
{
  if (command == NULL)
  {
    return ERROR;
  }

  command->status = status;

  return OK;
}

/** command_get_last_cmd acceses the command and gets the last_cmd
 */
T_Command command_get_last_cmd(Command *command)
{
  if (command == NULL)
  {
    return NO_CMD;
  }

  return command->last_cmd;
}

/** command_set_last_cmd acesses the command and sets the last_cmd to the given value
 */
STATUS command_set_last_cmd(Command *command, T_Command last_cmd)
{
  if (command == NULL)
  {
    return ERROR;
  }

  command->last_cmd = last_cmd;

  return OK;
}

/** command_get_reps acceses the command and gets the reps
 */
int command_get_reps(Command *command)
{
  if (command == NULL)
  {
    return ERROR;
  }

  return command->reps;
}

/** command_set_reps acesses the command and sets the reps to the given value
 */
STATUS command_set_reps(Command *command, int reps)
{
  if (command == NULL)
  {
    return ERROR;
  }

  command->reps = reps;

  return OK;
}

/** command_set_cmd acesses the command and sets the cmd to the given value
 */
STATUS command_set_cmd(Command *command, T_Command cmd)
{
  if (command == NULL)
  {
    return ERROR;
  }

  command->cmd = cmd;

  return OK;
}

/** command_print prints the command introduced and its fields
 */
STATUS command_print(Command *command)
{
  if (command == NULL)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Command: %s; Name: %s; Status: %d\n", cmd_to_str[command->cmd - NO_CMD][CMDL], command->name, command->status);

  return OK;
}

/** command_get_user_input scans the opotion introduced by the user and fills
 * the command with the correspondieng information
 */
void command_get_user_input(Command *command)
{
  T_Command cmd = NO_CMD;
  char input[CMD_LENGHT] = "", str[WORD_SIZE] = "", str_aux[WORD_SIZE] = "";
  int i = UNKNOWN - NO_CMD + 1;

  command->last_cmd = command->cmd;

  if (fscanf(stdin, "%s", input) == 0)
  {
    command->cmd = cmd;
    return;
  }

  cmd = UNKNOWN;
  while (cmd == UNKNOWN && i < N_CMD)
  {
    if (!strcasecmp(input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL]))
    {
      cmd = i + NO_CMD;
    }
    else
    {
      i++;
    }
  }

  command->cmd = cmd;

  if (cmd == TAKE || cmd == DROP || cmd == MOVE || cmd == INSPECT || cmd == TURNON || cmd == TURNOFF || cmd == SAVE || cmd == LOAD)
  {
    if (fscanf(stdin, " %s", str) == 0)
    {
      return;
    }
    if (command->cmd == command->last_cmd && command->reps == 0 && command->status == ERROR && strcasecmp(command->name, str) == 0)
    {
      command->reps++;
    }
    else
    {
      command->reps = 0;
    }

    command_set_name(command, str);
  }
  else if (cmd == OPEN)
  {
    if (fscanf(stdin, " %s with %s", str_aux, str) == 0)
    {
      return;
    }
    if (command->cmd == command->last_cmd && command->reps == 0 && command->status == ERROR && strcasecmp(command->name, str) == 0 && strcasecmp(command->link, str_aux) == 0)
    {
      command->reps++;
    }
    else
    {
      command->reps = 0;
    }
    command_set_link(command, str_aux);
    command_set_name(command, str);
  }

  return;
}
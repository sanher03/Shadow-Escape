/**
 * @brief It implements the dialogue interpreter
 *
 * @file dialogue.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dialogue.h"

/**
 * @brief The dialogue structure
 *
 * It stores information of the dialogue introduced by the user
 */
struct _Dialogue
{
  T_Command cmd;        /*!< value of the command */
  STATUS status;        /*!< status of the command */
  int reps;       /*!< number of times the command failed*/
  char str[DLG_LENGHT]; /*!<string of the message to be displayed*/
};

/** dialogue_create allocates memory for the data structure
 */
Dialogue *dialogue_create()
{
  Dialogue *dialogue;

  dialogue = (Dialogue *)malloc(sizeof(Dialogue));

  if (dialogue == NULL)
  {
    return NULL;
  }

  dialogue->cmd = NO_CMD;
  dialogue->str[0] = '\0';
  dialogue->reps = 0;
  dialogue->status = ERROR;

  return dialogue;
}

/** dialogue_destroy frees the memory allocated for the data structure
 */
STATUS dialogue_destroy(Dialogue *dialogue)
{
  if (dialogue == NULL)
  {
    return OK;
  }

  free(dialogue);

  return OK;
}

/** dialogue_get_cmd acceses the dialogue and gets the cmd
 */
T_Command dialogue_get_cmd(Dialogue *dialogue)
{
  if (dialogue == NULL)
  {
    return NO_CMD;
  }

  return dialogue->cmd;
}

/** dialogue_get_str acceses the dialogue and gets the str
 */
char *dialogue_get_str(Dialogue *dialogue)
{
  if (dialogue == NULL)
  {
    return NULL;
  }

  return dialogue->str;
}

/** dialogue_get_id acceses the dialogue and gets the id
 */
STATUS dialogue_set_str(Dialogue *dialogue, char *str)
{
  if (dialogue == NULL || str == NULL)
  {
    return ERROR;
  }

  strcpy(dialogue->str, str);

  return OK;
}

/** dialogue_get_status acceses the dialogue and gets the status
 */
STATUS dialogue_get_status(Dialogue *dialogue)
{
  if (dialogue == NULL)
  {
    return ERROR;
  }

  return dialogue->status;
}

/** dialogue_set_status acesses the dialogue and sets the status to the given value
 */
STATUS dialogue_set_status(Dialogue *dialogue, STATUS status)
{
  if (dialogue == NULL)
  {
    return ERROR;
  }

  dialogue->status = status;

  return OK;
}

/** dialogue_get_reps acceses the dialogue and gets the reps
 */
int dialogue_get_reps(Dialogue *dialogue)
{
  if (dialogue == NULL)
  {
    return ERROR;
  }

  return dialogue->reps;
}

/** dialogue_set_reps acesses the dialogue and sets the reps to the given value
 */
STATUS dialogue_set_reps(Dialogue *dialogue, int reps)
{
  if (dialogue == NULL)
  {
    return ERROR;
  }

  dialogue->reps = reps;

  return OK;
}

/** dialogue_set_cmd acesses the dialogue and sets the cmd to the given value
 */
STATUS dialogue_set_cmd(Dialogue *dialogue, T_Command cmd)
{
  if (dialogue == NULL)
  {
    return ERROR;
  }

  dialogue->cmd = cmd;

  return OK;
}

/** dialogue_print prints the dialogue introduced and its fields
 */
STATUS dialogue_print(Dialogue *dialogue)
{
  extern char *cmd_to_str[N_CMD][N_CMDT], *status_to_str[N_CMDT];

  if (dialogue == NULL)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Dialogue: %s; Status: %s; String: %s; Number of times: %d\n", cmd_to_str[dialogue->cmd - NO_CMD][CMDL], status_to_str[dialogue->status], dialogue->str, dialogue->reps);

  return OK;
}

STATUS dialogue_print_to_save(Dialogue *dialogue, FILE *file)
{
  if (!dialogue || !file)
  {
    return ERROR; 
  }

  fprintf(file, "#d:%d|%d|%d|%s|\n", dialogue->cmd, dialogue->status, dialogue->reps, dialogue->str);

  return OK;
}





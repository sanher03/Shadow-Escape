/**
 * @brief It implements the set module
 *
 * @file set.c
 * @author Fabio Desio
 * @version 2.0
 * @date 20-02-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"

#define MAX_N_IDS 100 /*!< Maximum number of ids the array can store*/

/**
 * @brief The set structure
 *
 * It stores information of the different sets managed by the game
 */
struct _Set
{
  Id id[MAX_N_IDS]; /*!< Array of ids */
  int n_ids;        /*!< Number of ids */
};

/** set_get_id_pos runs through the set until it finds the specified id
 */
int set_get_id_pos(Set *set, Id id)
{
  int i;

  if (set == NULL || id == NO_ID)
  {
    return NO_ID;
  }

  for (i = 0; i < set->n_ids; i++)
  {
    if (set->id[i] == id)
    {
      return i;
    }
  }

  return NO_ID;
}

/** set_get_n_ids acesses the set and its number of ids
 */
int set_get_n_ids(Set *set)
{

  if (set == NULL)
  {
    return NO_ID;
  }

  return set->n_ids;
}

/** set_get_pos_id returns the id stored at the specified position
 */
Id set_get_pos_id(Set *set, int pos)
{
  if (set == NULL || pos == NO_ID || set->n_ids <= pos)
  {
    return NO_ID;
  }

  return set->id[pos];
}

/** set_get_pos_id returns the id stored at the specified position
 */
Set *set_create()
{
  Set *set;
  int i;

  set = (Set *)malloc(sizeof(Set));
  if (set == NULL)
  {
    return NULL;
  }

  for (i = 0; i < MAX_N_IDS; i++)
  {
    set->id[i] = NO_ID;
  }

  set->n_ids = 0;

  return set;
}

/** set_get_pos_id returns the id stored at the specified position
 */
STATUS set_destroy(Set *set)
{
  if (set == NULL)
  {
    return ERROR;
  }

  free(set);

  return OK;
}

/** set_add checks if the set has the id and adds it otherwise, increasing the number of ids
 */
STATUS set_add(Set *set, Id id)
{
  int pos;

  if (set == NULL || id == NO_ID || set->n_ids == MAX_N_IDS)
  {
    return ERROR;
  }

  pos = set_get_id_pos(set, id);

  if (pos != NO_ID)
  {
    return OK;
  }

  set->id[set->n_ids] = id;
  set->n_ids++;

  return OK;
}

/** set_del checks if the set has the id and deletes it otherwise, decreasing the number of ids
 */
STATUS set_del(Set *set, Id id)
{
  int pos;

  if (set == NULL || id == NO_ID)
  {
    return ERROR;
  }

  pos = set_get_id_pos(set, id);

  if (pos == NO_ID)
  {
    return OK;
  }

  if (pos == set->n_ids - 1)
  {
    set->n_ids--;
    return OK;
  }

  set->n_ids--;
  set->id[pos] = set->id[set->n_ids];

  return OK;
}

/** set_print prints the number of ids and the ids in the array
 */
STATUS set_print(Set *set)
{
  int i;

  if (set == NULL)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Set (N_ids: %d)\n", set->n_ids);

  for (i = 0; i < set->n_ids; i++)
  {
    fprintf(stdout, "--> Id %d: %ld\n", i + 1, set->id[i]);
  }

  return OK;
}

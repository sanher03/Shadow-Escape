/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Ignacio Sánchez
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "space.h"
#include "types.h"

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space
{
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Link *links[MAX_LINKS];   /*!< Array that stores the links of a space*/
  Set *objects;             /*!< Set of objects the space has */
  char **gdesc;             /*!< Graphic description of the space */
  char description[DESCR_SIZE + 1]; /*!< Description of the space*/
  BOOL light;               /*!< Whether the space is light*/
  char det_descr[DESCR_SIZE + 1]; /*!< Detailed description of the space*/
};

/** space_gdesc_create allocates memory for the graphic description of a space
 */
char **space_gdesc_create()
{
  char **gdesc;
  int i;

  gdesc = (char **)malloc(NUM_GDESC * sizeof(char *));
  for (i = 0; i < NUM_GDESC; i++)
  {
    gdesc[i] = (char *)calloc(GDESC_MAX, sizeof(char));
  }

  return gdesc;
}

/** space_gdesc_destroy frees the memory for the graphic description of a space
 */
STATUS space_gdesc_destroy(char **gdesc)
{
  int i;

  if (gdesc == NULL)
  {
    return ERROR;
  }

  for (i = 0; i < NUM_GDESC; i++)
  {
    free(gdesc[i]);
  }
  free(gdesc);

  return OK;
}

/** space_create allocates memory for a new space
 *  and initializes its members
 */
Space *space_create(Id id)
{
  Space *newSpace = NULL;
  int i;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *)calloc(1, sizeof(Space));
  if (newSpace == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->description[0] = '\0';
  for (i = 0; i < MAX_LINKS; i++)
  {
    newSpace->links[i] = NULL;
  }
  newSpace->objects = set_create();
  newSpace->gdesc = space_gdesc_create();
  newSpace->light = FALSE;
  newSpace->det_descr[0] = '\0';

  return newSpace;
}

/** space_destroy frees the previous memory allocation
 *  for a space
 */
STATUS space_destroy(Space *space)
{
  int i = 0;

  if (!space)
  {
    return ERROR;
  }

  set_destroy(space->objects);
  space_gdesc_destroy(space->gdesc);
  for (i = 0; i < MAX_LINKS; i++)
  {
    link_destroy(space->links[i]);
  }
  free(space);

  return OK;
}

/** It gets the id of a space
 */
Id space_get_id(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->id;
}

/** It sets the name of a space
 */
STATUS space_set_name(Space *space, char *name)
{
  if (!space || !name)
  {
    return ERROR;
  }

  if (!strcpy(space->name, name))
  {
    return ERROR;
  }
  return OK;
}

/** It sets the description of a space
 */
STATUS space_set_description(Space *space, char *description)
{
  if (!space || !description)
  {
    return ERROR;
  }

  if (!strcpy(space->description, description))
  {
    return ERROR;
  }
  return OK;
}

/** It gets the name of a space
 */
const char *space_get_name(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->name;
}

/** It gets the name of a space
 */
const char *space_get_description(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->description;
}

/** space_get_gdesc acceses the space structure and returns the double pointer 
 *  pointing the graphic description
 */
char **space_get_gdesc(Space *space)
{
  if (!space)
    return NULL;

  return space->gdesc;
}

/** space_set_gdesc acceses the space structure and copies the graphic 
 *  description of the argument into each of the arrays
 */
STATUS space_set_gdesc(Space *space, char **desc)
{
  int i;

  if (!space || !desc)
    return ERROR;

  for (i = 0; i < NUM_GDESC; i++)
  {
    strcpy(space->gdesc[i], desc[i]);
  }

  return OK;
}

/** space_add_link Loops through the link array until 
 * it finds one empty and adds the link
 */
STATUS space_add_link(Space *space, Link *link)
{
  int i = 0;

  if (space == NULL || link == NULL)
  {
    return ERROR;
  }

  while (i < MAX_LINKS && space->links[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_LINKS)
  {
    return ERROR;
  }

  space->links[i] = link;

  return OK;
}

/** space_get_link_with_direction acceses the space structure and returns 
 *  the link that corresponds to the direction passed as an argument
 */
Link *space_get_link_with_direction(Space *space, DIRECTION dir)
{
  int i;

  if (!space)
  {
    return NULL;
  }

  for (i = 0; i < MAX_LINKS; i++)
  {
    if (link_get_direction(space->links[i]) ==  dir)
    {
      return space->links[i];
    }
  }
  return NULL;
}

/** space_print It prints the space information
 */
STATUS space_print(Space *space)
{
  Id idaux = NO_ID;
  int n_objs = 0, i;

  /* Error Control */
  if (!space)
  {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  /* 2. For each direction, print its link */
  for (i = 0; i < MAX_LINKS; i++)
  {
    idaux = NO_ID;
    if (link_get_direction(space->links[i]) == N)
    {
      idaux = link_get_destination(space->links[i]);
      break;
    }
  }
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No north link.\n");
  }
  for (i = 0; i < MAX_LINKS; i++)
  {
    idaux = NO_ID;
    if (link_get_direction(space->links[i]) == S)
    {
      idaux = link_get_destination(space->links[i]);
      break;
    }
  }
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No south link.\n");
  }
  for (i = 0; i < MAX_LINKS; i++)
  {
    idaux = NO_ID;
    if (link_get_direction(space->links[i]) == E)
    {
      idaux = link_get_destination(space->links[i]);
      break;
    }
  }
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No east link.\n");
  }
  for (i = 0; i < MAX_LINKS; i++)
  {
    idaux = NO_ID;
    if (link_get_direction(space->links[i]) == W)
    {
      idaux = link_get_destination(space->links[i]);
      break;
    }
  }
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No west link.\n");
  }
  n_objs = set_get_n_ids(space->objects);
  if (NO_ID != n_objs)
  {
    fprintf(stdout, "---> No objects in the space.\n");
  }
  else
  {
    set_print(space->objects);
  }
  fprintf(stdout, "---> Graphic description:\n");
  for (i = 0; i < NUM_GDESC; i++)
  {
    fprintf(stdout, "---> %s\n", space->gdesc[i]);
  }
  if (space->light)
  {
    fprintf(stdout, "---> Light: TRUE\n");
  }
  else
  {
    fprintf(stdout, "---> Light: FALSE\n");
  }

  return OK;
}

/** space_add_object calls the set_add function to add an object
 */
STATUS space_add_object(Space *space, Id object)
{
  if (!space)
  {
    return ERROR;
  }

  return set_add(space->objects, object);
}

/** space_del_object calls the set_del function to delete an object
 */
STATUS space_del_object(Space *space, Id object)
{
  if (!space)
  {
    return ERROR;
  }

  return set_del(space->objects, object);
}

/** space_has_object_id calls the set_get_id_pos function to see if the id is in the space
 */
BOOL space_has_object_id(Space *space, Id object)
{
  if (!space)
  {
    return FALSE;
  }

  if (set_get_id_pos(space->objects, object) == NO_ID)
  {
    return FALSE;
  }

  return TRUE;
}

/** space_has_object_name calls the set_get_id_pos function to see if the id is in the space
 */
BOOL space_has_object_name(Space *space, Id object)
{
  if (!space)
  {
    return FALSE;
  }

  if (set_get_id_pos(space->objects, object) == NO_ID)
  {
    return FALSE;
  }

  return TRUE;
}

/** space_get_object_set allocates the memory for the set of objects and initializes it with the ids
 */
Id *space_get_object_set(Space *space)
{
  int n_ids, i;
  Id *objects;

  if (!space)
  {
    return NULL;
  }

  n_ids = set_get_n_ids(space->objects);

  if (n_ids == NO_ID)
  {
    return NULL;
  }

  objects = (Id *)malloc(n_ids * sizeof(Id));

  if (objects == NULL)
  {
    return NULL;
  }

  for (i = 0; i < n_ids; i++)
  {
    objects[i] = set_get_pos_id(space->objects, i);
  }

  return objects;
}

/** space_get_num_obj calls the set_get_n_ids function to get the number of objects
 */
int space_get_num_obj(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }

  return set_get_n_ids(space->objects);
}

/** space_get_light acceses the space structure to get the light
 */
BOOL space_get_light(Space *space)
{
  if (!space)
  {
    return FALSE;
  } 

  return space->light;
}

/** space_set_light acceses the space structure to set the light
 */
STATUS space_set_light(Space *space, BOOL light)
{
  if (!space)
  {
    return ERROR;
  } 

  space->light = light;

  return OK;
}

/** It sets the detailed description of a space
 */
STATUS space_set_det_descr(Space *space, char *description)
{
  if (!space || !description)
  {
    return ERROR;
  }

  strcpy(space->det_descr, description);

  return OK;
}

/** It gets the detailed description of a space
 */
const char *space_get_det_descr(Space *space)
{
  if (!space)
  {
    return NULL;
  }

  return space->det_descr;
}

/**
 *  Loops through the links of a space until it finds the one with the given name
 */
Link *space_get_link_with_name(Space *space, const char *name)
{
  int i;

  if (!space || !name)
  {
    return NULL;
  } 

  for (i = 0; i < MAX_LINKS && space->links[i] != NULL; i++)
  {
    if (strcasecmp(name, link_get_name(space->links[i])) == 0)
    {
      break;
    }
  }

  return space->links[i];
}

STATUS space_print_to_save(Space *space, FILE *file)
{
  int i;

  if (!space || !file)
  {
    return ERROR; 
  }

  fprintf(file, "#s:%ld|%s|%s|%s|%d|", space->id, space->name, space->description, space->det_descr, space->light);
  for (i = 0; i < NUM_GDESC; i++)
  {
    fprintf(file, "%s@", space->gdesc[i]);
    if (i == NUM_GDESC - 1)
    {
      fprintf(file, "\n");
    }
  }
  for (i = 0; i < MAX_LINKS; i++)
  {
    if (space->links[i] != NULL)
    {
      link_print_to_save(space->links[i], file);
    }
  }

  return OK;
}

/**
 * @brief It implements the object module
 *
 * @file object.c
 * @author Fabio Desio
 * @version 3.0
 * @date 06-02-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"
#include "types.h"

#define N_BOOL 2 /*!< Total number of BOOL status */

/**
 * @brief The object structure
 *
 * It stores information of the different objects managed by the game
 */
struct _Object
{
  Id id;                            /*!< Id of the object*/
  char name[WORD_SIZE + 1];         /*!< Name of the object*/
  char description[DESCR_SIZE + 1]; /*!< Description of the object*/
  BOOL hidden;                      /*!< Shows whether the object is hidden or not */
  BOOL movable;                     /*!< Shows whether the object can move or not */
  Id dependency;                    /*!< Id of the object with which it has a dependency relationship */
  Id open;                          /*!< Id of the link the object is able to open */
  BOOL illuminate;                  /*!< Shows whether the object can illuminate the space or not */
  BOOL turnedon;                    /*!< Shows whether the object that can be illuminated is turned on or not */
  T_ObjType type;                   /*!< Type of the object */
};

char *bool_to_str[N_BOOL] = {"FALSE", "TRUE"}; /*!< Converts a boolean into a string*/

/**
 * object_create Allocates memory for the data structure and initializes its fields
 */
Object *object_create(Id id)
{
  Object *object = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  object = (Object *)malloc(1 * sizeof(Object));
  if (object == NULL)
  {
    return NULL;
  }

  object->id = id;
  *(object->name) = '\0';
  object->description[0] = '\0';
  object->hidden = TRUE;
  object->movable = TRUE;
  object->dependency = NO_ID;
  object->open = 37;
  object->illuminate = FALSE;
  object->turnedon = FALSE;
  object->type = NO_TYPE;

  return object;
}

/**
 * object_destroy Frees the allocated memory of the given object
 */
STATUS object_destroy(Object *object)
{
  /*Error control*/
  if (object == NULL)
  {
    return ERROR;
  }

  free(object);
  return OK;
}

/**
 * object_set_name Copies the string given to the name field of the object
 */
STATUS object_set_name(Object *object, char *name)
{
  /*Error control*/
  if (object == NULL || name == NULL)
  {
    return ERROR;
  }

  strcpy(object->name, name);

  return OK;
}

/**
 * object_set_description Copies the string given to the description field of the object
 */
STATUS object_set_description(Object *object, char *description)
{
  /*Error control*/
  if (object == NULL || description == NULL)
  {
    return ERROR;
  }

  strcpy(object->description, description);

  return OK;
}

/**
 * object_set_hidden Copies the hidden BOOL variable to the hidden field of the object
 */
STATUS object_set_hidden(Object *object, BOOL hidden)
{
  /* Error control */
  if (object == NULL)
  {
    return ERROR;
  }

  object->hidden = hidden;
  return OK;
}

/**
 * object_set_movable Copies the movable BOOL variable to the movable field of the object
 */
STATUS object_set_movable(Object *object, BOOL movable)
{
  /* Error control */
  if (object == NULL)
  {
    return ERROR;
  }

  object->movable = movable;
  return OK;
}

/**
 * object_set_dependency Updates the object dependency field
 */
STATUS object_set_dependency(Object *object, Id dependency)
{
  /* Error control */
  if (object == NULL)
  {
    return ERROR;
  }

  object->dependency = dependency;
  return OK;
}

/**
 * object_set_open Updates the object open field
 */
STATUS object_set_open(Object *object, Id open)
{
  /* Error control */
  if (object == NULL)
  {
    return ERROR;
  }

  object->open = open;
  return OK;
}

/**
 * object_set_illuminate Updates the object illuminate field
 */
STATUS object_set_illuminate(Object *object, BOOL illuminate)
{
  /* Error control */
  if (object == NULL)
  {
    return ERROR;
  }

  object->illuminate = illuminate;
  return OK;
}

/**
 * object_set_turnedon Updates the object turnedon field
 */
STATUS object_set_turnedon(Object *object, BOOL turnedon)
{
  /* Error control */
  if (object == NULL)
  {
    return ERROR;
  }

  object->turnedon = turnedon;
  return OK;
}

/**
 * object_set_type Updates the object objtype field
 */
STATUS object_set_type(Object *object, T_ObjType type)
{
  /* Error control */
  if (object == NULL)
  {
    return ERROR;
  }

  object->type = type;
  return OK;
}

/**
 * object_get_id Acesses the object structure to get the id
 */
Id object_get_id(Object *object)
{
  /*Error control*/
  if (object == NULL)
  {
    return NO_ID;
  }

  return object->id;
}

/**
 * object_get_name Acesses the object structure to get the name
 */
char *object_get_name(Object *object)
{
  /*Error control*/
  if (object == NULL)
  {
    return NULL;
  }

  return object->name;
}

/**
 * object_get_description Acesses the object structure to get the description
 */
char *object_get_description(Object *object)
{
  /*Error control*/
  if (object == NULL)
  {
    return NULL;
  }

  return object->description;
}

/**
 * object_get_hidden Gets the value of the hidden field on the object structure
 */
BOOL object_get_hidden(Object *object)
{
  /* Error control */
  if (object == NULL)
  {
    return FALSE;
  }

  return object->hidden;
}

/**
 *  object_get_movable Gets the value of the movable field on the object structure
 */
BOOL object_get_movable(Object *object)
{
  /* Error control */
  if (object == NULL)
  {
    return FALSE;
  }

  return object->movable;
}

/**
 * object_get_dependency Gets the value of the dependency field on the object structure
 */
Id object_get_dependency(Object *object)
{
  /* Error control */
  if (object == NULL)
  {
    return NO_ID;
  }

  return object->dependency;
}

/**
 * object_get_open Gets the value of the open field on the object structures
 */
Id object_get_open(Object *object)
{
  /* Error control */
  if (object == NULL)
  {
    return NO_ID;
  }

  return object->open;
}

/**
 * object_get_illuminate Gets the value of the illuminate field on the object structure
 */
BOOL object_get_illuminate(Object *object)
{
  /* Error control */
  if (object == NULL)
  {
    return FALSE;
  }

  return object->illuminate;
}

/**
 * object_get_turnedon Gets the value of the turnedon field on the object structure
 */
BOOL object_get_turnedon(Object *object)
{
  /* Error control */
  if (object == NULL)
  {
    return FALSE;
  }

  return object->turnedon;
}

/**
 * object_get_type Gets the value of the type field on the object structure
 */
T_ObjType object_get_type(Object *object)
{
  /* Error control */
  if (object == NULL)
  {
    return NO_TYPE;
  }

  return object->type;
}


/**
 * object_print Acesses the object structure to print all its fields
 */
STATUS object_print(Object *object)
{
  extern char *bool_to_str[N_BOOL];

  /*Error control*/
  if (object == NULL)
  {
    return ERROR;
  }

  /* Print the id and the name of the object */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s; Description: %s; Hidden: %s; Movable: %s; Dependency: %ld; Open: %ld; Illuminate: %s; Turned On: %s)\n",
          object->id, object->name, object->description, bool_to_str[object->hidden], bool_to_str[object->movable], object->dependency, object->open, bool_to_str[object->illuminate], bool_to_str[object->turnedon]);

  return OK;
}

STATUS object_print_to_save(Id location, Object *object, FILE *file)
{
  if (!object || !file)
  {
    return ERROR;
  }

  fprintf(file, "#o:%ld|%s|%ld|%s|%d|%d|%ld|%ld|%d|%d|%d|\n", object->id, object->name, location, object->description, object->hidden, object->movable, object->dependency, object->open, object->illuminate, object->turnedon, object->type);

  return OK;
}

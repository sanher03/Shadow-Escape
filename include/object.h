/**
 * @brief It defines the object interface
 *
 * @file object.h
 * @author Fabio Desio
 * @version 2.0
 * @date 06-02-2023
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

#define MAX_OBJECTS 100 /*!< Maximum objects that can be stored*/

typedef struct _Object Object; /*!< Definition of the object structure */

/**
 * @brief Possible types of objects
 */
typedef enum enum_ObjType
{
    NO_TYPE = -1, /*!< Type not specified */
    FOOD,         /*!< Food type */
    POTION,       /*!< Potion type */
    POISON,       /*!< Poison type */
    SHIELD,       /*!< Shield type */
    GUN,          /*!< Gun type */
    KNIFE,        /*!< Knife type <*/
    STORAGE       /*!< Storage type <*/
} T_ObjType;

/**
 * @brief Creates the data structure of an object
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param id of the object
 * @return pointer to the structure
 */
Object *object_create(Id id);

/**
 * @brief Destroys the given object
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object to destroy
 * @return OK, ERROR in case of error
 */
STATUS object_destroy(Object *object);

/*SETTERS*/
/**
 * @brief Sets the name field of the object to the one given
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object to modify
 * @param name pointer to the string to be copied
 * @return OK, ERROR in case of error
 */
STATUS object_set_name(Object *object, char *name);

/**
 * @brief Sets the description field of the object to the one given
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object to modify
 * @param description pointer to the string to be copied
 * @return OK, ERROR in case of error
 */
STATUS object_set_description(Object *object, char *description);

/**
 * @brief Sets the hidden field of the object to the one given
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object to modify
 * @param hidden BOOL variable
 * @return OK, ERROR in case of error
 */
STATUS object_set_hidden(Object *object, BOOL hidden);

/**
 * @brief Sets the movable field of the object to the one given
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object to modify
 * @param movable BOOL variable
 * @return OK, ERROR in case of error
 */
STATUS object_set_movable(Object *object, BOOL movable);

/**
 * @brief Sets the dependency field of the object to the one given
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object to modify
 * @param dependency Id of the object with which it holds dependency
 * @return OK, ERROR in case of error
 */
STATUS object_set_dependency(Object *object, Id dependency);

/**
 * @brief Sets the open field of the object to the one given
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object to modify
 * @param open Id of the link the object is able to open
 * @return OK, ERROR in case of error
 */
STATUS object_set_open(Object *object, Id open);

/**
 * @brief Sets the illuminate field of the object to the one given
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object to modify
 * @param illuminate BOOL variable
 * @return OK, ERROR in case of error
 */
STATUS object_set_illuminate(Object *object, BOOL illuminate);

/**
 * @brief Sets the turnedon field of the object to the one given
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object to modify
 * @param turnedon BOOL variable
 * @return OK, ERROR in case of error
 */
STATUS object_set_turnedon(Object *object, BOOL turnedon);

/**
 * @brief Sets the object type field of the object to the one given
 *
 * @date 5/05/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object to modify
 * @param type T_ObjType variable
 * @return OK, ERROR in case of error
 */
STATUS object_set_type(Object *object, T_ObjType type);

/*GETTERS*/
/**
 * @brief Obtains the id of an object
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object
 * @return id of the object
 */
Id object_get_id(Object *object);

/**
 * @brief Obtains the name of an object
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object
 * @return id of the object
 */
char *object_get_name(Object *object);

/**
 * @brief Obtains the description of an object
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object
 * @return Description of the object
 */
char *object_get_description(Object *object);

/**
 * @brief Obtains the hidden value of an object
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object
 * @return BOOL value of the hidden field
 */
BOOL object_get_hidden(Object *object);

/**
 * @brief Obtains the movable value of an object
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object
 * @return BOOL value of the movable field
 */
BOOL object_get_movable(Object *object);

/**
 * @brief Obtains the dependency value of an object
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object
 * @return Dependency id of the object
 */
Id object_get_dependency(Object *object);

/**
 * @brief Obtains the open value of an object
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object
 * @return Open id of the object
 */
Id object_get_open(Object *object);

/**
 * @brief Obtains the illuminate of an object
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object
 * @return BOOL value of the illuminate field
 */
BOOL object_get_illuminate(Object *object);

/**
 * @brief Obtains the turnedon value of an object
 *
 * @date 17/04/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object
 * @return BOOL value of the turnedon field
 */
BOOL object_get_turnedon(Object *object);

/**
 * @brief Obtains the object type of an object
 *
 * @date 5/05/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object
 * @return T_ObjType value of the object type field
 */
T_ObjType object_get_type(Object *object);

/**
 * @brief Prints the info of an object
 *
 * @date 15/02/2023
 * @author: Fabio Desio
 *
 * @param object pointer to the object
 * @return OK, ERROR in case of error
 */
STATUS object_print(Object *object);

/**
 * @brief writes the state of the object to the file
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param location location of the object
 * @param object pointer to the object
 * @param file pointer to the file
 * @return OK, ERROR if an error occurred
 */
STATUS object_print_to_save(Id location, Object *object, FILE *file);

#endif
/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Ignacio Sánchez
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"
#include "link.h"

typedef struct _Space Space; /*!< Definition of the space structure */

#define MAX_SPACES 100 /*!< Maximum number of spaces the game can have*/

#define MAX_LINKS 6 /*!< Maximum number of links a space can have*/

#define FIRST_SPACE 1 /*!< Number of the first space*/

#define NUM_GDESC 23 /*!< Maximum number of spaces the game can have*/

#define GDESC_MAX 75 /*!< Maximum number of characters of the array of the graphic description*/

/**
 * @brief Creates de graphic description of a game
 * @author Ignacio Sánchez
 *
 * @return double pointer of a char variable
 */
char **space_gdesc_create();

/**
 * @brief Destroys the graphic description
 * @author Ignacio Sánchez
 *
 * @param gdesc pointer to the de graphic description to destroy
 * @return a new space, initialized
 */
STATUS space_gdesc_destroy(char **gdesc);

/**
 * @brief It creates a new space, allocating memory and initializing its memebers
 * @author Ignacio Sánchez
 *
 * @param id the identification number for the new space
 * @return a new space, initialized
 */
Space *space_create(Id id);

/**
 * @brief It destroys a space, freeing the allocated memory
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_destroy(Space *space);

/**
 * @brief It gets the id of a space
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space
 * @return the id of space
 */
Id space_get_id(Space *space);

/**
 * @brief It sets the name of a space
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_set_name(Space *space, char *name);

/**
 * @brief It sets the description of a space
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space
 * @param description a string with the description to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_set_description(Space *space, char *description);

/**
 * @brief It gets the name of a space
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space
 * @return  a string with the name of the space
 */
const char *space_get_name(Space *space);

/**
 * @brief It gets the description of a space
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space
 * @return  a string with the description of the space
 */
const char *space_get_description(Space *space);

/**
 * @brief Gets the id of the space in the direction specified
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space
 * @param dir direction of the movement
 * @return id of the destionation space
 */
Link *space_get_link_with_direction(Space *space, DIRECTION dir);

/**
 * @brief Adds a link to the space
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space
 * @param link pointer to the link to be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_add_link(Space *space, Link *link);

/**
 * @brief Adds an object to the space
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space
 * @param object pointer to the object to be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_add_object(Space *space, Id object);

/**
 * @brief It prints the space information
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_print(Space *space);

/**
 * @brief returns if the space has the object specified
 * @author Ignacio Sánchez
 *
 * @param space Space to check
 * @param object id of the object
 * @return TRUE or FALSE
 */
BOOL space_has_object_id(Space *space, Id object);

/**
 * @brief Deletes an object from a space
 * @author Ignacio Sánchez
 *
 * @param space Space to delete from
 * @param object id of the object
 * @return OK, ERROR in case of error
 */
STATUS space_del_object(Space *space, Id object);

/**
 * @brief Gets the number of objects in the space
 * @author Ignacio Sánchez
 *
 * @param space Space to check
 * @return number of objects
 */
int space_get_num_obj(Space *space);

/**
 * @brief returns the array of objects in the space
 * @author Ignacio Sánchez
 *
 * @param space Space to be analized
 * @return array of ids
 */
Id *space_get_object_set(Space *space);

/**
 * @brief returns the gdesc of a space
 * @author Ignacio Sánchez
 *
 * @param space Space to check
 * @return gdesc of the space
 */
char **space_get_gdesc(Space *space);

/**
 * @brief copies a graphic description into the space gdesc
 * @author Ignacio Sánchez
 *
 * @param space Space to modify
 * @param desc double pointer to the description
 * @return OK, ERROR in case of error
 */
STATUS space_set_gdesc(Space *space, char **desc);

/**
 * @brief returns whether the space is light 
 * @author Ignacio Sánchez
 *
 * @param space Space to check
 * @return TRUE if the space is light, FALSE otherwise
 */
BOOL space_get_light(Space *space);

/**
 * @brief sets the light on the given space to a value
 * @author Ignacio Sánchez
 *
 * @param space Space to modify
 * @param light BOOLEAN with the light
 * @return OK, ERROR in case of error
 */
STATUS space_set_light(Space *space, BOOL light);

/**
 * @brief It sets the detailed description of a space
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space
 * @param description a string with the description to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_set_det_descr(Space *space, char *description);

/**
 * @brief It gets the detailed description of a space
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space
 * @return  a string with the description of the space
 */
const char *space_get_det_descr(Space *space);

/**
 * @brief It gets the the link with the given name
 * @author Ignacio Sánchez
 *
 * @param space a pointer to the space
 * @param name the name of the link
 * @return pointer to the link
 */
Link *space_get_link_with_name(Space *space, const char *name);

/**
 * @brief writes the state of the space to the file
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param space pointer to the space
 * @param file pointer to the file
 * @return OK, ERROR if an error occurred
 */
STATUS space_print_to_save(Space *space, FILE *file);

#endif

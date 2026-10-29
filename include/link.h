/**
 * @brief It defines the linnk interface
 *
 * @file link.h
 * @author Álvaro de Santos
 * @version 2.0
 * @date 06-02-2023
 * @copyright GNU Public License
 */

#ifndef LINK_H
#define LINK_H

#include "types.h"

typedef struct _Link Link; /*!< Definition of the link structure */

/*CREATE/DESTROY*/
/**
 * @brief Creates the data structure of an link
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param id of the link
 * @return pointer to the structure
 */
Link *link_create(Id id);

/**
 * @brief Destroys the given link
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link to destroy
 * @return OK, ERROR in case of error
 */
STATUS link_destroy(Link *link);

/*SETTERS*/
/**
 * @brief Sets the name field of the link to the one given
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link to modify
 * @param name pointer to the string to be copied
 * @return OK, ERROR in case of error
 */
STATUS link_set_name(Link *link, char *name);

/**
 * @brief Sets the origin field of the link to the one given
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link to modify
 * @param or the id to be copied
 * @return OK, ERROR in case of error
 */
STATUS link_set_origin(Link *link, Id or);

/**
 * @brief Sets the destination field of the link to the one given
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link to modify
 * @param dest the id to be copied
 * @return OK, ERROR in case of error
 */
STATUS link_set_destination(Link *link, Id dest);

/**
 * @brief Sets the direction field of the link to the one given
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link to modify
 * @param dir the direction to be copied
 * @return OK, ERROR in case of error
 */
STATUS link_set_direction(Link *link, DIRECTION dir);

/**
 * @brief Sets the status field of the link to the one given
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link to modify
 * @param st the status to be copied
 * @return OK, ERROR in case of error
 */
STATUS link_set_status(Link *link, LINKSTATUS st);

/*GETTERS*/
/**
 * @brief Obtains the id of a link
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link
 * @return id of the link
 */
Id link_get_id(Link *link);

/**
 * @brief Obtains the name of a link
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link
 * @return id of the link
 */
char *link_get_name(Link *link);

/**
 * @brief Obtains the origin of a link
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link
 * @return origin of the link
 */
Id link_get_origin(Link *link);

/**
 * @brief Obtains the destination of a link
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link
 * @return destination of the link
 */
Id link_get_destination(Link *link);

/**
 * @brief Obtains the direction of a link
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link
 * @return direction of the link
 */
DIRECTION link_get_direction(Link *link);

/**
 * @brief Obtains the status of a link
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link
 * @return status of the link
 */
LINKSTATUS link_get_status(Link *link);

/*PRINTERS*/
/**
 * @brief Prints the info of a link
 *
 * @date 25/03/2023
 * @author: Álvaro de Santos
 *
 * @param link pointer to the link
 * @return OK, ERROR in case of error
 */
STATUS link_print(Link *link);

/**
 * @brief writes the state of the link to the file
 *
 * @date 15/02/2023
 * @author: Ignacio Sánchez
 *
 * @param link pointer to the link
 * @param file pointer to the file
 * @return OK, ERROR if an error occurred
 */
STATUS link_print_to_save(Link *link, FILE *file);

#endif
/**
 * @brief It defines the set interface
 *
 * @file set.h
 * @author Fabio Desio
 * @version 2.0
 * @date 20-02-2023
 * @copyright GNU Public License
 */
#ifndef SET_H
#define SET_H

#include "types.h"

typedef struct _Set Set; /*!< Definition of the set structure */

/**
 * @brief Creates the data structure of a set
 *
 * @date 20/02/2023
 * @author: Fabio Desio
 *
 * @return pointer to the structure
 */
Set *set_create();

/**
 * @brief Gets the position of the id specified
 * @author: Fabio Desio
 *
 * @param set pointer to the set
 * @param id to be found
 * @return position where the id is
 */
int set_get_id_pos(Set *set, Id id);

/**
 * @brief Gets the number of ids in the set
 * @author: Fabio Desio
 *
 * @param set pointer to the set
 * @return number of ids
 */
int set_get_n_ids(Set *set);

/**
 * @brief gets the id at a specified position
 * @author: Fabio Desio
 *
 * @param set pointer to the set
 * @param pos position to be checked
 * @return OK, ERROR in case of error
 */
Id set_get_pos_id(Set *set, int pos);

/**
 * @brief Frees the memory allocated for the set
 * @author: Fabio Desio
 *
 * @param set pointer to the set
 * @return OK, ERROR in case of error
 */
STATUS set_destroy(Set *set);

/**
 * @brief Adds an id to the set
 * @author: Fabio Desio
 *
 * @param set pointer to the set
 * @param id id to be added
 * @return OK, ERROR in case of error
 */
STATUS set_add(Set *set, Id id);

/**
 * @brief deletes an id from the set
 * @author: Fabio Desio
 *
 * @param set pointer to the set
 * @param id the id to be deleted
 * @return OK, ERROR in case of error
 */
STATUS set_del(Set *set, Id id);

/**
 * @brief prints the information of a set
 * @author: Fabio Desio
 *
 * @param set pointer to the set
 * @return OK, ERROR in case of error
 */
STATUS set_print(Set *set);

#endif

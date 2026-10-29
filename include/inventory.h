/**
 * @brief It defines the inventory interface
 *
 * @file inventory.h
 * @author Fabio Desio
 * @version 2.0
 * @date 04-03-2023
 * @copyright GNU Public License
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"
#include "set.h"

typedef struct _Inventory Inventory; /*!< Definition of the inventory structure */

#define MAX_INVENTORY_SIZE 10 /*!< Maximum number of objects that an inventory can carry */

/**
 * @brief get the number of items in the inventory
 * @author Ignacio Sánchez
 *
 * @return number of items
 */
int inventory_get_n_objs(Inventory *inventory);

/**
 * @brief Creates a new inventory, allocating memory and initializing its values
 * @author Fabio Desio
 *
 * @return pointer to the newly allocated inventory
 */
Inventory *inventory_create();

/**
 * @brief Destroys an inventory, freeing the previously allocated memory
 * @author Fabio Desio
 *
 * @param inventory pointer to the inventory to destroy
 * @return OK, ERROR in case of error
 */
STATUS inventory_destroy(Inventory *inventory);

/**
 * @brief Adds an object to the inventory's set of objects
 * @author Fabio Desio
 *
 * @param inventory pointer to the inventory
 * @param object id of the object to add to the inventory
 * @return OK, ERROR in case of error
 */
STATUS inventory_add_object(Inventory *inventory, Id object);

/**
 * @brief Deletes an object from the inventory's set of objects
 * @author Fabio Desio
 *
 * @param inventory pointer to the inventory from which to delete the object
 * @param object id to the object to delete from the inventory
 * @return OK, ERROR in case of error
 */
STATUS inventory_del_object(Inventory *inventory, Id object);

/**
 * @brief Gets the set of objects from the inventory structure
 * @author Fabio Desio
 *
 * @param inventory pointer to the inventory
 * @return pointer to the set of objects
 */
Set *inventory_get_object_set(Inventory *inventory);

/**
 * @brief Gets the maximum number of objects from the inventory structure
 * @author Fabio Desio
 *
 * @param inventory pointer to the inventory
 * @return maximum number of objects in the inventory
 */
int inventory_get_max_objs(Inventory *inventory);

/**
 * @brief Replaces the set of objects in the inventory structure
 * @author Fabio Desio
 *
 * @param inventory pointer to the inventory to modify
 * @param objs pointer to the set of objects
 * @return OK, ERROR in case of error
 */
STATUS inventory_set_object_set(Inventory *inventory, Set *objs);

/**
 * @brief Sets a new maximum number of objects value in the inventory structure
 * @author Fabio Desio
 *
 * @param inventory pointer to the inventory to modify
 * @param max_objs maximum number of objects we want the inventory to carry
 * @return OK, ERROR in case of error
 */
STATUS inventory_set_max_objs(Inventory *inventory, int max_objs);

/**
 * @brief Checks if an inventory carries an object
 * @author Fabio Desio
 *
 * @param inventory pointer to the inventory to check
 * @param obj id of the object to check
 * @return TRUE, FALSE if it not belongs
 */
BOOL inventory_has_obj(Inventory *inventory, Id obj);

/**
 * @brief Prints the given inventory
 * @author Fabio Desio
 *
 * @param inventory pointer to the inventory to print
 * @return OK, ERROR in case of error
 */
STATUS inventory_print(Inventory *inventory);

#endif
/**
 * @brief It implements the inventory module
 *
 * @file inventory.c
 * @author Fabio Desio
 * @version 3.0
 * @date 03-04-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"
#include "inventory.h"

/**
 * @brief Inventory
 *
 * This struct stores all the information of an inventory
 */
struct _Inventory
{
    Set *objs;    /*!< Set of objects for the inventory */
    int max_objs; /*!< Max number of objects the inventory carries */
};

/**
 * inventory_get_n_objs returns the number of objects the inventory
 */
int inventory_get_n_objs(Inventory *inventory)
{
    if (inventory == NULL)
    {
        return -1;
    }

    return set_get_n_ids(inventory->objs);
}

/**
 * inventory_create allocates memory for the new inventory and initializes its values
 */
Inventory *inventory_create()
{
    Inventory *newInv = NULL;

    newInv = (Inventory *)malloc(sizeof(newInv[0]));
    if (newInv == NULL)
    {
        return NULL;
    }

    newInv->objs = set_create();
    newInv->max_objs = MAX_INVENTORY_SIZE;

    return newInv;
}

/**
 * inventory_destroy frees the previous memory allocation for an inventory
 */
STATUS inventory_destroy(Inventory *inventory)
{
    if (inventory == NULL)
    {
        return ERROR;
    }

    set_destroy(inventory->objs);
    free(inventory);

    return OK;
}

/**
 * inventory_add_object adds the object's id to the inventory's set of objects
 */
STATUS inventory_add_object(Inventory *inventory, Id object)
{
    if (inventory == NULL || object == NO_ID || inventory_get_n_objs(inventory) >= inventory->max_objs)
    {
        return ERROR;
    }

    return set_add(inventory->objs, object);
}

/**
 * inventory_del_object removes the object's id from the inventory's set of objects
 */
STATUS inventory_del_object(Inventory *inventory, Id object)
{
    if (inventory == NULL || object == NO_ID)
    {
        return ERROR;
    }

    return set_del(inventory->objs, object);
}

/**
 * inventory_get_object_set gets the inventory's set of objects
 */
Set *inventory_get_object_set(Inventory *inventory)
{
    if (inventory == NULL)
    {
        return NULL;
    }

    return inventory->objs;
}

/**
 * inventory_has_obj checks if an object's id belongs to an inventory
 */
BOOL inventory_has_obj(Inventory *inventory, Id obj)
{
    if (inventory == NULL || obj == NO_ID)
    {
        return FALSE;
    }

    if (set_get_id_pos(inventory->objs, obj) == NO_ID)
    {
        return FALSE;
    }

    return TRUE;
}

/**
 * inventory_get_max_objs gets the maximum number of objects of the inventory
 */
int inventory_get_max_objs(Inventory *inventory)
{
    if (inventory == NULL)
    {
        return -1;
    }

    return inventory->max_objs;
}

/**
 * inventory_set_object_set replaces the inventory's set of objects with another set
 */
STATUS inventory_set_object_set(Inventory *inventory, Set *objs)
{
    if (inventory == NULL || objs == NULL)
    {
        return ERROR;
    }

    set_destroy(inventory->objs);
    inventory->objs = objs;

    return OK;
}

/**
 * inventory_set_max_objs replaces the inventory's max_objs camp with a new limit
 */
STATUS inventory_set_max_objs(Inventory *inventory, int max_objs)
{
    if (inventory == NULL || max_objs < 1)
    {
        return ERROR;
    }

    inventory->max_objs = max_objs;

    return OK;
}

/**
 * inventory_print prints the given inventory
 */
STATUS inventory_print(Inventory *inventory)
{
    if (inventory == NULL)
    {
        return ERROR;
    }

    fprintf(stdout, "--> Inventory (max_objs): %d)\n", inventory_get_max_objs(inventory));

    set_print(inventory_get_object_set(inventory));

    return OK;
}
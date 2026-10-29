/**
 * @brief It declares the tests for the inventory module
 *
 * @file inventory_test.h
 * @author Fabio Desio
 * @version 2.0
 * @date 04-04-2023
 * @copyright GNU Public License
 */

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

/**
 * @test Test inventory creation
 * @pre None
 * @post Non NULL pointer to inventory
 */
void test1_inventory_create();

/**
 * @test Test inventory creation
 * @pre None
 * @post Inventory with default max_objs
 */
void test2_inventory_create();

/**
 * @test Test object addition to inventory
 * @pre Inventory created and object ID provided
 * @post OK status and object added to inventory
 */
void test1_inventory_add_object();

/**
 * @test Test object addition to NULL inventory
 * @pre None
 * @post ERROR status returned
 */
void test2_inventory_add_object();

/**
 * @test Test object deletion from inventory
 * @pre Inventory created, object added to inventory
 * @post OK status and object deleted from inventory
 */
void test1_inventory_del_object();

/**
 * @test Test object deletion from NULL inventory
 * @pre None
 * @post ERROR status returned
 */
void test2_inventory_del_object();

/**
 * @test Test inventory object set getter
 * @pre Inventory created and object added to inventory
 * @post Non NULL object set returned
 */
void test1_inventory_get_object_set();

/**
 * @test Test inventory object set getter from NULL inventory
 * @pre None
 * @post NULL object set returned
 */
void test2_inventory_get_object_set();

/**
 * @test Test inventory max_objs getter
 * @pre Inventory created
 * @post Default max_objs value returned
 */
void test1_inventory_get_max_objs();

/**
 * @test Test inventory max_objs getter from NULL inventory
 * @pre None
 * @post -1 returned
 */
void test2_inventory_get_max_objs();

/**
 * @test Test inventory object set setter
 * @pre Inventory created and object set created
 * @post OK status returned and object set updated
 */
void test1_inventory_set_object_set();

/**
 * @test Test inventory object set setter with NULL object set
 * @pre Inventory created
 * @post ERROR status returned
 */
void test2_inventory_set_object_set();

/**
 * @test Test inventory max_objs setter
 * @pre Inventory created
 * @post OK status and max_objs updated
 */
void test1_inventory_set_max_objs();

/**
 * @test Test inventory max_objs setter with negative value
 * @pre Inventory created
 * @post ERROR status returned
 */
void test2_inventory_set_max_objs();

/**
 * @test Test inventory object checking
 * @pre Inventory created and object added to inventory
 * @post TRUE returned
 */
void test1_inventory_has_obj();

/**
 * @test Test inventory object checking with non-existing object
 * @pre Inventory created
 * @post FALSE returned
 */
void test2_inventory_has_obj();

#endif
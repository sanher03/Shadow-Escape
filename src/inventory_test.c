/**
 * @brief It tests inventory module
 *
 * @file inventory_test.c
 * @author Fabio Desio
 * @version 3.0
 * @date 04-04-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "inventory_test.h"
#include "test.h"
#include "set.h"

#define MAX_TESTS 16 /*!< Total number of tests*/

/**
 * @brief Main function for INVENTORY unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
int main(int argc, char **argv)
{

    int test = 0;
    int all = 1;

    if (argc < 2)
    {
        printf("Running all test for module Inventory:\n");
    }
    else
    {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 || test > MAX_TESTS)
        {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 1)
        test1_inventory_create();
    if (all || test == 2)
        test2_inventory_create();
    if (all || test == 3)
        test1_inventory_add_object();
    if (all || test == 4)
        test2_inventory_add_object();
    if (all || test == 5)
        test1_inventory_del_object();
    if (all || test == 6)
        test2_inventory_del_object();
    if (all || test == 7)
        test1_inventory_get_object_set();
    if (all || test == 8)
        test2_inventory_get_object_set();
    if (all || test == 9)
        test1_inventory_get_max_objs();
    if (all || test == 10)
        test2_inventory_get_max_objs();
    if (all || test == 11)
        test1_inventory_set_object_set();
    if (all || test == 12)
        test2_inventory_set_object_set();
    if (all || test == 13)
        test1_inventory_set_max_objs();
    if (all || test == 14)
        test2_inventory_set_max_objs();
    if (all || test == 15)
        test1_inventory_has_obj();
    if (all || test == 16)
        test2_inventory_has_obj();

    PRINT_PASSED_PERCENTAGE;

    return __test_passed == __test_counter ? 0 : 1;
}

/**
 *  First inventory creation test
 */
void test1_inventory_create()
{
    int result;
    Inventory *inv = NULL;
    inv = inventory_create();
    result = inv != NULL;
    PRINT_TEST_RESULT(result);
    inventory_destroy(inv);
}

/**
 * Second inventory creation test
 */
void test2_inventory_create()
{
    Inventory *inv = inventory_create();
    PRINT_TEST_RESULT(inventory_get_max_objs(inv) == MAX_INVENTORY_SIZE);
    inventory_destroy(inv);
}

/**
 *  First inventory add object test
 */
void test1_inventory_add_object()
{
    Inventory *inv;

    inv = inventory_create();
    PRINT_TEST_RESULT(inventory_add_object(inv, 23) == OK);
    inventory_destroy(inv);
}

/**
 * Second inventory add object test
 */
void test2_inventory_add_object()
{
    Inventory *inv = NULL;
    PRINT_TEST_RESULT(inventory_add_object(inv, 23) == ERROR);
}

/**
 *  First object deletion from inventory test
 */
void test1_inventory_del_object()
{
    Inventory *inv;

    inv = inventory_create();
    inventory_add_object(inv, 23);
    PRINT_TEST_RESULT(inventory_del_object(inv, 23) == OK);
    inventory_destroy(inv);
}

/**
 * Second object deletion from inventory test
 */
void test2_inventory_del_object()
{
    Inventory *inv = NULL;
    PRINT_TEST_RESULT(inventory_del_object(inv, NO_ID) == ERROR);
}

/**
 *  First inventory object getter test
 */
void test1_inventory_get_object_set()
{
    Inventory *s = inventory_create(23);
    Set *objs;
    inventory_add_object(s, 23);
    objs = inventory_get_object_set(s);
    PRINT_TEST_RESULT(objs != NULL);
    inventory_destroy(s);
}

/**
 * Second inventory object getter test
 */
void test2_inventory_get_object_set()
{
    Inventory *inv = NULL;
    PRINT_TEST_RESULT(inventory_get_object_set(inv) == NULL);
}

/**
 *  First inventory max_objs getter test
 */
void test1_inventory_get_max_objs()
{
    Inventory *inv;

    inv = inventory_create();
    PRINT_TEST_RESULT(inventory_get_max_objs(inv) == MAX_INVENTORY_SIZE);
    inventory_destroy(inv);
}

/**
 * Second inventory max_objs getter test
 */
void test2_inventory_get_max_objs()
{
    Inventory *inv = NULL;
    PRINT_TEST_RESULT(inventory_get_max_objs(inv) == -1);
}

/**
 *  First inventory object set setter test
 */
void test1_inventory_set_object_set()
{
    Inventory *inv = inventory_create();
    Set *objs = set_create();

    PRINT_TEST_RESULT(inventory_set_object_set(inv, objs) == OK);
    inventory_destroy(inv);
}

/**
 * Second inventory object set setter test
 */
void test2_inventory_set_object_set()
{
    Inventory *inv = NULL;
    Set *objs = NULL;

    PRINT_TEST_RESULT(inventory_set_object_set(inv, objs) == ERROR);
}

/**
 *  First inventory max_objs setter test
 */
void test1_inventory_set_max_objs()
{
    Inventory *inv = inventory_create();
    STATUS st = inventory_set_max_objs(inv, 23);

    PRINT_TEST_RESULT((st == OK) && (inventory_get_max_objs(inv) == 23));
    inventory_destroy(inv);
}

/**
 * Second inventory max_objs setter test
 */
void test2_inventory_set_max_objs()
{
    Inventory *inv = inventory_create();
    PRINT_TEST_RESULT(inventory_set_max_objs(inv, -1) == ERROR);
    inventory_destroy(inv);
}

/**
 *  First inventory object checking test
 */
void test1_inventory_has_obj()
{
    Inventory *inv = inventory_create();
    inventory_add_object(inv, 23);

    PRINT_TEST_RESULT(inventory_has_obj(inv, 23) == TRUE);
    inventory_destroy(inv);
}

/**
 * Second inventory object checking test
 */
void test2_inventory_has_obj()
{
    Inventory *inv = inventory_create();
    PRINT_TEST_RESULT(inventory_has_obj(inv, 23) == FALSE);
    inventory_destroy(inv);
}
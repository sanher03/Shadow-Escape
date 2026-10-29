/**
 * @brief It tests enemy module
 *
 * @file enemy_test.c
 * @author Fabio Desio
 * @version 3.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enemy.h"
#include "enemy_test.h"
#include "test.h"

#define MAX_TESTS 16 /*!< Total number of tests*/

/**
 * @brief Main function for enemy unit tests.
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
        printf("Running all test for module Space:\n");
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
        test1_enemy_create();
    if (all || test == 2)
        test2_enemy_create();
    if (all || test == 3)
        test1_enemy_get_id();
    if (all || test == 4)
        test2_enemy_get_id();
    if (all || test == 5)
        test1_enemy_set_name();
    if (all || test == 6)
        test2_enemy_set_name();
    if (all || test == 7)
        test1_enemy_get_name();
    if (all || test == 8)
        test2_enemy_get_name();
    if (all || test == 9)
        test1_enemy_set_health();
    if (all || test == 10)
        test2_enemy_set_health();
    if (all || test == 11)
        test1_enemy_get_health();
    if (all || test == 12)
        test2_enemy_get_health();
    if (all || test == 13)
        test1_enemy_set_location();
    if (all || test == 14)
        test2_enemy_set_location();
    if (all || test == 15)
        test1_enemy_get_location();
    if (all || test == 16)
        test2_enemy_get_location();

    PRINT_PASSED_PERCENTAGE;

    return __test_passed == __test_counter ? 0 : 1;
}

/**
 * First enemy id getter test
 */
void test1_enemy_create()
{
    int result;
    Enemy *e;
    e = enemy_create(7);
    result = e != NULL;
    PRINT_TEST_RESULT(result);
    enemy_destroy(e);
}

/**
 * Second enemy id getter test
 */
void test2_enemy_create()
{
    Enemy *e;
    e = enemy_create(7);
    PRINT_TEST_RESULT(enemy_get_id(e) == 7);
    enemy_destroy(e);
}

/**
 * First enemy id getter test
 */
void test1_enemy_get_id()
{
    Enemy *e;
    e = enemy_create(23);
    PRINT_TEST_RESULT(enemy_get_id(e) == 23);
    enemy_destroy(e);
}

/**
 * Second enemy id getter test
 */
void test2_enemy_get_id()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_get_id(e) == NO_ID);
}

/**
 * First enemy name setter test
 */
void test1_enemy_set_name()
{
    Enemy *e;
    e = enemy_create(23);
    PRINT_TEST_RESULT(enemy_set_name(e, "Fabio") == OK);
    enemy_destroy(e);
}

/**
 * Second enemy name setter test
 */
void test2_enemy_set_name()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_name(e, "Fabio") == ERROR);
}

/**
 * First enemy name getter test
 */
void test1_enemy_get_name()
{
    Enemy *e;
    e = enemy_create(23);
    enemy_set_name(e, "Fabio");
    PRINT_TEST_RESULT(strcmp(enemy_get_name(e), "Fabio") == 0);
    enemy_destroy(e);
}

/**
 * Second enemy name getter test
 */
void test2_enemy_get_name()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_get_name(e) == NULL);
}

/**
 * First enemy health setter test
 */
void test1_enemy_set_health()
{
    Enemy *e;
    e = enemy_create(23);
    PRINT_TEST_RESULT(enemy_set_health(e, 10) == OK);
    enemy_destroy(e);
}

/**
 * Second enemy health setter test
 */
void test2_enemy_set_health()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_health(e, 10) == ERROR);
}

/**
 * First enemy location getter test
 */
void test1_enemy_get_health()
{
    Enemy *e;
    e = enemy_create(23);
    enemy_set_health(e, 10);
    PRINT_TEST_RESULT(enemy_get_health(e) == 10);
    enemy_destroy(e);
}

/**
 * Second enemy location getter test
 */
void test2_enemy_get_health()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_get_health(e) == -1);
}

/**
 * First enemy location setter test
 */
void test1_enemy_set_location()
{
    Enemy *e;
    e = enemy_create(23);
    PRINT_TEST_RESULT(enemy_set_location(e, 1) == OK);
    enemy_destroy(e);
}

/**
 * Second enemy location setter test
 */
void test2_enemy_set_location()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_location(e, 1) == ERROR);
}

/**
 * First enemy location getter test
 */
void test1_enemy_get_location()
{
    Enemy *e;
    e = enemy_create(23);
    enemy_set_location(e, 1);
    PRINT_TEST_RESULT(enemy_get_location(e) == 1);
    enemy_destroy(e);
}

/**
 * Second enemy location getter test
 */
void test2_enemy_get_location()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_get_location(e) == NO_ID);
}
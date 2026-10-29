/**
 * @brief It tests player module
 *
 * @file player_test.c
 * @author Fabio Desio
 * @version 3.0
 * @date 04-04-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "player_test.h"
#include "set.h"
#include "inventory.h"
#include "test.h"

#define MAX_TESTS 24 /*!< Total number of tests*/

/**
 * @brief Main function for SPACE unit tests.
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
        printf("Running all test for module Player:\n");
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
        test1_player_create();
    if (all || test == 2)
        test2_player_create();
    if (all || test == 3)
        test1_player_add_object();
    if (all || test == 4)
        test2_player_add_object();
    if (all || test == 5)
        test1_player_del_object();
    if (all || test == 6)
        test2_player_del_object();
    if (all || test == 7)
        test1_player_get_inventory();
    if (all || test == 8)
        test2_player_get_inventory();
    if (all || test == 9)
        test1_player_get_id();
    if (all || test == 10)
        test2_player_get_id();
    if (all || test == 11)
        test1_player_set_name();
    if (all || test == 12)
        test2_player_set_name();
    if (all || test == 13)
        test1_player_get_name();
    if (all || test == 14)
        test2_player_get_name();
    if (all || test == 15)
        test1_player_set_health();
    if (all || test == 16)
        test2_player_set_health();
    if (all || test == 17)
        test1_player_get_health();
    if (all || test == 18)
        test2_player_get_health();
    if (all || test == 19)
        test1_player_set_location();
    if (all || test == 20)
        test2_player_set_location();
    if (all || test == 21)
        test1_player_get_location();
    if (all || test == 22)
        test2_player_get_location();
    if (all || test == 23)
        test1_player_get_num_objects();
    if (all || test == 24)
        test2_player_get_num_objects();

    PRINT_PASSED_PERCENTAGE;

    return __test_passed == __test_counter ? 0 : 1;
}

/** First player creation test
 */
void test1_player_create()
{
    int result;
    Player *s;
    s = player_create(7);
    result = s != NULL;
    PRINT_TEST_RESULT(result);
    player_destroy(s);
}

/** Second player creation test
 */
void test2_player_create()
{
    Player *s;
    s = player_create(7);
    PRINT_TEST_RESULT(player_get_id(s) == 7);
    player_destroy(s);
}

/**
 * First player add object test
 */
void test1_player_add_object()
{
    Player *p = player_create(23);
    PRINT_TEST_RESULT(player_add_object(p, 2) != ERROR);
    player_destroy(p);
}

/**
 * Second player add object test
 */
void test2_player_add_object()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_add_object(p, 2) == ERROR);
}

/**
 * First player delete object test
 */
void test1_player_del_object()
{
    Player *p = player_create(23);
    player_add_object(p, 23);
    PRINT_TEST_RESULT(player_del_object(p, 23) != ERROR);
    player_destroy(p);
}

/**
 * Second player delete object test
 */
void test2_player_del_object()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_del_object(p, 23) == ERROR);
}

/**
 * First player inventory getter test
 */
void test1_player_get_inventory()
{
    Player *p = player_create(23);
    PRINT_TEST_RESULT(player_get_inventory(p) != NULL);
    player_destroy(p);
}

/**
 * Second player inventory getter test
 */
void test2_player_get_inventory()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_get_inventory(p) == NULL);
}

/**
 * First player id getter test
 */
void test1_player_get_id()
{
    Player *e;
    e = player_create(23);
    PRINT_TEST_RESULT(player_get_id(e) == 23);
    player_destroy(e);
}

/**
 * Second player id getter test
 */
void test2_player_get_id()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_get_id(e) == NO_ID);
}

/**
 * First player name setter test
 */
void test1_player_set_name()
{
    Player *e;
    e = player_create(23);
    PRINT_TEST_RESULT(player_set_name(e, "Fabio") == OK);
    player_destroy(e);
}

/**
 * Second player name setter test
 */
void test2_player_set_name()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_set_name(e, "Fabio") == ERROR);
}

/**
 * First player name getter test
 */
void test1_player_get_name()
{
    Player *e;
    e = player_create(23);
    player_set_name(e, "Fabio");
    PRINT_TEST_RESULT(strcmp(player_get_name(e), "Fabio") == 0);
    player_destroy(e);
}

/**
 * Second player name getter test
 */
void test2_player_get_name()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_get_name(e) == NULL);
}

/**
 * First player health setter test
 */
void test1_player_set_health()
{
    Player *e;
    e = player_create(23);
    PRINT_TEST_RESULT(player_set_health(e, 10) == OK);
    player_destroy(e);
}

/**
 * Second player health setter test
 */
void test2_player_set_health()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_set_health(e, 10) == ERROR);
}

/**
 * First player location getter test
 */
void test1_player_get_health()
{
    Player *e;
    e = player_create(23);
    player_set_health(e, 10);
    PRINT_TEST_RESULT(player_get_health(e) == 10);
    player_destroy(e);
}

/**
 * Second player location getter test
 */
void test2_player_get_health()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_get_health(e) == -1);
}

/**
 * First player location setter test
 */
void test1_player_set_location()
{
    Player *e;
    e = player_create(23);
    PRINT_TEST_RESULT(player_set_location(e, 1) == OK);
    player_destroy(e);
}

/**
 * Second player location setter test
 */
void test2_player_set_location()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_set_location(e, 1) == ERROR);
}

/**
 * First player location getter test
 */
void test1_player_get_location()
{
    Player *e;
    e = player_create(23);
    player_set_location(e, 1);
    PRINT_TEST_RESULT(player_get_location(e) == 1);
    player_destroy(e);
}

/**
 * Second player location getter test
 */
void test2_player_get_location()
{
    Player *e = NULL;
    PRINT_TEST_RESULT(player_get_location(e) == NO_ID);
}

/**
 * First player get num objects
 */
void test1_player_get_num_objects()
{
    Player *p = player_create(23);
    player_add_object(p, 23);
    PRINT_TEST_RESULT(player_get_num_objects(p) == 1);
    player_destroy(p);
}

/**
 * Second player get num objects
 */
void test2_player_get_num_objects()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_get_num_objects(p) == 0);
}
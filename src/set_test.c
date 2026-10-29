/**
 * @brief It tests set module
 *
 * @file space_test.c
 * @author Fabio Desio
 * @version 3.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "set_test.h"
#include "test.h"

#define MAX_TESTS 12 /*!< Total number of tests*/

/**
 * @brief Main function for set unit tests.
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
        printf("Running all test for module Set:\n");
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
        test1_set_create();
    if (all || test == 2)
        test2_set_create();
    if (all || test == 3)
        test1_set_add();
    if (all || test == 4)
        test2_set_add();
    if (all || test == 5)
        test1_set_del();
    if (all || test == 6)
        test2_set_del();
    if (all || test == 7)
        test1_set_get_id_pos();
    if (all || test == 8)
        test2_set_get_id_pos();
    if (all || test == 9)
        test1_set_get_n_ids();
    if (all || test == 10)
        test2_set_get_n_ids();
    if (all || test == 11)
        test1_set_get_pos_id();
    if (all || test == 12)
        test2_set_get_pos_id();

    PRINT_PASSED_PERCENTAGE;

    return __test_passed == __test_counter ? 0 : 1;
}

/**
 * First set create test
 */
void test1_set_create()
{
    int result;
    Set *s;
    s = set_create();
    result = s != NULL;
    PRINT_TEST_RESULT(result);
    set_destroy(s);
}

/**
 * Second set create test
 */
void test2_set_create()
{
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_get_n_ids(s) == 0);
    set_destroy(s);
}

/**
 * First set add test
 */
void test1_set_add()
{
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_add(s, 1) == OK);
    set_destroy(s);
}

/**
 * Second set add test
 */
void test2_set_add()
{
    Set *s = NULL;
    PRINT_TEST_RESULT(set_add(s, 1) == ERROR);
}

/**
 * First set deletion test
 */
void test1_set_del()
{
    Set *s;
    s = set_create();
    set_add(s, 1);
    PRINT_TEST_RESULT(set_del(s, 1) == OK);
    set_destroy(s);
}

/**
 * Second set deletion test
 */
void test2_set_del()
{
    Set *s;
    s = set_create();
    PRINT_TEST_RESULT(set_del(s, 1) == OK);
    set_destroy(s);
}

/**
 * First set get pos from id test
 */
void test1_set_get_id_pos()
{
    Set *s;
    s = set_create();
    set_add(s, 1);
    set_add(s, 2);
    PRINT_TEST_RESULT(set_get_id_pos(s, 2) == 1);
    set_destroy(s);
}

/**
 * Second set get pos from id test
 */
void test2_set_get_id_pos()
{
    int result;
    Set *s;
    s = set_create();
    set_add(s, 1);
    set_add(s, 2);
    result = set_get_id_pos(s, 3) == -1;
    PRINT_TEST_RESULT(result);
    set_destroy(s);
}

/**
 * First set n_ids getter
 */
void test1_set_get_n_ids()
{
    int result;
    Set *s;
    s = set_create();
    set_add(s, 1);
    set_add(s, 2);
    result = set_get_n_ids(s) == 2;
    PRINT_TEST_RESULT(result);
    set_destroy(s);
}

/**
 * Second set n_ids getter
 */
void test2_set_get_n_ids()
{
    Set *s = NULL;
    PRINT_TEST_RESULT(set_get_n_ids(s) == NO_ID);
}

/**
 * First set pos getter
 */
void test1_set_get_pos_id()
{
    int result;
    Set *s;
    s = set_create();
    set_add(s, 1);
    set_add(s, 2);
    result = set_get_pos_id(s, 1) == 2;
    PRINT_TEST_RESULT(result);
    set_destroy(s);
}

/**
 * Second set pos getter
 */
void test2_set_get_pos_id()
{
    int result;
    Set *s;
    s = set_create();
    set_add(s, 1);
    set_add(s, 2);
    result = set_get_pos_id(s, 2) == -1;
    PRINT_TEST_RESULT(result);
    set_destroy(s);
}
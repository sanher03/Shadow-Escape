/**
 * @brief It tests link module
 *
 * @file link_test.c
 * @author Fabio Desio
 * @version 3.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"
#include "link_test.h"
#include "test.h"

#define MAX_TESTS 24 /*!< Maximum number of tests*/

/**
 * @brief Main function for LINK unit tests.
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
        printf("Running all test for module Link:\n");
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
        test1_link_create();
    if (all || test == 2)
        test2_link_create();
    if (all || test == 3)
        test1_link_get_id();
    if (all || test == 4)
        test2_link_get_id();
    if (all || test == 5)
        test1_link_set_name();
    if (all || test == 6)
        test2_link_set_name();
    if (all || test == 7)
        test1_link_get_origin();
    if (all || test == 8)
        test2_link_get_origin();
    if (all || test == 9)
        test1_link_set_origin();
    if (all || test == 10)
        test2_link_set_origin();
    if (all || test == 11)
        test1_link_get_destination();
    if (all || test == 12)
        test2_link_get_destination();
    if (all || test == 13)
        test1_link_set_destination();
    if (all || test == 14)
        test2_link_set_destination();
    if (all || test == 15)
        test1_link_get_status();
    if (all || test == 16)
        test2_link_get_status();
    if (all || test == 17)
        test1_link_set_status();
    if (all || test == 18)
        test2_link_set_status();
    if (all || test == 19)
        test1_link_get_direction();
    if (all || test == 20)
        test2_link_get_direction();
    if (all || test == 21)
        test1_link_set_direction();
    if (all || test == 22)
        test2_link_set_direction();
    if (all || test == 23)
        test1_link_get_name();
    if (all || test == 24)
        test2_link_get_name();

    PRINT_PASSED_PERCENTAGE;

    return __test_passed == __test_counter ? 0 : 1;
}

/* TODO: */

/** First link creation test
 */
void test1_link_create()
{
    int result;
    Link *s;
    s = link_create(7);
    result = s != NULL;
    PRINT_TEST_RESULT(result);
    link_destroy(s);
}

/** Second link creation test
 */
void test2_link_create()
{
    Link *s;
    s = link_create(7);
    PRINT_TEST_RESULT(link_get_id(s) == 7);
    link_destroy(s);
}

/**
 * First link id getter test
 */
void test1_link_get_id()
{
    Link *s;
    s = link_create(25);
    PRINT_TEST_RESULT(link_get_id(s) == 25);
    link_destroy(s);
}

/**
 * Second link id getter test
 */
void test2_link_get_id()
{
    Link *s = NULL;
    PRINT_TEST_RESULT(link_get_id(s) == NO_ID);
}

/**
 * First link name setter test
 */
void test1_link_set_name()
{
    Link *s;
    s = link_create(5);
    PRINT_TEST_RESULT(link_set_name(s, "Alvaro") == OK);
    link_destroy(s);
}

/**
 * Second link name setter test
 */
void test2_link_set_name()
{
    Link *s = NULL;
    PRINT_TEST_RESULT(link_set_name(s, "Alvaro") == ERROR);
}

/**
 * First link name getter test
 */
void test1_link_get_name()
{
    Link *s;
    s = link_create(25);
    link_set_name(s, "Alvaro");
    PRINT_TEST_RESULT(strcmp(link_get_name(s), "Alvaro") == 0);
    link_destroy(s);
}

/**
 * Second link name getter test
 */
void test2_link_get_name()
{
    Link *s = NULL;
    PRINT_TEST_RESULT(link_get_name(s) == NULL);
}

/**
 * First link origin getter test
 */
void test1_link_get_origin()
{
    Link *s;
    s = link_create(5);
    link_set_origin(s, 4);
    PRINT_TEST_RESULT(link_get_origin(s) == 4);
    link_destroy(s);
}

/**
 * Second link origin getter test
 */
void test2_link_get_origin()
{
    Link *s = NULL;
    PRINT_TEST_RESULT(link_get_origin(s) == NO_ID);
}

/**
 * First link origin setter test
 */
void test1_link_set_origin()
{
    Link *s;
    s = link_create(5);
    PRINT_TEST_RESULT(link_set_origin(s, 4) == OK);
    link_destroy(s);
}

/**
 * Second link origin setter test
 */
void test2_link_set_origin()
{
    Link *s = NULL;
    PRINT_TEST_RESULT(link_set_origin(s, 4) == ERROR);
}

/**
 * First link destination getter test
 */
void test1_link_get_destination()
{
    Link *s;
    s = link_create(5);
    link_set_destination(s, 4);
    PRINT_TEST_RESULT(link_get_destination(s) == 4);
    link_destroy(s);
}

/**
 * Second link destination getter test
 */
void test2_link_get_destination()
{
    Link *s = NULL;
    PRINT_TEST_RESULT(link_get_destination(s) == NO_ID);
}

/**
 * First link destination setter test
 */
void test1_link_set_destination()
{
    Link *s;
    s = link_create(5);
    PRINT_TEST_RESULT(link_set_destination(s, 4) == OK);
    link_destroy(s);
}

/**
 * Second link destination setter test
 */
void test2_link_set_destination()
{
    Link *s = NULL;
    PRINT_TEST_RESULT(link_set_destination(s, 4) == ERROR);
}

/**
 * First link status getter test
 */
void test1_link_get_status()
{
    Link *s;
    s = link_create(5);
    link_set_status(s, OPENED);
    PRINT_TEST_RESULT(link_get_status(s) == OPENED);
    link_destroy(s);
}

/**
 * Second link status getter test
 */
void test2_link_get_status()
{
    Link *s = NULL;
    PRINT_TEST_RESULT(link_get_status(s) == CLOSED);
}

/**
 * First link status setter test
 */
void test1_link_set_status()
{
    Link *s;
    s = link_create(5);
    PRINT_TEST_RESULT(link_set_status(s, OPENED) == OK);
    link_destroy(s);
}

/**
 * Second link status setter test
 */
void test2_link_set_status()
{
    Link *s = NULL;
    PRINT_TEST_RESULT(link_set_status(s, OPENED) == ERROR);
}

/**
 * First link direction setter test
 */
void test1_link_set_direction()
{
    Link *s;
    s = link_create(5);
    PRINT_TEST_RESULT(link_set_direction(s, W) == OK);
    link_destroy(s);
}

/**
 * Second link direction setter test
 */
void test2_link_set_direction()
{
    Link *s = NULL;
    PRINT_TEST_RESULT(link_set_direction(s, W) == ERROR);
}

/**
 * First link direction getter test
 */
void test1_link_get_direction()
{
    Link *s;
    s = link_create(5);
    link_set_direction(s, N);
    PRINT_TEST_RESULT(link_get_direction(s) == N);
    link_destroy(s);
}

/**
 * Second link direction getter test
 */
void test2_link_get_direction()
{
    Link *s = NULL;
    PRINT_TEST_RESULT(link_get_direction(s) == N);
}
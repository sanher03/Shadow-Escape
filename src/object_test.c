/**
 * @brief It tests object module
 *
 * @file object_test.c
 * @author Álvaro de Santos
 * @version 3.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "object_test.h"
#include "test.h"

#define MAX_TESTS 37 /*!< Maximum number of tests*/

/**
 * @brief Main function for OBJECT unit tests.
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
        printf("Running all test for module Object:\n");
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
        test1_object_create();
    if (all || test == 2)
        test2_object_create();
    if (all || test == 3)
        test1_object_get_id();
    if (all || test == 4)
        test2_object_get_id();
    if (all || test == 5)
        test1_object_set_name();
    if (all || test == 6)
        test2_object_set_name();
    if (all || test == 7)
        test1_object_get_name();
    if (all || test == 8)
        test2_object_get_name();
    if (all || test == 9)
        test1_object_set_description();
    if (all || test == 10)
        test2_object_set_description();
    if (all || test == 11)
        test1_object_get_description();
    if (all || test == 12)
        test2_object_get_description();
    if (all || test == 13)
        test1_object_set_hidden();
    if (all || test == 14)
        test2_object_set_hidden();
    if (all || test == 15)
        test1_object_get_hidden();
    if (all || test == 16)
        test2_object_get_hidden();
    if (all || test == 17)
        test1_object_set_movable();
    if (all || test == 18)
        test2_object_set_movable();
    if (all || test == 19)
        test1_object_get_movable();
    if (all || test == 20)
        test2_object_get_movable();
    if (all || test == 21)
        test1_object_set_dependency();
    if (all || test == 22)
        test2_object_set_dependency();
    if (all || test == 23)
        test1_object_get_dependency();
    if (all || test == 24)
        test2_object_get_dependency();
    if (all || test == 25)
        test1_object_set_open();
    if (all || test == 26)
        test2_object_set_open();
    if (all || test == 27)
        test1_object_get_open();
    if (all || test == 28)
        test2_object_get_open();
    if (all || test == 29)
        test1_object_set_illuminate();
    if (all || test == 30)
        test2_object_set_illuminate();
    if (all || test == 31)
        test1_object_get_illuminate();
    if (all || test == 32)
        test2_object_get_illuminate();
    if (all || test == 33)
        test1_object_get_id();
    if (all || test == 34)
        test2_object_get_id();
    if (all || test == 35)
        test1_object_print();
    if (all || test == 36)
        test2_object_print();

    PRINT_PASSED_PERCENTAGE;

    return __test_passed == __test_counter ? 0 : 1;
}

/* TODO: */

/** First object creation test
 */
void test1_object_create()
{
    int result;
    Object *s;
    s = object_create(7);
    result = s != NULL;
    PRINT_TEST_RESULT(result);
    object_destroy(s);
}

/** Second object creation test
 */
void test2_object_create()
{
    Object *s;
    s = object_create(7);
    PRINT_TEST_RESULT(object_get_id(s) == 7);
    object_destroy(s);
}

/**
 * First object id getter test
 */
void test1_object_get_id()
{
    Object *s;
    s = object_create(25);
    PRINT_TEST_RESULT(object_get_id(s) == 25);
    object_destroy(s);
}

/**
 * Second object id getter test
 */
void test2_object_get_id()
{
    Object *s = NULL;
    PRINT_TEST_RESULT(object_get_id(s) == NO_ID);
}

/**
 * First object name setter test
 */
void test1_object_set_name()
{
    Object *s;
    s = object_create(5);
    PRINT_TEST_RESULT(object_set_name(s, "Alvaro") == OK);
    object_destroy(s);
}

/**
 * Second object name setter test
 */
void test2_object_set_name()
{
    Object *s = NULL;
    PRINT_TEST_RESULT(object_set_name(s, "Alvaro") == ERROR);
}

/**
 * First object name getter test
 */
void test1_object_get_name()
{
    Object *s;
    s = object_create(25);
    object_set_name(s, "Alvaro");
    PRINT_TEST_RESULT(strcmp(object_get_name(s), "Alvaro") == 0);
    object_destroy(s);
}

/**
 * Second object name getter test
 */
void test2_object_get_name()
{
    Object *s = NULL;
    PRINT_TEST_RESULT(object_get_name(s) == NULL);
}

/**
 * First object description setter test
 */
void test1_object_set_description()
{
    Object *s;
    s = object_create(5);
    PRINT_TEST_RESULT(object_set_description(s, "Alvaro") == OK);
    object_destroy(s);
}

/**
 * Second object description setter test
 */
void test2_object_set_description()
{
    Object *s = NULL;
    PRINT_TEST_RESULT(object_set_description(s, "Alvaro") == ERROR);
}

/**
 * First object description getter test
 */
void test1_object_get_description()
{
    Object *s;
    s = object_create(25);
    object_set_description(s, "Alvaro");
    PRINT_TEST_RESULT(strcmp(object_get_description(s), "Alvaro") == 0);
    object_destroy(s);
}

/**
 * Second object description getter test
 */
void test2_object_get_description()
{
    Object *s = NULL;
    PRINT_TEST_RESULT(object_get_description(s) == NULL);
}

void test1_object_set_hidden()
{
    Object *s = NULL;
    s = object_create(5);
    PRINT_TEST_RESULT(object_set_hidden(s, TRUE) == OK);
    object_destroy(s);
}

void test2_object_set_hidden()
{
        Object *s = NULL;

        PRINT_TEST_RESULT(object_set_hidden(s, TRUE) == ERROR);
}

void test1_object_get_hidden()
{
    Object *s = NULL;

    s = object_create(5);

    PRINT_TEST_RESULT(object_get_hidden(s) == TRUE);

    object_destroy(s);
}

void test2_object_get_hidden()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_get_hidden(s) == FALSE);
}

void test1_object_set_movable()
{
    Object *s = NULL;

    s = object_create(5);

    PRINT_TEST_RESULT(object_set_movable(s, FALSE) == OK);

    object_destroy(s);
}

void test2_object_set_movable()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_set_movable(s, FALSE) == ERROR);
}

void test1_object_get_movable()
{
    Object *s = NULL;

    s = object_create(5);

    object_set_movable(s, TRUE);

    PRINT_TEST_RESULT(object_get_movable(s) == TRUE);

    object_destroy(s);
}

void test2_object_get_movable()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_get_movable(s) == FALSE);
}

void test1_object_set_dependency()
{
    Object *s = NULL;

    s = object_create(7);

    PRINT_TEST_RESULT(object_set_dependency(s, 8) == OK);

    object_destroy(s);
}

void test2_object_set_dependency()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_set_dependency(s, 9) == ERROR);
}

void test1_object_get_dependency()
{
    Object *s = NULL;

    s = object_create(7);

    object_set_dependency(s, 5);

    PRINT_TEST_RESULT(object_get_dependency(s) == 5);

    object_destroy(s);
}

void test2_object_get_dependency()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_get_dependency(s) == NO_ID);
}

void test1_object_set_open()
{
    Object *s = NULL;

    s = object_create(4);

    PRINT_TEST_RESULT(object_set_open(s, 6) == OK);

    object_destroy(s);
}

void test2_object_set_open()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_set_open(s, 1) == ERROR);
}

void test1_object_get_open()
{
    Object *s = NULL;

    s = object_create(2);

    object_set_open(s, 9);

    PRINT_TEST_RESULT(object_get_open(s) == 9);

    object_destroy(s);
}

void test2_object_get_open()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_get_open(s) == NO_ID);
}

void test1_object_set_illuminate()
{
    Object *s = NULL;

    s = object_create(3);

    PRINT_TEST_RESULT(object_set_illuminate(s, FALSE) == OK);

    object_destroy(s);
}

void test2_object_set_illuminate()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_set_illuminate(s, TRUE) == ERROR);
}

void test1_object_get_illuminate()
{
    Object *s = NULL;

    s = object_create(10);

    PRINT_TEST_RESULT(object_get_illuminate(s) == FALSE);

    object_destroy(s);
}

void test2_object_get_illuminate()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_get_illuminate(s) == FALSE);
}

void test1_object_set_turnedon()
{
    Object *s = NULL;

    s = object_create(69);

    PRINT_TEST_RESULT(object_set_turnedon(s, TRUE) == OK);

    object_destroy(s);
}

void test2_object_set_turnedon()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_set_turnedon(s, TRUE) == ERROR);
}

void test1_object_get_turnedon()
{
    Object *s = NULL;

    s = object_create(96);

    PRINT_TEST_RESULT(object_get_turnedon(s) == TRUE);

    object_destroy(s);
}

void test2_object_get_turnedon()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_get_turnedon(s) == FALSE);
}

void test1_object_print()
{
    Object *s = NULL;

    s = object_create(38);

    PRINT_TEST_RESULT(object_print(s) == OK);

    object_destroy(s);
}

void test2_object_print()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_print(s) == ERROR);
}

void test1_object_destroy()
{
    Object *s = NULL;

    s = object_create(777);

    PRINT_TEST_RESULT(object_destroy(s) == OK);

    object_destroy(s);
}

void test2_object_destroy()
{
    Object *s = NULL;

    PRINT_TEST_RESULT(object_destroy(s) == ERROR);
}
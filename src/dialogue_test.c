/**
 * @brief It tests space module
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
#include "dialogue.h"
#include "dialogue_test.h"
#include "test.h"

#define MAX_TESTS 18 /*!< Total number of tests*/

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
        printf("Running all test for module Dialogue:\n");
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
        test1_dialogue_create();
    if (all || test == 2)
        test2_dialogue_create();
    if (all || test == 3)
        test1_dialogue_get_cmd();
    if (all || test == 4)
        test2_dialogue_get_cmd();
    if (all || test == 5)
        test1_dialogue_set_cmd();
    if (all || test == 6)
        test2_dialogue_set_cmd();
    if (all || test == 7)
        test1_dialogue_get_str();
    if (all || test == 8)
        test2_dialogue_get_str();
    if (all || test == 9)
        test1_dialogue_set_str();
    if (all || test == 10)
        test2_dialogue_set_str();
    if (all || test == 11)
        test1_dialogue_get_reps();
    if (all || test == 12)
        test2_dialogue_get_reps();
    if (all || test == 13)
        test1_dialogue_set_reps();
    if (all || test == 14)
        test2_dialogue_set_reps();
    if (all || test == 15)
        test1_dialogue_get_status();
    if (all || test == 16)
        test2_dialogue_get_status();
    if (all || test == 17)
        test1_dialogue_set_status();
    if (all || test == 18)
        test2_dialogue_set_status();

    PRINT_PASSED_PERCENTAGE;

    return __test_passed == __test_counter ? 0 : 1;
}

void test1_dialogue_create(){

    Dialogue *d = NULL;

    d = dialogue_create();

    PRINT_TEST_RESULT(d != NULL);

    dialogue_destroy(d);
}

void test2_dialogue_create(){

    Dialogue *d = NULL;

    PRINT_TEST_RESULT(d == NULL);
}

void test1_dialogue_get_cmd(){

    Dialogue *d = NULL;

    d = dialogue_create();

    dialogue_set_cmd(d, ATTACK);

    PRINT_TEST_RESULT(dialogue_get_cmd(d) == ATTACK);

    dialogue_destroy(d);
}

void test2_dialogue_get_cmd(){

    Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_get_cmd(d) == NO_CMD);
}

void test1_dialogue_set_cmd(){

    Dialogue *d = NULL;

    d = dialogue_create();

    PRINT_TEST_RESULT(dialogue_set_cmd(d, ATTACK) == OK);

    dialogue_destroy(d);
}

void test2_dialogue_set_cmd(){

    Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_set_cmd(d, ATTACK) == ERROR);
}

void test1_dialogue_get_str(){

    Dialogue *d = NULL;

    d = dialogue_create();

    dialogue_set_str(d, "Álvaro del Val Latorre");

    PRINT_TEST_RESULT(strcmp(dialogue_get_str(d), "Álvaro del Val Latorre") == 0);

    dialogue_destroy(d);
}

void test2_dialogue_get_str(){

    Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_get_str(d) == NULL);
}

void test1_dialogue_set_str(){

    Dialogue *d = NULL;

    d = dialogue_create();

    PRINT_TEST_RESULT(dialogue_set_str(d, "Antonio") == OK);

    dialogue_destroy(d);
}

void test2_dialogue_set_str(){

    Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_set_str(d, "Antonio") == ERROR);
}

void test1_dialogue_get_reps(){

    Dialogue *d = NULL;

    d = dialogue_create();

    dialogue_set_reps(d, 9);

    PRINT_TEST_RESULT(dialogue_get_reps(d) == 9);

    dialogue_destroy(d);
}

void test2_dialogue_get_reps(){

    Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_get_reps(d) == ERROR);
}

void test1_dialogue_set_reps(){

    Dialogue *d = NULL;

    d = dialogue_create();

    PRINT_TEST_RESULT(dialogue_set_reps(d, 8) == OK);

    dialogue_destroy(d);
}

void test2_dialogue_set_reps(){

    Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_set_reps(d, 10) == ERROR);
}

void test1_dialogue_get_status(){

    Dialogue *d = NULL;

    d = dialogue_create();

    dialogue_set_status(d, OK);

    PRINT_TEST_RESULT(dialogue_get_status(d) == OK);

    dialogue_destroy(d);
}

void test2_dialogue_get_status(){

    Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_get_status(d) == ERROR);
}

void test1_dialogue_set_status(){

    Dialogue *d = NULL;

    d = dialogue_create();

    PRINT_TEST_RESULT(dialogue_set_status(d, OK) == OK);

    dialogue_destroy(d);
}

void test2_dialogue_set_status(){

    Dialogue *d = NULL;

    PRINT_TEST_RESULT(dialogue_set_status(d, OK) == ERROR);
}
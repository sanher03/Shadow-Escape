/**
 * @brief It tests command module
 *
 * @file command_test.c
 * @author Ignacio Sánchez
 * @version 3.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "command_test.h"
#include "test.h"

#define MAX_TESTS 25 /*!< Total number of tests*/

/**
 * @brief Main function for COMMAND unit tests.
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
        printf("Running all test for module Command:\n");
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
        test1_command_create();
    if (all || test == 2)
        test1_command_get_cmd();
    if (all || test == 3)
        test2_command_get_cmd();
    if (all || test == 4)
        test1_command_get_name();
    if (all || test == 5)
        test2_command_get_name();
    if (all || test == 6)
        test1_command_set_name();
    if (all || test == 7)
        test2_command_set_name();
    if (all || test == 8)
        test1_command_get_status();
    if (all || test == 9)
        test2_command_get_status();
    if (all || test == 10)
        test1_command_set_status();
    if (all || test == 11)
        test2_command_set_status();
    if (all || test == 12)
        test1_command_set_cmd();
    if (all || test == 13)
        test2_command_set_cmd();
    if (all || test == 14)
        test1_command_get_last_cmd();
    if (all || test == 15)
        test2_command_get_last_cmd();
    if (all || test == 16)
        test1_command_set_last_cmd();
    if (all || test == 17)
        test2_command_set_last_cmd();
    if (all || test == 18)
        test1_command_get_reps();
    if (all || test == 19)
        test2_command_get_reps();
    if (all || test == 20)
        test1_command_set_reps();
    if (all || test == 21)
        test2_command_set_reps();
    if (all || test == 22)
        test1_command_get_link();
    if (all || test == 23)
        test2_command_get_link();
    if (all || test == 24)
        test1_command_set_link();
    if (all || test == 25)
        test2_command_set_link();

    PRINT_PASSED_PERCENTAGE;

    return __test_passed == __test_counter ? 0 : 1;
}

/**
 * First enemy_create test
 */
void test1_command_create()
{
    int result;
    Command *c;
    c = command_create();
    result = c != NULL;
    PRINT_TEST_RESULT(result);
    command_destroy(c);
}

/**
 * First command cmd getter test
 */
void test1_command_get_cmd()
{
    Command *c;
    c = command_create();
    PRINT_TEST_RESULT(command_get_cmd(c) == NO_CMD);
    command_destroy(c);
}

/**
 * Second command cmd getter test
 */
void test2_command_get_cmd()
{
    Command *c = NULL;
    PRINT_TEST_RESULT(command_get_cmd(c) == NO_CMD);
}

/**
 * First command name getter test
 */
void test1_command_get_name()
{
    Command *c;
    c = command_create();
    PRINT_TEST_RESULT(strcmp(command_get_name(c), "\0") == 0);
    command_destroy(c);
}

/**
 * Second command name getter test
 */
void test2_command_get_name()
{
    Command *c = NULL;
    PRINT_TEST_RESULT(command_get_name(c) == NULL);
}

/**
 * First command name setter test
 */
void test1_command_set_name()
{
    Command *c;
    c = command_create();
    command_set_name(c, "test2");
    PRINT_TEST_RESULT(strcmp(command_get_name(c), "test2") == 0);
    command_destroy(c);
}

/**
 * Second command name setter test
 */
void test2_command_set_name()
{
    Command *c = NULL;
    PRINT_TEST_RESULT(command_set_name(c, "test2") == ERROR);
}

/**
 * First command status getter test
 */
void test1_command_get_status()
{
    Command *c = NULL;
    c = command_create();
    PRINT_TEST_RESULT(command_get_status(c) == ERROR);
    command_destroy(c);
}

/**
 * Second command status getter test
 */
void test2_command_get_status()
{
    Command *c = NULL;
    PRINT_TEST_RESULT(command_get_status(c) == ERROR);
}

/**
 * First command status setter test
 */
void test1_command_set_status()
{
    Command *c = NULL;
    c = command_create();
    PRINT_TEST_RESULT(command_set_status(c, OK) == OK);
    command_destroy(c);
}

/**
 * Second command status setter test
 */
void test2_command_set_status()
{
    Command *c = NULL;
    PRINT_TEST_RESULT(command_set_status(c, OK) == ERROR);
}

/**
 * First command cmd setter test
 */
void test1_command_set_cmd()
{
    Command *c = NULL;
    c = command_create();
    command_set_cmd(c, UNKNOWN);
    PRINT_TEST_RESULT(command_get_cmd(c) == UNKNOWN);
    command_destroy(c);
}

/**
 * Second command cmd setter test
 */
void test2_command_set_cmd()
{
    Command *c = NULL;
    PRINT_TEST_RESULT(command_set_cmd(c, MOVE) == ERROR);
}

void test1_command_get_last_cmd(){

    Command *c = NULL;

    c = command_create();

    command_set_last_cmd(c, ATTACK);

    PRINT_TEST_RESULT(command_get_last_cmd(c) == ATTACK);
    command_destroy(c);
}

void test2_command_get_last_cmd(){

    Command *c = NULL;

    PRINT_TEST_RESULT(command_get_last_cmd(c) == NO_CMD);
}

void test1_command_set_last_cmd(){

    Command *c = NULL;

    c = command_create();

    PRINT_TEST_RESULT(command_set_last_cmd(c, ATTACK) == OK);
    command_destroy(c);
}

void test2_command_set_last_cmd(){

    Command *c = NULL;

    PRINT_TEST_RESULT(command_set_last_cmd(c, ATTACK) == ERROR);
}

void test1_command_get_reps(){

    Command *c = NULL;

    c = command_create();

    command_set_reps(c, 5);

    PRINT_TEST_RESULT(command_get_reps(c) == 5);
    command_destroy(c);
}

void test2_command_get_reps(){

    Command *c = NULL;

    PRINT_TEST_RESULT(command_get_reps(c) == ERROR);
}

void test1_command_set_reps(){

    Command *c = NULL;

    c = command_create();

    PRINT_TEST_RESULT(command_set_reps(c, 5) == OK);
    command_destroy(c);
}

void test2_command_set_reps(){

    Command *c = NULL;

    PRINT_TEST_RESULT(command_set_reps(c, 9) == ERROR);
}

void test1_command_get_link(){

    Command *c = NULL;

    c = command_create();

    command_set_link(c, "Beyond");

    PRINT_TEST_RESULT(strcmp(command_get_link(c), "Beyond") == 0);
    command_destroy(c);
}

void test2_command_get_link(){

    Command *c = NULL;

    PRINT_TEST_RESULT(command_get_link(c) == NULL);
}

void test1_command_set_link(){

    Command *c = NULL;

    c = command_create();

    PRINT_TEST_RESULT(command_set_link(c, "Nowhere") == OK);
    command_destroy(c);
}

void test2_command_set_link(){

    Command *c = NULL;

    PRINT_TEST_RESULT(command_set_link(c, "Anytime") == ERROR);
}
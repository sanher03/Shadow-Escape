/**
 * @brief It declares the tests for the command module
 *
 * @file command_test.h
 * @author Ignacio Sánchez
 * @version 2.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#ifndef COMMAND_TEST_H
#define COMMAND_TEST_H

/**
 * @test Test game creation
 * @post Non NULL pointer to command
 */
void test1_command_create();

/**
 * @test Test command cmd getter
 * @pre command created
 * @post Command CMD == NO_CMD
 */
void test1_command_get_cmd();

/**
 * @test Test command cmd getter
 * @pre NULL pointer to a command
 * @post Command CMD == NO_CMD
 */
void test2_command_get_cmd();

/**
 * @test Test command name getter
 * @pre command created
 * @post Command name == "\0"
 */
void test1_command_get_name();

/**
 * @test Test command name getter
 * @pre NULL pointer to a command
 * @post Command name == NULL
 */
void test2_command_get_name();

/**
 * @test Test command name setter
 * @pre command created
 * @post Command name setting == OK
 */
void test1_command_set_name();

/**
 * @test Test command name setter
 * @pre NULL pointer to a command
 * @post Command name setting == ERROR
 */
void test2_command_set_name();

/**
 * @test Test command status getter
 * @pre command created
 * @post Command status == ERROR
 */
void test1_command_get_status();

/**
 * @test Test command name setter
 * @pre NULL pointer to a command
 * @post Command status == ERROR
 */
void test2_command_get_status();

/**
 * @test Test command status setter
 * @pre command created
 * @post Command status setting == OK
 */
void test1_command_set_status();

/**
 * @test Test command status setter
 * @pre NULL pointer to a command
 * @post Command status setting == ERROR
 */
void test2_command_set_status();

/**
 * @test Test command cmd setter
 * @pre command created
 * @post Command cmd setting == UNKNOWN
 */
void test1_command_set_cmd();

/**
 * @test Test command status setter
 * @pre NULL pointer to a command
 * @post Command cmd setting == ERROR
 */
void test2_command_set_cmd();

void test1_command_get_last_cmd();

void test2_command_get_last_cmd();

void test1_command_set_last_cmd();

void test2_command_set_last_cmd();

void test1_command_get_reps();

void test2_command_get_reps();

void test1_command_set_reps();

void test2_command_set_reps();

void test1_command_get_link();

void test2_command_get_link();

void test1_command_set_link();

void test2_command_set_link();

#endif
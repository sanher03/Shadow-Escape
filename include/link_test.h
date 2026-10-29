/**
 * @brief It declares the tests for the link module
 *
 * @file link_test.h
 * @author Fabio Desio
 * @version 2.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H

/**
 * @test Test link creation
 * @pre Link ID
 * @post Non NULL pointer to link
 */
void test1_link_create();

/**
 * @test Test link creation
 * @pre Link ID
 * @post Link_ID == Supplied Link Id
 */
void test2_link_create();

/**
 * @test Test link id getter
 * @pre Link ID
 * @post Link_ID == Supplied Link Id
 */
void test1_link_get_id();

/**
 * @test Test link id getter
 * @pre NULL Link
 * @post Link_ID == NO_ID
 */
void test2_link_get_id();

/**
 * @test Test link name setter
 * @pre Link ID, Name
 * @post STATUS == OK
 */
void test1_link_set_name();

/**
 * @test Test link name setter
 * @pre NULL Link
 * @post STATUS == ERROR
 */
void test2_link_set_name();

/**
 * @test Test link name getter
 * @pre Link ID, Name
 * @post STATUS == OK
 */
void test1_link_get_name();

/**
 * @test Test link name getter
 * @pre NULL Link
 * @post STATUS == ERROR
 */
void test2_link_get_name();

/**
 * @test Test origin link getter
 * @pre Link ID, Origin Link ID
 * @post Origin = Origin Link ID
 */
void test1_link_get_origin();

/**
 * @test Test origin link getter
 * @pre Link ID, Origin Link ID
 * @post Origin Link ID = NO_ID
 */
void test2_link_get_origin();

/**
 * @test Test Origin link setter
 * @pre Link ID, Origin Link ID
 * @post Set == OK
 */
void test1_link_set_origin();

/**
 * @test Test Origin link setter
 * @pre Link ID, Origin Link ID
 * @post Set == ERROR
 */
void test2_link_set_origin();

/**
 * @test Test Destination link getter
 * @pre Link ID, Destination Link ID
 * @post Destination = Destination Link ID
 */
void test1_link_get_destination();

/**
 * @test Test Destination link getter
 * @pre Link ID, Destination Link ID
 * @post Destination Link ID = NO_ID
 */
void test2_link_get_destination();

/**
 * @test Test Destination link setter
 * @pre Link ID, Destination Link ID
 * @post Set == OK
 */
void test1_link_set_destination();

/**
 * @test Test Destination link setter
 * @pre Link ID, Destination Link ID
 * @post Set == ERROR
 */
void test2_link_set_destination();

/**
 * @test Test Direction link getter
 * @pre Link ID, Direction Link DIRECTION
 * @post Direction = Direction Link DIRECTION
 */
void test1_link_get_direction();

/**
 * @test Test Direction link getter
 * @pre Link ID, Direction Link DIRECTION
 * @post Direction Link ID = NORTH
 */
void test2_link_get_direction();

/**
 * @test Test Direction link setter
 * @pre Link ID, Direction Link DIRECTION
 * @post Set == OK
 */
void test1_link_set_direction();

/**
 * @test Test Direction link setter
 * @pre Link ID, Direction Link DIRECTION
 * @post Set == ERROR
 */
void test2_link_set_direction();

/**
 * @test Test Status link getter
 * @pre Link ID, Status Link STATUS
 * @post Status = Status Link STATUS
 */
void test1_link_get_status();

/**
 * @test Test Status link getter
 * @pre Link ID, Status Link STATUS
 * @post Status Link STATUS = ERROR
 */
void test2_link_get_status();

/**
 * @test Test Status link setter
 * @pre Link ID, Status Link STATUS
 * @post Set == OK
 */
void test1_link_set_status();

/**
 * @test Test Status link setter
 * @pre Link ID, Status Link STATUS
 * @post Set == ERROR
 */
void test2_link_set_status();

#endif
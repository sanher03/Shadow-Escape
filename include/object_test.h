/**
 * @brief It declares the tests for the object module
 *
 * @file object_test.h
 * @author Álvaro de Santos
 * @version 2.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H

/**
 * @test Test object creation
 * @pre Object ID
 * @post Non NULL pointer to object
 */
void test1_object_create();

/**
 * @test Test object creation
 * @pre Object ID
 * @post Object_ID == Supplied Object Id
 */
void test2_object_create();

/**
 * @test Test object id getter
 * @pre Object ID
 * @post Object_ID == Supplied Object Id
 */
void test1_object_get_id();

/**
 * @test Test object id getter
 * @pre NULL Object
 * @post Object_ID == NO_ID
 */
void test2_object_get_id();

/**
 * @test Test object name setter
 * @pre Object ID, Name
 * @post STATUS == OK
 */
void test1_object_set_name();

/**
 * @test Test object name setter
 * @pre NULL Object
 * @post STATUS == ERROR
 */
void test2_object_set_name();

/**
 * @test Test object name getter
 * @pre Object ID, Name
 * @post STATUS == OK
 */
void test1_object_get_name();

/**
 * @test Test object name getter
 * @pre NULL Object
 * @post STATUS == ERROR
 */
void test2_object_get_name();

/**
 * @test Test object description setter
 * @pre Object ID, description
 * @post STATUS == OK
 */
void test1_object_set_description();

/**
 * @test Test object description setter
 * @pre NULL Object
 * @post STATUS == ERROR
 */
void test2_object_set_description();

/**
 * @test Test object description getter
 * @pre Object ID, description
 * @post STATUS == OK
 */
void test1_object_get_description();

/**
 * @test Test object description getter
 * @pre NULL Object
 * @post STATUS == ERROR
 */
void test2_object_get_description();

void test1_object_set_hidden();

void test2_object_set_hidden();

void test1_object_get_hidden();

void test2_object_get_hidden();

void test1_object_set_movable();

void test2_object_set_movable();

void test1_object_get_movable();

void test2_object_get_movable();

void test1_object_set_dependency();

void test2_object_set_dependency();

void test1_object_get_dependency();

void test2_object_get_dependency();

void test1_object_set_open();

void test2_object_set_open();

void test1_object_get_open();

void test2_object_get_open();

void test1_object_set_illuminate();

void test2_object_set_illuminate();

void test1_object_get_illuminate();

void test2_object_get_illuminate();

void test1_object_set_turnedon();

void test2_object_set_turnedon();

void test1_object_get_turnedon();

void test2_object_get_turnedon();

void test1_object_print();

void test2_object_print();

void test1_object_destroy();

void test2_object_destroy();

#endif
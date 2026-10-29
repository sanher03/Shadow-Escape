/**
 * @brief It declares the tests for the enemy module
 *
 * @file enemy_test.h
 * @author Fabio Desio
 * @version 2.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#ifndef ENEMY_TEST_H
#define ENEMY_TEST_H

/**
 * @test Test enemy creation
 * @pre enemy ID
 * @post Non NULL pointer to enemy
 */
void test1_enemy_create();

/**
 * @test Test enemy creation
 * @pre enemy ID
 * @post enemy_ID == Supplied enemy Id
 */
void test2_enemy_create();

/**
 * @test Test enemy id getter
 * @pre Enemy ID
 * @post OK
 */
void test1_enemy_get_id();

/**
 * @test Test enemy id getter
 * @pre Enemy ID
 * @post ERROR
 */
void test2_enemy_get_id();

/**
 * @test Test name enemy setter
 * @pre enemy ID
 * @post Set == OK
 */
void test1_enemy_set_name();

/**
 * @test Test East enemy setter
 * @pre enemy ID
 * @post Set == ERROR
 */
void test2_enemy_set_name();

/**
 * @test Test East enemy getter
 * @pre enemy ID
 * @post GET == OK
 */
void test1_enemy_get_name();

/**
 * @test Test name enemy getter
 * @pre enemy ID, East enemy ID
 * @post GET == ERROR
 */
void test2_enemy_get_name();

/**
 * @test Test health enemy setter
 * @pre enemy ID
 * @post Set == OK
 */
void test1_enemy_set_health();

/**
 * @test Test health enemy setter
 * @pre enemy ID
 * @post Set == ERROR
 */
void test2_enemy_set_health();

/**
 * @test Test health enemy getter
 * @pre enemy ID
 * @post Get == OK
 */
void test1_enemy_get_health();

/**
 * @test Test health enemy getter
 * @pre enemy ID
 * @post Get == ERROR
 */
void test2_enemy_get_health();

/**
 * @test Test location enemy setter
 * @pre enemy ID
 * @post Set == OK
 */
void test1_enemy_set_location();

/**
 * @test Test location enemy setter
 * @pre enemy ID
 * @post Set == ERROR
 */
void test2_enemy_set_location();

/**
 * @test Test location enemy getter
 * @pre enemy ID
 * @post Get == OK
 */
void test1_enemy_get_location();

/**
 * @test Test location enemy getter
 * @pre enemy ID
 * @post Get == ERROR
 */
void test2_enemy_get_location();

#endif
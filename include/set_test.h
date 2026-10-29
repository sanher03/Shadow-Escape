/**
 * @brief It declares the tests for the set  module
 *
 * @file set_test.h
 * @author Fabio Desio
 * @version 2.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

/**
 * @test Test set creation
 * @pre set ID
 * @post Non NULL pointer to set
 */
void test1_set_create();

/**
 * @test Test Set creation
 * @pre Set ID
 * @post Set_ID == Supplied Set Id
 */
void test2_set_create();

/**
 * @test Test set add
 * @pre Set
 * @post ADD == OK
 */
void test1_set_add();

/**
 * @test Test set add
 * @pre Set
 * @post ADD == ERROR
 */
void test2_set_add();

/**
 * @test Test set deletion
 * @pre Set
 * @post DELETE == OK
 */
void test1_set_del();

/**
 * @test Test set deletion
 * @pre Set
 * @post DELETE == ERROR
 */
void test2_set_del();

/**
 * @test Test set get pos from id
 * @pre Set
 * @post Add two, check position
 */
void test1_set_get_id_pos();

/**
 * @test Test set get pos from id
 * @pre Set
 * @post Force error
 */
void test2_set_get_id_pos();

/**
 * @test Test n_ids getter
 * @pre Set
 * @post OK
 */
void test1_set_get_n_ids();

/**
 * @test Test n_ids getter
 * @pre Set
 * @post Force error
 */
void test2_set_get_n_ids();

/**
 * @test Test set get id from pos
 * @pre Set
 * @post Add two, check position
 */
void test1_set_get_pos_id();

/**
 * @test Test set get id from pos
 * @pre Set
 * @post Force error
 */
void test2_set_get_pos_id();

#endif
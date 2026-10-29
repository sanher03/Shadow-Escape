/**
 * @brief It declares the tests for the space module
 *
 * @file space_test.h
 * @author Fabio Desio
 * @version 2.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test Test space creation
 * @pre Space ID
 * @post Non NULL pointer to space
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test space id getter
 * @pre Space ID
 * @post Space_ID == Supplied Space Id
 */
void test1_space_get_id();

/**
 * @test Test space id getter
 * @pre NULL Space
 * @post Space_ID == NO_ID
 */
void test2_space_get_id();

/**
 * @test Test space name setter
 * @pre Space ID, Name
 * @post STATUS == OK
 */
void test1_space_set_name();

/**
 * @test Test space name setter
 * @pre NULL Space
 * @post STATUS == ERROR
 */
void test2_space_set_name();

/**
 * @test Test space name getter
 * @pre Space ID, Name
 * @post STATUS == OK
 */
void test1_space_get_name();

/**
 * @test Test space name getter
 * @pre NULL Space
 * @post STATUS == ERROR
 */
void test2_space_get_name();

/**
 * @test Test space add object
 * @pre Space ID, Object ID
 * @post ADD == OK
 */
void test1_space_add_object();

/**
 * @test Test space add object
 * @pre Space ID, Object ID
 * @post ADD == ERROR
 */
void test2_space_add_object();

/**
 * @test Test space has object id
 * @pre Space ID, Object ID
 * @post TRUE
 */
void test1_space_has_object_id();

/**
 * @test Test space has object id
 * @pre Space ID, No obj ID
 * @post FALSE
 */
void test2_space_has_object_id();

/**
 * @test Test space remove object
 * @pre Space ID, Object ID
 * @post REMOVE == OK
 */
void test1_space_del_object();

/**
 * @test Test space remove object
 * @pre Space ID, No Object ID
 * @post REMOVE == ERROR
 */
void test2_space_del_object();

/**
 * @test Test space get num of objects
 * @pre Space ID
 * @post Add two objects, check n_objs == 2
 * */
void test1_space_get_num_obj();

/**
 * @test Test space get num of objects
 * @pre Space ID
 * @post n_objs == -1
 */
void test2_space_get_num_obj();

/**
 * @test Test space set description
 * @pre Space ID
 * @post check st == OK
 * */
void test1_space_set_description();

/**
 * @test Test space set description
 * @pre Space ID
 * @post Space is null pointer, check == ERROR 
 * */
void test2_space_set_description();

/**
 * @test Test space get description
 * @pre Space ID
 * @post strcmp, check == 0
 * */
void test1_space_get_description();

/**
 * @test Test space get description
 * @pre Space ID
 * @post Space is null pointer, check == ERROR
 * */
void test2_space_get_description();

/**
 * @test Test space get link from direction
 * @pre Space ID, DIRECTION
 * @post check return is NOT NULL
 * */
void test1_space_get_link_with_direction();

/**
 * @test Test space get link from direction
 * @pre Space ID, DIRECTION
 * @post space is a null pointer, check == ERROR
 * */
void test2_space_get_link_with_direction();

/**
 * @test Test space add link
 * @pre Space ID, Link ID
 * @post check correct addition
 * */
void test1_space_add_link();

/**
 * @test Test space add link
 * @pre Space ID, Link ID
 * @post check incorrect addition, two null pointers
 * */
void test2_space_add_link();

/**
 * @test Test space object set getter
 * @pre Space ID
 * @post check correct get
 * */
void test1_space_get_object_set();

/**
 * @test Test space object set getter
 * @pre Space ID
 * @post space is a null pointer, check == NULL
 * */
void test2_space_get_object_set();

/**
 * @test Test space gdesc getter
 * @pre Space ID
 * @post check correct get
 * */
void test1_space_get_gdesc();

/**
 * @test Test space gdesc getter
 * @pre Space ID
 * @post check incorrect get
 * */
void test2_space_get_gdesc();

/**
 * @test Test space gdesc setter
 * @pre Space ID
 * @post check correct set
 * */
void test1_space_set_gdesc();

/**
 * @test Test space gdesc setter
 * @pre Space ID
 * @post check incorrect set
 * */
void test2_space_set_gdesc();

/**
 * @test Test space gdesc creator
 * @pre Space ID
 * @post check incorrect gdesc
 * */
void test1_space_gdesc_create();

/**
 * @test Test space gdesc creator
 * @pre Space ID
 * @post check incorrect gdesc first string
 * */
void test2_space_gdesc_create();

void test1_space_get_light();

void test2_space_get_light();

void test1_space_set_light();

void test2_space_set_light();

void test1_space_set_det_descr();

void test2_space_set_det_descr();

void test1_space_get_det_descr();

void test2_space_get_det_descr();

void test1_space_get_link_with_name();

void test2_space_get_link_with_name();

#endif
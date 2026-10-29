/**
 * @brief It declares the tests for the PLAYER module
 *
 * @file player_test.h
 * @author Fabio Desio
 * @version 2.0
 * @date 06-04-2023
 * @copyright GNU Public License
 */

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

/**
 * @test Test player creation
 * @pre Player ID
 * @post Non NULL pointer to player
 */
void test1_player_create();

/**
 * @test Test player creation with correct ID assignment
 * @pre Player ID
 * @post Player ID matches input ID
 */
void test2_player_create();

/**
 * @test Test adding an object to a player
 * @pre Player and object IDs
 * @post Object ID added to player inventory
 */
void test1_player_add_object();

/**
 * @test Test adding an object to a non-existent player
 * @pre Non-existent player ID and object ID
 * @post ERROR returned
 */
void test2_player_add_object();

/**
 * @test Test deleting an object from a player
 * @pre Player and object IDs
 * @post Object ID removed from player inventory
 */
void test1_player_del_object();

/**
 * @test Test deleting an object from a non-existent player
 * @pre Non-existent player ID and object ID
 * @post ERROR returned
 */
void test2_player_del_object();

/**
 * @test Test player inventory getter
 * @pre Player ID
 * @post Non-NULL inventory pointer
 */
void test1_player_get_inventory();

/**
 * @test Test player inventory getter for non-existent player
 * @pre Non-existent player ID
 * @post NULL inventory pointer
 */
void test2_player_get_inventory();

/**
 * @test Test player ID getter
 * @pre Player ID
 * @post ID of the player
 */
void test1_player_get_id();

/**
 * @test Test player ID getter for non-existent player
 * @pre Non-existent player ID
 * @post NO_ID returned
 */
void test2_player_get_id();

/**
 * @test Test player name setter
 * @pre Player ID and name string
 * @post Player name set to input string
 */
void test1_player_set_name();

/**
 * @test Test player name setter for non-existent player
 * @pre Non-existent player ID and name string
 * @post ERROR returned
 */
void test2_player_set_name();

/**
 * @test Test player name getter
 * @pre Player ID and name string
 * @post Player name matches input string
 */
void test1_player_get_name();

/**
 * @test Test player name getter for non-existent player
 * @pre Non-existent player ID
 * @post NULL name pointer
 */
void test2_player_get_name();

/**
 * @test Test player health setter
 * @pre Player ID and health value
 * @post Player health set to input value
 */
void test1_player_set_health();

/**
 * @test Test player health setter for non-existent player
 * @pre Non-existent player ID and health value
 * @post ERROR returned
 */
void test2_player_set_health();

/**
 * @test Test player health getter
 * @pre Player ID and health value
 * @post Player health matches input value
 */
void test1_player_get_health();

/**
 * @test Test player health getter for non-existent player
 * @pre Non-existent player ID
 * @post -1 returned
 */
void test2_player_get_health();

/**
 * @test Test player location setter
 * @pre Player ID and location ID
 * @post Player location set to input value
 */
void test1_player_set_location();

/**
 * @test Test player location setter for non-existent player
 * @pre Non-existent player ID and location ID
 * @post ERROR returned
 */
void test2_player_set_location();

/**
 * @test Test player location getter
 * @pre Player ID and location ID
 * @post Player location matches input value
 */
void test1_player_get_location();

/**
 * @test Test player location getter
 * @pre Player ID and location ID
 * @post Player location does not match input value
 */
void test2_player_get_location();

/**
 * @test Test player get number of objects
 * @pre Player and objects already initialized
 * @post Number of objects held by player
 */
void test1_player_get_num_objects();

/**
 * @test Test player get number of objects with no objects held
 * @pre Player already initialized
 * @post Number of objects held by player is 0
 */
void test2_player_get_num_objects();

#endif
/**
 * @brief It declares the tests for the game_reader module
 *
 * @file game_management_test.h
 * @author Ignacio Sánchez
 * @version 2.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#ifndef GAME_MANAGEMENT_TEST_H
#define GAME_MANAGEMENT_TEST_H

/**
 * @test Test game_reader_load_spaces
 * @pre load spaces
 * @post Space with id 11 != NULL
 */
void test1_game_management_load_spaces();

/**
 * @test Test game_reader_load_spaces
 * @pre load spaces
 * @post Name of space with id 11 == Entry
 */
void test2_game_management_load_spaces();

/**
 * @test Test game_reader_load_objects
 * @pre load objects
 * @post Object with id 21 != NULL
 */
void test1_game_management_load_objects();

/**
 * @test Test game_reader_load_objects
 * @pre load objects
 * @post Id of object with name Grano == 21
 */
void test2_game_management_load_objects();

/**
 * @test Test game_reader_load_links
 * @pre load links
 * @post Connection to south from 11 == 121
 */
void test1_game_management_load_links();

/**
 * @test Test game_reader_load_links
 * @pre load links
 * @post Connection to east from 122 == 125
 */
void test2_game_management_load_links();

/**
 * @test Test game_reader_load_player
 * @pre load player
 * @post Player of the game != NULL
 */
void test1_game_management_load_player();

/**
 * @test Test game_reader_load_player
 * @pre load player
 * @post id of the player of the game == 1
 */
void test2_game_management_load_player();

/**
 * @test Test game_reader_load_enemy
 * @pre load enemy
 * @post enemy of the game != NULL
 */
void test1_game_management_load_enemy();

/**
 * @test Test game_reader_load_enemy
 * @pre load enemy
 * @post id of the enemy of the game == 2
 */
void test2_game_management_load_enemy();

void test1_game_management_save();

void test2_game_management_save();

void test1_game_management_load();

void test2_game_management_load();

void test1_game_management_load_dialogues();

void test2_game_management_load_dialogues();

#endif
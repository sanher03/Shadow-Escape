/**
 * @brief It declares the tests for the game module
 *
 * @file game_test.h
 * @author Ignacio Sánchez
 * @version 2.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#ifndef GAME_TEST_H
#define GAME_TEST_H

/**
 * @test Test game creation
 * @pre pointer to the game created
 * @post Non NULL pointer to game
 */
void test1_game_create();

/**
 * @test Test game creation
 * @pre pointer to the game created
 * @post pointer to game's player == NULL
 */
void test2_game_create();

/**
 * @test Test game creation from file
 * @pre pointer to the game created
 * @post Non NULL pointer to space with id 11
 */
void test1_game_create_from_file();

/**
 * @test Test game creation from file
 * @pre pointer to the game created
 * @post Id of the game's player == 1
 */
void test2_game_create_from_file();

/**
 * @test Test game's command getting
 * @pre pointer to the game created
 * @post Non NULL pointer to command
 */
void test1_game_get_cmd();

/**
 * @test Test game's command getting
 * @pre NULL pointer to game
 * @post NULL pointer to command
 */
void test2_game_get_cmd();

/**
 * @test Test game's enemy getting
 * @pre pointer to the game created
 * @post Non NULL pointer to enemy
 */
void test1_game_get_enemy();

/**
 * @test Test game's enemy getting
 * @pre NULL pointer to game
 * @post NULL pointer to enemy
 */
void test2_game_get_enemy();

/**
 * @test Test game's player getting
 * @pre pointer to the game created
 * @post Non NULL pointer to enemy
 */
void test1_game_get_player();

/**
 * @test Test game's player getting
 * @pre NULL pointer to game
 * @post NULL pointer to player
 */
void test2_game_get_player();

/**
 * @test Test game's get object with a determined name
 * @pre pointer to game created
 * @post id of the object named "Grano" == 21
 */
void test1_game_get_object_with_name();

/**
 * @test Test game's get object with a determined name
 * @pre NULL pointer to game
 * @post id of the object == NO_ID
 */
void test2_game_get_object_with_name();

/**
 * @test Test game's get space with a determined id
 * @pre pointer to game created
 * @post id of the space returned == 125
 */
void test1_game_get_space();

/**
 * @test Test game's get space with a determined id
 * @pre NULL pointer to game
 * @post id of the space returned == NO_ID
 */
void test2_game_get_space();

/**
 * @test Test game's get location of an object
 * @pre pointer to game created
 * @post location of object named "Grano" == 125
 */
void test1_game_get_object_location();

/**
 * @test Test game's get location of an object
 * @pre NULL pointer to game
 * @post id of the location returned == NO_ID
 */
void test2_game_get_object_location();

/**
 * @test Test game's updating if cmd is UNKNOWN
 * @pre pointer to the game created
 * @post return of the function == OK
 */
void test1_game_update_unknown();

/**
 * @test Test game's updating if cmd is EXIT
 * @pre pointer to the game created
 * @post return of the function == OK
 */
void test2_game_update_exit();

/**
 * @test Test game's updating if cmd is NEXT
 * @pre pointer to the game created
 * @post after update location of the player == 121
 */
void test3_game_update_next();

/**
 * @test Test game's updating if cmd is BACK
 * @pre pointer to the game created
 * @post after update location of the player == 11
 */
void test4_game_update_back();

/**
 * @test Test game's updating if cmd is RIGHT
 * @pre pointer to the game created
 * @post after update location of the player == 125
 */
void test5_game_update_right();

/**
 * @test Test game's updating if cmd is LEFT
 * @pre pointer to the game created
 * @post after update location of the player == 122
 */
void test6_game_update_left();

/**
 * @test Test game's updating if cmd is TAKE
 * @pre pointer to the game created and player's inventory is empty
 * @post after update inventory of the player must have object "Grano"
 */
void test7_game_update_take();

/**
 * @test Test game's updating if cmd is DROP
 * @pre pointer to the game created and player's inventory has "Grano"
 * @post after update inventory of the player must not have object "Grano"
 */
void test8_game_update_drop();

/**
 * @test Test game's updating if cmd is ATTACK
 * @pre pointer to the game created and player's and enemy's health set to 0
 * @post either the player or the enemy are dead
 */
void test9_game_update_attack();

/**
 * @test Test game's updating if cmd is MOVE
 * @pre pointer to the game created
 * @post after update location of the player == 121
 */
void test10_game_update_move();

/**
 * @test Test game's updating if cmd is MOVE
 * @pre pointer to the game created
 * @post after update location of the player == 125
 */
void test11_game_update_move();

/**
 * @test Test game's updating if cmd is INSPECT
 * @pre pointer to the game created and command's name is "s"
 * @post return of the function == OK
 */
void test12_game_update_inspect();

/**
 * @test Test game's updating if cmd is INSPECT
 * @pre pointer to the game created and command's name is "Grano"
 * @post return of the function == OK
 */
void test13_game_update_inspect();

/**
 * @test Test game's adding spaces
 * @pre pointer to the game created
 * @post space of the game with id 11 != NULL
 */
void test1_game_add_space();

/**
 * @test Test game's adding spaces
 * @pre NULL pointer to game
 * @post return of the function == ERROR
 */
void test2_game_add_space();

/**
 * @test Test game's adding objects
 * @pre pointer to the game created
 * @post object of the game with id 21 != NULL
 */
void test1_game_add_object();

/**
 * @test Test game's adding objects
 * @pre NULL pointer to game
 * @post return of the function == ERROR
 */
void test2_game_add_object();

/**
 * @test Test game's connection getting
 * @pre pointer to the game created
 * @post southern connection of space 11 == 121
 */
void test1_game_get_connection();

/**
 * @test Test game's connection getting
 * @pre NULL pointer to game
 * @post southern connection of space 11 == NO_ID
 */
void test2_game_get_connection();

/**
 * @test Test game's status of a connection getting
 * @pre pointer to the game created
 * @post southern connection of space 11 == OPENED
 */
void test1_game_get_connection_status();

/**
 * @test Test game's status of a connection getting
 * @pre NULL pointer to game
 * @post southern connection of space 11 == CLOSED
 */
void test2_game_get_connection_status();

/**
 * @test Test game's adding links
 * @pre pointer to the game created
 * @post southern connection of space 11 == NO_ID
 */
void test1_game_add_link();

/**
 * @test Test game's adding links
 * @pre NULL pointer to game
 * @post return of the function == ERROR
 */
void test2_game_add_link();

/**
 * @test Test game's adding player
 * @pre pointer to the game created
 * @post player of the game != NULL
 */
void test1_game_add_player();

/**
 * @test Test game's adding player
 * @pre NULL pointer to game
 * @post return of the function == ERROR
 */
void test2_game_add_player();

/**
 * @test Test game's adding enemy
 * @pre pointer to the game created
 * @post enemy of the game != NULL
 */
void test1_game_add_enemy();

/**
 * @test Test game's adding enemy
 * @pre NULL pointer to game
 * @post return of the function == ERROR
 */
void test2_game_add_enemy();

/**
 * @test Test game's getting of object ids in the map
 * @pre pointer to the game created
 * @post when loading game the array returned must contain all of the objects ids
 */
void test1_game_get_objects_ids_in_map();

/**
 * @test Test game's getting of object ids in the map
 * @pre NULL pointer to game
 * @post array returned == NULL
 */
void test2_game_get_objects_ids_in_map();

/**
 * @test Test game's getting of an object with an specified id
 * @pre pointer to the game created
 * @post id of the object returned == 21
 */
void test1_game_get_obj();

/**
 * @test Test game's getting of an object with an specified id
 * @pre NULL pointer to game
 * @post object returned == NULL
 */
void test2_game_get_obj();

/**
 * @test Test game's getting of string with the name of the object with an specified id
 * @pre pointer to the game created
 * @post comparison between string returned and "grano" == 0
 */
void test1_game_get_obj_name();

/**
 * @test Test game's getting of string with the name of the object with an specified id
 * @pre NULL pointer to game
 * @post string returned == NULL
 */
void test2_game_get_obj_name();

#endif
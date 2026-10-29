/**
 * @brief It tests game_reader module
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
#include "game_management.h"
#include "game.h"
#include "space.h"
#include "object.h"
#include "link.h"
#include "enemy.h"
#include "player.h"
#include "game_management_test.h"
#include "test.h"

#define MAX_TESTS 16 /*!< Total number of tests*/

/**
 * @brief Main function for GAME_READER unit tests.
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
        printf("Running all test for module Game_reader:\n");
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
        test1_game_management_load_spaces();
    if (all || test == 2)
        test2_game_management_load_spaces();
    if (all || test == 3)
        test1_game_management_load_objects();
    if (all || test == 4)
        test2_game_management_load_objects();
    if (all || test == 5)
        test1_game_management_load_links();
    if (all || test == 6)
        test2_game_management_load_links();
    if (all || test == 7)
        test1_game_management_load_player();
    if (all || test == 8)
        test2_game_management_load_player();
    if (all || test == 9)
        test1_game_management_load_enemy();
    if (all || test == 10)
        test2_game_management_load_enemy();
    if (all || test == 11)
        test1_game_management_save();
    if (all || test == 12)
        test2_game_management_save();
    if (all || test == 13)
        test1_game_management_load();
    if (all || test == 14)
        test2_game_management_load();
    if (all || test == 15)
        test1_game_management_load_dialogues();
    if (all || test == 16)
        test2_game_management_load_dialogues();

    PRINT_PASSED_PERCENTAGE;

    return __test_passed == __test_counter ? 0 : 1;
}

/**
 * First game_reader_load_spaces test
 */
void test1_game_management_load_spaces()
{
    int result;
    Game *g;
    Space *s;
    game_create(&g);
    game_management_load_spaces(g, "data/nuevo.dat");
    s = game_get_space(g, 10);
    result = s != NULL;
    PRINT_TEST_RESULT(result);
    game_destroy(g);
}

/**
 * Second game_reader_load_spaces test
 */
void test2_game_management_load_spaces()
{
    Game *g;
    Space *s;
    game_create(&g);
    game_management_load_spaces(g, "data/nuevo.dat");
    s = game_get_space(g, 11);
    PRINT_TEST_RESULT(strcmp(space_get_name(s), "Corridor") == 0);
    game_destroy(g);
}

/**
 * First game_reader_load_objects test
 */
void test1_game_management_load_objects()
{
    int result;
    Game *g;
    Object *o;
    game_create(&g);
    game_management_load_objects(g, "data/nuevo.dat");
    o = game_get_obj(g, 80);
    result = o != NULL;
    PRINT_TEST_RESULT(result);
    game_destroy(g);
}

/**
 * Second game_reader_load_objects test
 */
void test2_game_management_load_objects()
{
    Game *g;
    Id o;
    game_create(&g);
    game_management_load_objects(g, "data/nuevo.dat");
    o = game_get_object_with_name(g, "Backpack");
    PRINT_TEST_RESULT(o == 82);
    game_destroy(g);
}

/**
 * First game_reader_load_links test
 */
void test1_game_management_load_links()
{
    Game *g;
    Id id;
    game_create(&g);
    game_management_load_spaces(g, "data/nuevo.dat");
    game_management_load_links(g, "data/nuevo.dat");
    id = game_get_connection(g, 11, S);
    PRINT_TEST_RESULT(id == 10);
    game_destroy(g);
}

/**
 * Second game_reader_load_links test
 */
void test2_game_management_load_links()
{
    Game *g;
    Id id;
    game_create(&g);
    game_management_load_spaces(g, "data/nuevo.dat");
    game_management_load_links(g, "data/nuevo.dat");
    id = game_get_connection(g, 10, N);
    PRINT_TEST_RESULT(id == 11);
    game_destroy(g);
}

/**
 * First game_reader_load_player test
 */
void test1_game_management_load_player()
{
    int result;
    Game *g;
    Player *p;
    game_create(&g);
    game_management_load_player(g, "data/nuevo.dat");
    p = game_get_player(g);
    result = p != NULL;
    PRINT_TEST_RESULT(result);
    game_destroy(g);
}

/**
 * Second game_reader_load_player test
 */
void test2_game_management_load_player()
{
    Game *g;
    Player *p;
    Id id;
    game_create(&g);
    game_management_load_player(g, "data/nuevo.dat");
    p = game_get_player(g);
    id = player_get_id(p);
    PRINT_TEST_RESULT(id == 1);
    game_destroy(g);
}

/**
 * First game_reader_load_enemy test
 */
void test1_game_management_load_enemy()
{
    int result;
    Game *g;
    Enemy *e;
    game_create(&g);
    game_management_load_enemy(g, "data/nuevo.dat");
    e = game_get_enemy(g);
    result = e != NULL;
    PRINT_TEST_RESULT(result);
    game_destroy(g);
}

/**
 * Second game_reader_load_enemy test
 */
void test2_game_management_load_enemy()
{
    Game *g;
    Enemy *e;
    Id id;
    game_create(&g);
    game_management_load_enemy(g, "data/nuevo.dat");
    e = game_get_enemy(g);
    id = enemy_get_id(e);
    PRINT_TEST_RESULT(id == 2);
    game_destroy(g);
}

void test1_game_management_save()
{

    Game *game = NULL;

    game_create(&game);

    game_create_from_file(game, "data/nuevo.dat");

    PRINT_TEST_RESULT(game_management_save(game, "save.dat") == OK);
    game_destroy(game);
}

void test2_game_management_save()
{

    Game *game = NULL;

    game_create(&game);

    game_create_from_file(game, "data/nuevo.dat");

    PRINT_TEST_RESULT(game_management_save(game, "does_not_exist.dat") == OK);
    game_destroy(game);
}

void test1_game_management_load()
{

    Game *game = NULL;
    Command *cmd = NULL;

    game_create(&game);
    cmd = command_create();
    command_set_name(cmd, "Naranja");

    PRINT_TEST_RESULT(game_management_load(&game, cmd) == ERROR);
    command_destroy(cmd);
    game_destroy(game);
}

void test2_game_management_load()
{

    Game *game = NULL;
    Command *cmd = NULL;

    game_create(&game);

    PRINT_TEST_RESULT(game_management_load(&game, cmd) == ERROR);
    game_destroy(game);
}

void test1_game_management_load_dialogues()
{

    Game *game = NULL;

    game_create(&game);

    game_create_from_file(game, "data/nuevo.dat");

    PRINT_TEST_RESULT(game_management_load_dialogues(game, "data/nuevo.dat") == OK);
    game_destroy(game);
}

void test2_game_management_load_dialogues()
{

    Game *game = NULL;

    game_create(&game);

    game_create_from_file(game, "data/nuevo.dat");

    PRINT_TEST_RESULT(game_management_load_dialogues(game, "does_not_exist.dat") == OK);
    game_destroy(game);
}
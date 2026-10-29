/**
 * @brief It tests space module
 *
 * @file space_test.c
 * @author Fabio Desio
 * @version 3.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_rules_test.h"
#include "game_rules.h"
#include "game.h"
#include "link.h"
#include "object.h"
#include "inventory.h"
#include "player.h"
#include "enemy.h"
#include "space.h"
#include "test.h"

#define MAX_TESTS 13 /*!< Total number of tests*/

/**
 * @brief Main function for Gamerules unit tests.
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
        printf("Running all test for module Gamerules:\n");
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
        test1_rules_update();
    if (all || test == 2)
        test2_rules_update();
    if (all || test == 3)
        test1_rules_TOFF_SPACES();
    if (all || test == 4)
        test2_rules_TOFF_SPACES();
    if (all || test == 5)
        test1_rules_TAKE_FOOD();
    if (all || test == 6)
        test2_rules_TAKE_FOOD();
    if (all || test == 7)
        test1_rules_TAKE_POTION();
    if (all || test == 8)
        test1_rules_ADD_SHIELD();
    if (all || test == 9)
        test2_rules_ADD_SHIELD();
    if (all || test == 10)
        test1_rules_HPUP_ENEMY();
    if (all || test == 12)
        test1_rules_UP_INVENTORY();
    if (all || test == 13)
        test2_rules_UP_INVENTORY();

    PRINT_PASSED_PERCENTAGE;

    return __test_passed == __test_counter ? 0 : 1;
}

void test1_rules_update(){

    Game *g = NULL;
    int j;
    int n = 0;

    game_create(&g);

    game_create_from_file(g, "data/nuevo.dat");

    enemy_set_health(game_get_enemy(g), 0);

    game_rules_update(g);

    for (j = 0; j < MAX_LINKS; j++)
    {
        if(link_get_status(space_get_link_with_direction(game_get_space(g, enemy_get_location(game_get_enemy(g))), j)) == OPENED){
            n++;
        }
    }

    PRINT_TEST_RESULT(n == MAX_LINKS);
}

void test2_rules_update(){

    Game *g = NULL;
    int j;
    int n = 0;

    game_create(&g);

    game_create_from_file(g, "data/nuevo.dat");

    game_rules_update(g);

    for (j = 0; j < MAX_LINKS; j++)
    {
        if(link_get_status(space_get_link_with_direction(game_get_space(g, enemy_get_location(game_get_enemy(g))), j)) == CLOSED){
            n++;
        }
    }

    PRINT_TEST_RESULT(n != MAX_LINKS);
}

void test1_rules_TOFF_SPACES(){

    Game *g = NULL;
    int i;
    int n = 0;
    Space **spaces = NULL;

    game_create(&g);

    game_create_from_file(g, "data/nuevo.dat");

    game_rules_TOFF_SPACES(g);

    spaces = game_get_spaces(g);

    for (i = 0; spaces[i] != NULL; i++)
    {
        if(space_get_light(spaces[i]) == FALSE){
            n++;
        }
    }

    PRINT_TEST_RESULT(n == 21);
}

void test2_rules_TOFF_SPACES(){

    Game *g = NULL;
    int i;
    int n = 0;
    Space **spaces = NULL;

    game_create(&g);

    game_create_from_file(g, "data/nuevo.dat");

    game_rules_TOFF_SPACES(g);

    spaces = game_get_spaces(g);

    for (i = 0; spaces[i] != NULL; i++)
    {
        if(space_get_light(spaces[i]) == TRUE){
            n++;
        }

    }

    PRINT_TEST_RESULT(n != 21);

}

void test1_rules_TAKE_FOOD(){

    Game *game = NULL;

    int init_health = 0;
    int final_health = 0;

    game_create(&game);

    game_create_from_file(game, "data/nuevo.dat");

    player_set_health(game_get_player(game), 2);

    init_health = player_get_health(game_get_player(game));

    game_rules_TAKE_FOOD(game);

    final_health = player_get_health(game_get_player(game));

    PRINT_TEST_RESULT(init_health < final_health);
}

void test2_rules_TAKE_FOOD(){

    Game *game = NULL;
    int init_health = 0;
    int final_health = 0;

    game_create(&game);

    game_create_from_file(game, "data/nuevo.dat");

    player_set_health(game_get_player(game), MAX_PLAYER_HEALTH);

    init_health = player_get_health(game_get_player(game));

    game_rules_TAKE_FOOD(game);

    final_health = player_get_health(game_get_player(game));

    PRINT_TEST_RESULT(init_health == final_health);

}

void test1_rules_TAKE_POTION(){

    Game *game = NULL;
    int init_health = 0;
    int final_health = 0;

    game_create(&game);

    game_create_from_file(game, "data/nuevo.dat");

    init_health = player_get_health(game_get_player(game));

    game_rules_TAKE_POTION(game);

    final_health = player_get_health(game_get_player(game));

    PRINT_TEST_RESULT((init_health < final_health) || (init_health > final_health));
}

void test1_rules_ADD_SHIELD(){

    Game *game = NULL;
    int health = 0;

    game_create(&game);

    game_create_from_file(game, "data/nuevo.dat");

    player_set_health(game_get_player(game), MAX_PLAYER_HEALTH);

    game_rules_ADD_SHIELD(game);

    health = player_get_health(game_get_player(game));

    PRINT_TEST_RESULT(health > MAX_PLAYER_HEALTH);
}

void test2_rules_ADD_SHIELD(){

    Game *game = NULL;
    int init_health = 0;
    int final_health = 0;

    game_create(&game);

    game_create_from_file(game, "data/nuevo.dat");

    player_set_health(game_get_player(game), 1);

    init_health = player_get_health(game_get_player(game));

    game_rules_ADD_SHIELD(game);

    final_health = player_get_health(game_get_player(game));

    PRINT_TEST_RESULT(init_health == final_health);
}

void test1_rules_HPUP_ENEMY(){

    Game *game = NULL;
    int init_health = 0;
    int final_health = 0;

    game_create(&game);

    game_create_from_file(game, "data/nuevo.dat");

    init_health = enemy_get_health(game_get_enemy(game));

    game_rules_HPUP_ENEMY(game);

    final_health = enemy_get_health(game_get_enemy(game));

    PRINT_TEST_RESULT(init_health < final_health);
}

void test1_rules_UP_INVENTORY(){

    Game *game = NULL;
    int max_objs = 0;

    game_create(&game);

    game_create_from_file(game, "data/nuevo.dat");

    inventory_set_max_objs(player_get_inventory(game_get_player(game)),4);

    game_rules_UP_INVENTORY(game);

    max_objs = inventory_get_max_objs(player_get_inventory(game_get_player(game)));

    PRINT_TEST_RESULT(max_objs != MAX_INVENTORY_SIZE);
}

void test2_rules_UP_INVENTORY(){

    Game *game = NULL;
    int max_objs = 0;

    game_create(&game);

    game_create_from_file(game, "data/nuevo.dat");

    inventory_set_max_objs(player_get_inventory(game_get_player(game)),7);

    game_rules_UP_INVENTORY(game);

    max_objs = inventory_get_max_objs(player_get_inventory(game_get_player(game)));

    PRINT_TEST_RESULT(max_objs == MAX_INVENTORY_SIZE);
}
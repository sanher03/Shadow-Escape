/**
 * @brief It tests game module
 *
 * @file game_test.c
 * @author Ignacio Sánchez
 * @version 3.0
 * @date 12-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_test.h"
#include "test.h"

#define MAX_TESTS 45 /*!< Total number of tests*/

/**
 * @brief Main function for GAME unit tests.
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
        printf("Running all test for module Game:\n");
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
        test1_game_create();
    if (all || test == 2)
        test2_game_create();
    if (all || test == 3)
        test1_game_create_from_file();
    if (all || test == 4)
        test2_game_create_from_file();
    if (all || test == 5)
        test1_game_get_cmd();
    if (all || test == 6)
        test2_game_get_cmd();
    if (all || test == 7)
        test1_game_get_enemy();
    if (all || test == 8)
        test2_game_get_enemy();
    if (all || test == 9)
        test1_game_get_player();
    if (all || test == 10)
        test2_game_get_player();
    if (all || test == 11)
        test1_game_get_object_with_name();
    if (all || test == 12)
        test2_game_get_object_with_name();
    if (all || test == 13)
        test1_game_get_space();
    if (all || test == 14)
        test2_game_get_space();
    if (all || test == 15)
        test1_game_get_object_location();
    if (all || test == 16)
        test2_game_get_object_location();
    if (all || test == 17)
        test1_game_update_unknown();
    if (all || test == 18)
        test2_game_update_exit();
    if (all || test == 19)
        test7_game_update_take();
    if (all || test == 20)
        test8_game_update_drop();
    if (all || test == 21)
        test9_game_update_attack();
    if (all || test == 22)
        test10_game_update_move();
    if (all || test == 23)
        test11_game_update_move();
    if (all || test == 24)
        test12_game_update_inspect();
    if (all || test == 25)
        test13_game_update_inspect();
    if (all || test == 26)
        test1_game_add_space();
    if (all || test == 27)
        test2_game_add_space();
    if (all || test == 28)
        test1_game_add_object();
    if (all || test == 29)
        test2_game_add_object();
    if (all || test == 30)
        test1_game_get_connection();
    if (all || test == 31)
        test2_game_get_connection();
    if (all || test == 32)
        test1_game_get_connection_status();
    if (all || test == 33)
        test1_game_get_connection_status();
    if (all || test == 34)
        test1_game_add_link();
    if (all || test == 35)
        test2_game_add_link();
    if (all || test == 36)
        test1_game_add_player();
    if (all || test == 37)
        test2_game_add_player();
    if (all || test == 38)
        test1_game_add_enemy();
    if (all || test == 39)
        test2_game_add_enemy();
    if (all || test == 40)
        test1_game_get_objects_ids_in_map();
    if (all || test == 41)
        test2_game_get_objects_ids_in_map();
    if (all || test == 42)
        test1_game_get_obj();
    if (all || test == 43)
        test2_game_get_obj();
    if (all || test == 44)
        test1_game_get_obj_name();
    if (all || test == 45)
        test2_game_get_obj_name();

    PRINT_PASSED_PERCENTAGE;

    return __test_passed == __test_counter ? 0 : 1;
}

/**
 * First game_create test
 */
void test1_game_create()
{
    int result;
    Game *g;
    game_create(&g);
    result = g != NULL;
    PRINT_TEST_RESULT(result);
    game_destroy(g);
}

/**
 * Second game_create test
 */
void test2_game_create()
{
    int result;
    Game *g;
    Player *p;
    game_create(&g);
    p = game_get_player(g);
    result = p == NULL;
    PRINT_TEST_RESULT(result);
    game_destroy(g);
}

/**
 * First game_create_from_file test
 */
void test1_game_create_from_file()
{
    int result;
    Game *g;
    Space *s;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    s = game_get_space(g, 11);
    result = s != NULL;
    PRINT_TEST_RESULT(result);
    game_destroy(g);
}

/**
 * Second game_create_from_file test
 */
void test2_game_create_from_file()
{
    Game *g;
    Player *p;
    Id id;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    p = game_get_player(g);
    id = player_get_id(p);
    PRINT_TEST_RESULT(id == 1);
    game_destroy(g);
}

/**
 * First game_get_cmd test
 */
void test1_game_get_cmd()
{
    int result;
    Game *g;
    Command *c;
    game_create(&g);
    c = command_create();
    game_set_cmd(g,c);
    c = game_get_cmd(g);
    result = c != NULL;
    PRINT_TEST_RESULT(result);
    game_destroy(g);
    command_destroy(c);
}

/**
 * Second game_get_cmd test
 */
void test2_game_get_cmd()
{
    int result;
    Game *g = NULL;
    Command *c;
    c = game_get_cmd(g);
    result = c == NULL;
    PRINT_TEST_RESULT(result);
}

/**
 * First game_get_enemy test
 */
void test1_game_get_enemy()
{
    int result;
    Game *g;
    Enemy *e;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    e = game_get_enemy(g);
    result = e != NULL;
    PRINT_TEST_RESULT(result);
    game_destroy(g);
}

/**
 * Second game_get_enemy test
 */
void test2_game_get_enemy()
{
    int result;
    Game *g = NULL;
    Enemy *e;
    e = game_get_enemy(g);
    result = e == NULL;
    PRINT_TEST_RESULT(result);
}

/**
 * First game_get_player test
 */
void test1_game_get_player()
{
    int result;
    Game *g;
    Player *p;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    p = game_get_player(g);
    result = p != NULL;
    PRINT_TEST_RESULT(result);
    game_destroy(g);
}

/**
 * Second game_get_player test
 */
void test2_game_get_player()
{
    int result;
    Game *g = NULL;
    Player *p;
    p = game_get_player(g);
    result = p == NULL;
    PRINT_TEST_RESULT(result);
}

/**
 * First game_get_object_with_name test
 */
void test1_game_get_object_with_name()
{
    Game *g = NULL;
    Id id;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    id = game_get_object_with_name(g, "Pizza");
    PRINT_TEST_RESULT(id == 78);
    game_destroy(g);
}

/**
 * Second game_get_object_with_name test
 */
void test2_game_get_object_with_name()
{
    Game *g = NULL;
    Id id;
    id = game_get_object_with_name(g, "Grano");
    PRINT_TEST_RESULT(id == NO_ID);
}

/**
 * First game_get_space test
 */
void test1_game_get_space()
{
    Game *g = NULL;
    Id id;
    Space *s;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    s = game_get_space(g, 25);
    id = space_get_id(s);
    PRINT_TEST_RESULT(id == 25);
    game_destroy(g);
}

/**
 * Second game_get_space test
 */
void test2_game_get_space()
{
    Game *g = NULL;
    Space *s;
    s = game_get_space(g, 125);
    PRINT_TEST_RESULT(s == NULL);
}

/**
 * First game_get_object_location test
 */
void test1_game_get_object_location()
{
    Game *g = NULL;
    Id id;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    id = game_get_object_location(g, 71);
    PRINT_TEST_RESULT(id == 10);
    game_destroy(g);
}

/**
 * Second game_get_object_location test
 */
void test2_game_get_object_location()
{
    Game *g = NULL;
    Id id;
    id = game_get_object_location(g, 21);
    PRINT_TEST_RESULT(id == NO_ID);
}

/**
 * First game_update test
 */
void test1_game_update_unknown()
{
    Game *g = NULL;
    STATUS st;
    Command *c;
    FILE *f = NULL;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    c = command_create();
    game_set_cmd(g, c);
    command_set_cmd(c, UNKNOWN);
    st = game_update(&g, c, f);
    PRINT_TEST_RESULT(st == OK);
    game_destroy(g);
    command_destroy(c);
}

/**
 * Second game_update test
 */
void test2_game_update_exit()
{
    Game *g = NULL;
    STATUS st;
    Command *c;
    FILE *f = NULL;
    game_create(&g);
    c = command_create();
    game_create_from_file(g, "data/nuevo.dat");
    game_set_cmd(g, c);
    command_set_cmd(c, EXIT);
    st = game_update(&g, c, f);
    PRINT_TEST_RESULT(st == OK);
    game_destroy(g);
    command_destroy(c);
}

/**
 * seventh game_update test
 */
void test7_game_update_take()
{
    Game *g = NULL;
    Player *p;
    Command *c;
    Inventory *i;
    FILE *f = NULL;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    c = command_create();
    game_set_cmd(g, c);
    command_set_cmd(c, TAKE);
    command_set_name(c, "Knife");
    p = game_get_player(g);
    player_set_location(p, 15);
    game_update(&g, c, f);
    i = player_get_inventory(p);
    PRINT_TEST_RESULT(command_get_status(c) == OK && inventory_has_obj(i, 76) == TRUE);
    game_destroy(g);
    command_destroy(c);
}

/**
 * eigth game_update test
 */
void test8_game_update_drop()
{
    Game *g = NULL;
    Player *p;
    Command *c;
    Inventory *i;
    FILE *f = NULL;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    c = command_create();
    game_set_cmd(g, c);
    command_set_cmd(c, DROP);
    command_set_name(c, "Vitamins");
    p = game_get_player(g);
    player_add_object(p, 81);
    game_update(&g, c, f);
    i = player_get_inventory(p);
    PRINT_TEST_RESULT(command_get_status(c) == OK && inventory_has_obj(i, 81) == FALSE);
    game_destroy(g);
    command_destroy(c);
}

/**
 * nineth game_update test
 */
void test9_game_update_attack()
{
    Game *g = NULL;
    Player *p;
    Enemy *e;
    Command *c = NULL;
    FILE *f = NULL;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    c = command_create();
    game_set_cmd(g, c);
    command_set_cmd(c, ATTACK);
    p = game_get_player(g);
    e = game_get_enemy(g);
    player_set_location(p, 26);
    player_set_health(p, 1);
    enemy_set_health(e, 1);
    game_update(&g, c, f);
    PRINT_TEST_RESULT(command_get_status(c) == OK && (player_get_health(p) == 0 || enemy_get_health(e) == 0));
    game_destroy(g);
    command_destroy(c);
}

/**
 * tenth game_update test
 */
void test10_game_update_move()
{
    Game *g = NULL;
    Id id;
    Player *p;
    Command *c;
    FILE *f = NULL;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    c = command_create();
    game_set_cmd(g, c);
    command_set_cmd(c, MOVE);
    command_set_name(c, "n");
    p = game_get_player(g);
    game_update(&g, c, f);
    id = player_get_location(p);
    PRINT_TEST_RESULT(command_get_status(c) == OK && id == 11);
    game_destroy(g);
    command_destroy(c);
}

/**
 * eleventh game_update test
 */
void test11_game_update_move()
{
    Game *g = NULL;
    Player *p;
    Id id;
    Command *c;
    FILE *f = NULL;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    c = command_create();
    game_set_cmd(g, c);
    command_set_cmd(c, MOVE);
    command_set_name(c, "w");
    p = game_get_player(g);
    player_set_location(p, 24);
    game_update(&g, c, f);
    id = player_get_location(p);
    PRINT_TEST_RESULT(command_get_status(c) == OK && id == 23);
    game_destroy(g);
    command_destroy(c);
}

/**
 * twelfth game_update test
 */
void test12_game_update_inspect()
{
    Game *g = NULL;
    STATUS st;
    Command *c;
    FILE *f = NULL;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    c = command_create();
    game_set_cmd(g, c);
    command_set_cmd(c, INSPECT);
    command_set_name(c, "s");
    st = game_update(&g, c, f);
    PRINT_TEST_RESULT(st == OK);
    game_destroy(g);
    command_destroy(c);
}

/**
 * thirteenth game_update test
 */
void test13_game_update_inspect()
{
    Game *g = NULL;
    STATUS st;
    Command *c;
    Player *p;
    FILE *f = NULL;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    c = command_create();
    game_set_cmd(g, c);
    command_set_cmd(c, INSPECT);
    command_set_name(c, "Grano");
    p = game_get_player(g);
    player_add_object(p, 21);
    st = game_update(&g, c, f);
    PRINT_TEST_RESULT(st == OK);
    game_destroy(g);
    command_destroy(c);
}

/**
 * First game_add_space test
 */
void test1_game_add_space()
{
    Game *g = NULL;
    Space *s;
    game_create(&g);
    s = space_create(11);
    game_add_space(g, s);
    s = game_get_space(g, 11);
    PRINT_TEST_RESULT(s != NULL);
    game_destroy(g);
}

/**
 * Second game_add_space test
 */
void test2_game_add_space()
{
    Game *g = NULL;
    Space *s = NULL;
    PRINT_TEST_RESULT(game_add_space(g, s) == ERROR);
}

/**
 * First game_add_object test
 */
void test1_game_add_object()
{
    Game *g = NULL;
    Object *o;
    game_create(&g);
    o = object_create(11);
    game_add_object(g, o);
    o = game_get_obj(g, 11);
    PRINT_TEST_RESULT(o != NULL);
    game_destroy(g);
}

/**
 * Second game_add_object test
 */
void test2_game_add_object()
{
    Game *g = NULL;
    Object *o = NULL;
    PRINT_TEST_RESULT(game_add_object(g, o) == ERROR);
}

/**
 * First game_get_connection test
 */
void test1_game_get_connection()
{
    Game *g = NULL;
    Id id;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    id = game_get_connection(g, 19, D);
    PRINT_TEST_RESULT(id == 20);
    game_destroy(g);
}

/**
 * Second game_get_connection test
 */
void test2_game_get_connection()
{
    Game *g = NULL;
    Id id;
    id = game_get_connection(g, 11, S);
    PRINT_TEST_RESULT(id == NO_ID);
}

/**
 * First game_get_connection_status test
 */
void test1_game_get_connection_status()
{
    Game *g = NULL;
    LINKSTATUS st;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    st = game_get_connection_status(g, 11, S);
    PRINT_TEST_RESULT(st == OPENED);
    game_destroy(g);
}

/**
 * Second game_get_connection_status test
 */
void test2_game_get_connection_status()
{
    Game *g = NULL;
    LINKSTATUS st;
    st = game_get_connection_status(g, 11, S);
    PRINT_TEST_RESULT(st == CLOSED);
}

/**
 * First game_add_link test
 */
void test1_game_add_link()
{
    Game *g = NULL;
    Id id;
    Link *l;
    Space *s;
    game_create(&g);
    s = space_create(11);
    game_add_space(g, s);
    l = link_create(40);
    link_set_origin(l, 11);
    link_set_destination(l, 121);
    link_set_direction(l, S);
    game_add_link(g, l);
    id = game_get_connection(g, 11, S);
    PRINT_TEST_RESULT(id == 121);
    game_destroy(g);
}

/**
 * Second game_add_link test
 */
void test2_game_add_link()
{
    Game *g = NULL;
    Link *l = NULL;
    PRINT_TEST_RESULT(game_add_link(g, l) == ERROR);
}

/**
 * First game_add_player test
 */
void test1_game_add_player()
{
    Game *g = NULL;
    Player *p;
    game_create(&g);
    p = player_create(11);
    game_add_player(g, p);
    PRINT_TEST_RESULT(game_get_player(g) != NULL);
    game_destroy(g);
}

/**
 * Second game_add_player test
 */
void test2_game_add_player()
{
    Game *g = NULL;
    Player *p = NULL;
    PRINT_TEST_RESULT(game_add_player(g, p) == ERROR);
}

/**
 * First game_add_enemy test
 */
void test1_game_add_enemy()
{
    Game *g = NULL;
    Enemy *e;
    game_create(&g);
    e = enemy_create(11);
    game_add_enemy(g, e);
    PRINT_TEST_RESULT(game_get_enemy(g) != NULL);
    game_destroy(g);
}

/**
 * Second game_add_enemy test
 */
void test2_game_add_enemy()
{
    Game *g = NULL;
    Enemy *e = NULL;
    PRINT_TEST_RESULT(game_add_enemy(g, e) == ERROR);
}

/**
 * First game_get_objects_ids_in_map test
 */
void test1_game_get_objects_ids_in_map()
{
    Game *g = NULL;
    Id expected_ids[] = {70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
                         81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91};
    Id *objs;
    int i, j, n_obj, matches = 0;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    objs = game_get_objects_ids_in_map(g, &n_obj);
    if (objs != NULL && n_obj == (int)(sizeof(expected_ids) / sizeof(expected_ids[0])))
    {
        for (i = 0; i < n_obj; i++)
        {
            for (j = 0; j < n_obj; j++)
            {
                if (expected_ids[i] == objs[j])
                {
                    matches++;
                    break;
                }
            }
            if (j == n_obj)
            {
                break;
            }
        }
    }
    PRINT_TEST_RESULT(matches == (int)(sizeof(expected_ids) / sizeof(expected_ids[0])));
    game_destroy(g);
    free(objs);
}

/**
 * Second game_get_objects_ids_in_map test
 */
void test2_game_get_objects_ids_in_map()
{
    Game *g = NULL;
    Id *objs;
    int n_obj;
    objs = game_get_objects_ids_in_map(g, &n_obj);
    PRINT_TEST_RESULT(objs == NULL);
}

/**
 * First game_get_obj test
 */
void test1_game_get_obj()
{
    Game *g = NULL;
    Object *o;
    Id id;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    o = game_get_obj(g, 84);
    id = object_get_id(o);
    PRINT_TEST_RESULT(id == 84);
    game_destroy(g);
}

/**
 * Second game_get_obj test
 */
void test2_game_get_obj()
{
    Game *g = NULL;
    Object *o;
    o = game_get_obj(g, 21);
    PRINT_TEST_RESULT(o == NULL);
}

/**
 * First game_get_obj_name test
 */
void test1_game_get_obj_name()
{
    Game *g = NULL;
    char *n;
    game_create(&g);
    game_create_from_file(g, "data/nuevo.dat");
    n = game_get_obj_name(g, 88);
    PRINT_TEST_RESULT(n != NULL && strcmp(n, "Lightswitch6") == 0);
    game_destroy(g);
}

/**
 * Second game_get_obj_name test
 */
void test2_game_get_obj_name()
{
    Game *g = NULL;
    char *n;
    n = game_get_obj_name(g, 90);
    PRINT_TEST_RESULT(n == NULL);
}


#include <stdio.h>
#include <stdlib.h>

#include "game_rules.h"
#include "types.h"
#include "space.h"
#include "game.h"
#include "player.h"
#include "enemy.h"
#include "inventory.h"
#include "object.h"

#define LEFT_E_EYE 15 /*!< Left eye of the enemy*/
#define RIGHT_E_EYE 19 /*!< Right eye of the enemy*/

/**
 * game_rules_update Updates and applies the game rules
*/
void game_rules_update(Game *game)
{
    Player *player;
    Inventory *inventory;
    Object **objects;
    int i, j;
    int rnd;
    Id id_obj;
    T_ObjType type;
    Enemy *enemy;
    char **gdesc;

    player = game_get_player(game);
    enemy = game_get_enemy(game);
    inventory = player_get_inventory(player);
    objects = game_get_objects(game);

    if (game_get_ncomands(game) % 5 == 0)
    {
        rnd = (rand() / RAND_MAX) * NUM_RAND_RULES;

        if (rnd == 1)
        {
            game_rules_TOFF_SPACES(game);
        }
        else if (rnd == 2)
        {
            game_rules_HPUP_ENEMY(game);
        }
    }
    for (i = 0; i < MAX_OBJECTS && objects[i] != NULL; i++)
    {
        id_obj = object_get_id(objects[i]);
        if (inventory_has_obj(inventory, id_obj) == TRUE)
        {
            type = object_get_type(objects[i]);

            if (type == STORAGE)
            {
                game_rules_UP_INVENTORY(game);
            }
            else if (type == FOOD)
            {
                game_rules_TAKE_FOOD(game);
                player_del_object(player, id_obj);
            }
            else if (type == POTION)
            {
                game_rules_TAKE_POTION(game);
            }
            else if (type == SHIELD)
            {
                game_rules_ADD_SHIELD(game);
            }
        }
    }
    if (enemy_get_health(enemy) <= 0)
    {
        for (j = 0; j < MAX_LINKS; j++)
        {
            link_set_status(space_get_link_with_direction(game_get_space(game, enemy_get_location(enemy)), j), OPENED);
            gdesc = space_get_gdesc(game_get_space(game, enemy_get_location(enemy)));
            gdesc[N_CMDT][LEFT_E_EYE] = 'x';
            gdesc[N_CMDT][RIGHT_E_EYE] = 'x';
        }
    }

    return;
}

/**
 * game_rules_TOFF_SPACES turns off the spaces every certain number of commands
*/
void game_rules_TOFF_SPACES(Game *game)
{
    int i;
    Space **spaces;

    spaces = game_get_spaces(game);

    for (i = 0; spaces[i] != NULL; i++)
    {
        space_set_light(spaces[i], FALSE);
    }

    return;
}

/**
 * game_rules_TAKE_FOOD it is possible to take some objects that increase your HP
*/
void game_rules_TAKE_FOOD(Game *game)
{
    int hp, n, health;
    Player *player;

    player = game_get_player(game);

    health = player_get_health(player);

    n = rand() % MAX_PLAYER_HEALTH;

    if (health + n >= MAX_PLAYER_HEALTH)
        hp = MAX_PLAYER_HEALTH;
    else
        hp = health + n;

    player_set_health(player, hp);

    return;
}

/**
 * game_rules_TAKE_POTION when you take the potion you can either heal or damage yourself
*/
void game_rules_TAKE_POTION(Game *game)
{
    int hp;
    Player *player;

    player = game_get_player(game);

    if (rand() % 2)
        hp = player_get_health(player) + 1;
    else
        hp = player_get_health(player) - 1;

    player_set_health(player, hp);

    return;
}

/**
 * game_rules_HPUP_ENEMY increases the HP of the enemy randomly
*/
void game_rules_HPUP_ENEMY(Game *game)
{
    Enemy *enemy;
    int enemy_cur_health, enemy_new_health;

    enemy = game_get_enemy(game);

    enemy_cur_health = enemy_get_health(enemy);

    enemy_new_health = enemy_cur_health + (rand() / RAND_MAX) * 5;

    enemy_set_health(enemy, enemy_new_health);

    return;
}

/**
 * game_rules_ADD_SHIELD adds extra HP if the player is full health
*/
void game_rules_ADD_SHIELD(Game *game)
{
    int hp;
    Player *player;

    player = game_get_player(game);

    if (player_get_health(player) == MAX_PLAYER_HEALTH)
    {
        hp = MAX_PLAYER_HEALTH + 3;
        player_set_health(player, hp);
    }

    return;
}

/**
 * game_rules_UP_INVENTORY increases the size of the inventory
*/
void game_rules_UP_INVENTORY(Game *game)
{
    Player *player;
    Inventory *inventory;
    int inventory_cur_size, inventory_new_size;

    player = game_get_player(game);

    inventory = player_get_inventory(player);

    inventory_cur_size = inventory_get_max_objs(inventory);

    if (inventory_cur_size + 5 <= MAX_INVENTORY_SIZE)
    {
        inventory_new_size = inventory_cur_size + 5;
    }
    else
    {
        inventory_new_size = MAX_INVENTORY_SIZE;
    }

    inventory_set_max_objs(inventory, inventory_new_size);

    return;
}

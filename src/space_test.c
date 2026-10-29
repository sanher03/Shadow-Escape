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
#include "space.h"
#include "space_test.h"
#include "link.h"
#include "set.h"
#include "test.h"

#define MAX_TESTS 42 /*!< Total number of tests*/

/**
 * @brief Main function for SPACE unit tests.
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
        printf("Running all test for module Space:\n");
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
        test1_space_create();
    if (all || test == 2)
        test2_space_create();
    if (all || test == 3)
        test1_space_get_id();
    if (all || test == 4)
        test2_space_get_id();
    if (all || test == 5)
        test1_space_set_name();
    if (all || test == 6)
        test2_space_set_name();
    if (all || test == 7)
        test1_space_add_object();
    if (all || test == 8)
        test2_space_add_object();
    if (all || test == 9)
        test1_space_set_gdesc();
    if (all || test == 10)
        test2_space_set_gdesc();
    if (all || test == 11)
        test1_space_has_object_id();
    if (all || test == 12)
        test2_space_has_object_id();
    if (all || test == 13)
        test1_space_del_object();
    if (all || test == 14)
        test2_space_del_object();
    if (all || test == 15)
        test1_space_get_num_obj();
    if (all || test == 16)
        test2_space_get_num_obj();
    if (all || test == 17)
        test1_space_get_name();
    if (all || test == 18)
        test2_space_get_name();
    if (all || test == 19)
        test1_space_get_description();
    if (all || test == 20)
        test2_space_get_description();
    if (all || test == 21)
        test1_space_set_description();
    if (all || test == 22)
        test2_space_set_description();
    if (all || test == 23)
        test1_space_get_link_with_direction();
    if (all || test == 24)
        test2_space_get_link_with_direction();
    if (all || test == 25)
        test1_space_add_link();
    if (all || test == 26)
        test2_space_add_link();
    if (all || test == 27)
        test1_space_get_object_set();
    if (all || test == 28)
        test2_space_get_object_set();
    if (all || test == 29)
        test1_space_get_gdesc();
    if (all || test == 30)
        test2_space_get_gdesc();
    if (all || test == 31)
        test1_space_gdesc_create();
    if (all || test == 32)
        test2_space_gdesc_create();
    if (all || test == 33)
        test1_space_get_light();
    if (all || test == 34)
        test2_space_get_light();
    if (all || test == 35)
        test1_space_set_light();
    if (all || test == 36)
        test2_space_set_light();
    if (all || test == 37)
        test1_space_set_det_descr();
    if (all || test == 38)
        test2_space_set_det_descr();
    if (all || test == 39)
        test1_space_get_det_descr();
    if (all || test == 40)
        test2_space_get_det_descr();
    if (all || test == 41)
        test1_space_get_link_with_name();
    if (all || test == 42)
        test2_space_get_link_with_name();

    PRINT_PASSED_PERCENTAGE;

    return __test_passed == __test_counter ? 0 : 1;
}

/** First space creation test
 */
void test1_space_create()
{
    int result;
    Space *s;
    s = space_create(7);
    result = s != NULL;
    PRINT_TEST_RESULT(result);
    space_destroy(s);
}

/** Second space creation test
 */
void test2_space_create()
{
    Space *s;
    s = space_create(7);
    PRINT_TEST_RESULT(space_get_id(s) == 7);
    space_destroy(s);
}

/**
 * First space id getter test
 */
void test1_space_get_id()
{
    Space *s;
    s = space_create(25);
    PRINT_TEST_RESULT(space_get_id(s) == 25);
    space_destroy(s);
}

/**
 * Second space id getter test
 */
void test2_space_get_id()
{
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}

/**
 * First space name setter test
 */
void test1_space_set_name()
{
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_name(s, "Fabio") == OK);
    space_destroy(s);
}

/**
 * Second space name setter test
 */
void test2_space_set_name()
{
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_name(s, "Fabio") == ERROR);
}

/**
 * First space name getter test
 */
void test1_space_get_name()
{
    Space *s;
    s = space_create(25);
    space_set_name(s, "Fabio");
    PRINT_TEST_RESULT(strcmp(space_get_name(s), "Fabio") == 0);
    space_destroy(s);
}

/**
 * Second space name getter test
 */
void test2_space_get_name()
{
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

/**
 * First space add object test
 */
void test1_space_add_object()
{
    Space *s;
    Id obj = 10;
    s = space_create(5);
    PRINT_TEST_RESULT(space_add_object(s, obj) == OK);
    space_destroy(s);
}

/**
 * Second space add object test
 */
void test2_space_add_object()
{
    Space *s = NULL;
    PRINT_TEST_RESULT(space_add_object(s, NO_ID) == ERROR);
}

/**
 * First space object check test
 */
void test1_space_has_object_id()
{
    Space *s;
    s = space_create(5);
    space_add_object(s, 23);
    PRINT_TEST_RESULT(space_has_object_id(s, 23) == TRUE);
    space_destroy(s);
}

/**
 * Second space object check test
 */
void test2_space_has_object_id()
{
    Space *s = NULL;
    PRINT_TEST_RESULT(space_has_object_id(s, NO_ID) == FALSE);
}

/**
 * First space delete test
 */
void test1_space_del_object()
{
    Space *s;
    Id obj = 10;
    s = space_create(5);
    space_add_object(s, obj);
    PRINT_TEST_RESULT(space_del_object(s, obj) == OK);
    space_destroy(s);
}

/**
 * Second space delete test
 */
void test2_space_del_object()
{
    Space *s = NULL;
    PRINT_TEST_RESULT(space_del_object(s, NO_ID) == ERROR);
}

/**
 * First space num of objects getter test
 */
void test1_space_get_num_obj()
{
    Space *s;
    s = space_create(5);
    space_add_object(s, 23);
    space_add_object(s, 24);
    PRINT_TEST_RESULT(space_get_num_obj(s) == 2);
    space_destroy(s);
}

/**
 * Second space num of objects getter test
 */
void test2_space_get_num_obj()
{
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_num_obj(s) == -1);
}

/**
 * First space description setter test
 */
void test1_space_set_description()
{
    Space *s = space_create(7);
    PRINT_TEST_RESULT(space_set_description(s, "DESC") == OK);
    space_destroy(s);
}

/**
 * Second space description setter test
 */
void test2_space_set_description()
{
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_description(s, "DESC") == ERROR);
}

/**
 * First space description getter test
 */
void test1_space_get_description()
{
    Space *s = space_create(7);
    space_set_description(s, "DESC");
    PRINT_TEST_RESULT(strcmp(space_get_description(s), "DESC") == 0);
    space_destroy(s);
}

/**
 * Second space description getter test
 */
void test2_space_get_description()
{
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_description(s) == ERROR);
}

/**
 * First space link getter test
 */
void test1_space_get_link_with_direction()
{
    Space *s = space_create(7);
    Link *l = link_create(7);
    DIRECTION dir = N;
    space_add_link(s, l);
    PRINT_TEST_RESULT(space_get_link_with_direction(s, dir) != NULL);
    space_destroy(s);
}

/**
 * Second space link getter test
 */
void test2_space_get_link_with_direction()
{
    Space *s = NULL;
    DIRECTION dir = N;
    PRINT_TEST_RESULT(space_get_link_with_direction(s, dir) == NULL);
}

/**
 * First space link addition test
 */
void test1_space_add_link()
{
    Space *s = space_create(23);
    Link *l = link_create(21);
    PRINT_TEST_RESULT(space_add_link(s, l) == OK);
    space_destroy(s);
}

/**
 * Second space link addition test
 */
void test2_space_add_link()
{
    Space *s = NULL;
    Link *l = NULL;
    PRINT_TEST_RESULT(space_add_link(s, l) == ERROR);
}

/**
 * First space object set getter test
 */
void test1_space_get_object_set()
{
    Space *s = space_create(23);
    Id *objs = space_get_object_set(s);
    PRINT_TEST_RESULT(objs != NULL);
    space_destroy(s);
    free(objs);
}

/**
 * Second space object set getter test
 */
void test2_space_get_object_set()
{
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_object_set(s) == NULL);
}

/**
 * First space gdesc getter test
 */
void test1_space_get_gdesc()
{
    Space *s = space_create(23);
    PRINT_TEST_RESULT(space_get_gdesc(s) != NULL);
    space_destroy(s);
}

/**
 * Second space gdesc getter test
 */
void test2_space_get_gdesc()
{
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_gdesc(s) == NULL);
}

/**
 * First space gdesc setter test
 */
void test1_space_set_gdesc()
{
    Space *s = space_create(23);
    char **gdesc = space_gdesc_create();
    PRINT_TEST_RESULT(space_set_gdesc(s, gdesc) == OK);
    space_gdesc_destroy(gdesc);
    space_destroy(s);
}

/**
 * Second space gdesc setter test
 */
void test2_space_set_gdesc()
{
    Space *s = NULL;
    char **gdesc = NULL;
    PRINT_TEST_RESULT(space_set_gdesc(s, gdesc) == ERROR);
}

/**
 * First space gdesc create test
 */
void test1_space_gdesc_create()
{
    char **gdesc = space_gdesc_create();
    PRINT_TEST_RESULT(gdesc != NULL);
    space_gdesc_destroy(gdesc);
}

/**
 * Second space gdesc create test
 */
void test2_space_gdesc_create()
{
    char **gdesc = space_gdesc_create();
    PRINT_TEST_RESULT(gdesc[0] != NULL);
    space_gdesc_destroy(gdesc);
}

void test1_space_get_light(){
    
    Space *s = NULL;

    s = space_create(33);

    space_set_light(s, TRUE);

    PRINT_TEST_RESULT(space_get_light(s) == TRUE);

    space_destroy(s);
}

void test2_space_get_light(){
    
    Space *s = NULL;

    PRINT_TEST_RESULT(space_get_light(s) == FALSE);
}

void test1_space_set_light(){

    Space *s = NULL;

    s = space_create(69);

    PRINT_TEST_RESULT(space_set_light(s, TRUE) == OK);

    space_destroy(s);
}

void test2_space_set_light(){

    Space *s = NULL;

    PRINT_TEST_RESULT(space_set_light(s, TRUE) == ERROR);
}

void test1_space_set_det_descr(){

    Space *s = NULL;

    s = space_create(777);

    PRINT_TEST_RESULT(space_set_det_descr(s, "Nothing else") == OK);

    space_destroy(s);
}

void test2_space_set_det_descr(){

    Space *s = NULL;

    PRINT_TEST_RESULT(space_set_det_descr(s, "Pillow") == ERROR);
}

void test1_space_get_det_descr(){

    Space *s = NULL;

    s = space_create(81);

    space_set_det_descr(s, "Ester Daniels");

    PRINT_TEST_RESULT(strcmp(space_get_det_descr(s), "Ester Daniels") == 0);

    space_destroy(s);
}

void test2_space_get_det_descr(){

    Space *s = NULL;

    PRINT_TEST_RESULT(space_get_det_descr(s) == NULL);
}

void test1_space_get_link_with_name(){

    Space *s = NULL;
    Link *l = NULL;

    s = space_create(1999);

    l = link_create(1992);

    link_set_name(l, "Number of the link?");

    space_add_link(s, l);

    PRINT_TEST_RESULT(space_get_link_with_name(s, "Number of the link?") != NULL);

    space_destroy(s);
}

void test2_space_get_link_with_name(){

    Space *s = NULL;
    
    PRINT_TEST_RESULT(space_get_link_with_name(s, "No pain, no gain") == NULL);
}
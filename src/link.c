/**
 * @brief It implements the link module
 *
 * @file link.c
 * @author Álvaro de Santos
 * @version 3.0
 * @date 25-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "link.h"
#include "types.h"

/**
 * @brief The link structure
 *
 * It stores information of the different links managed by the game
 */
struct _Link
{
	Id id;					  /*!< Id of the link*/
	char name[WORD_SIZE + 1]; /*!< Name of the link*/
	Id or;					  /*!< origin space of the link*/
	Id dest;				  /*!< destination space of the link*/
	DIRECTION dir;			  /*!< direction of the link*/
	LINKSTATUS st;			  /*!< status of the link (opened or closed)*/
};

/**					link CREATE / DESTROY functions					**/

/**
 * link_create Allocates memory for the data structure and initializes its fields
 */
Link *link_create(Id id)
{
	Link *link = NULL;

	/* Error control */
	if (id == NO_ID)
		return NULL;

	link = (Link *)malloc(1 * sizeof(Link));
	if (link == NULL)
	{
		return NULL;
	}

	link->id = id;
	link->name[0] = '\0';
	link->or = NO_ID;
	link->dest = NO_ID;
	link->dir = N;
	link->st = CLOSED;

	return link;
}

/**
 * link_destroy Frees the allocated memory of the given link
 */
STATUS link_destroy(Link *link)
{
	/*Error control*/
	if (link == NULL)
	{
		return ERROR;
	}
	free(link);
	return OK;
}

/** 				link SET functions 					**/

/**
 * link_set_name Copies the string given to the name field of the link
 */
STATUS link_set_name(Link *link, char *name)
{
	/*Error control*/
	if (link == NULL || name == NULL)
	{
		return ERROR;
	}

	strcpy(link->name, name);

	return OK;
}

/**
 * link_set_origin Copies the id given to the origin field of the link
 */
STATUS link_set_origin(Link *link, Id or)
{
	/*Error control*/
	if (link == NULL || or == NO_ID)
	{
		return ERROR;
	}

	link->or = or ;

	return OK;
}

/**
 * link_set_destination Copies the id given to the destination field of the link
 */
STATUS link_set_destination(Link *link, Id dest)
{
	/*Error control*/
	if (link == NULL || dest == NO_ID)
	{
		return ERROR;
	}

	link->dest = dest;

	return OK;
}

/**
 * link_set_direction Copies the DIRECTION given to the direction field of the link
 */
STATUS link_set_direction(Link *link, DIRECTION dir)
{
	/*Error control*/
	if (link == NULL)
	{
		return ERROR;
	}

	link->dir = dir;

	return OK;
}

/**
 * link_set_status Copies the status given to the status field of the link
 */
STATUS link_set_status(Link *link, LINKSTATUS st)
{
	/*Error control*/
	if (link == NULL)
	{
		return ERROR;
	}

	link->st = st;

	return OK;
}

/** 			link GET functions 				**/

/**
 * link_get_id Acesses the link structure to get the id
 */
Id link_get_id(Link *link)
{
	/*Error control*/
	if (link == NULL)
	{
		return NO_ID;
	}

	return link->id;
}

/**
 * link_get_name Acesses the link structure to get the name
 */
char *link_get_name(Link *link)
{
	/*Error control*/
	if (link == NULL)
	{
		return NULL;
	}

	return link->name;
}

/**
 * link_get_origin Acesses the link structure to get the origin
 */
Id link_get_origin(Link *link)
{
	/*Error control*/
	if (link == NULL)
	{
		return NO_ID;
	}

	return link->or ;
}

/**
 * link_get_destination Acesses the link structure to get the destination
 */
Id link_get_destination(Link *link)
{
	/*Error control*/
	if (link == NULL)
	{
		return NO_ID;
	}

	return link->dest;
}

/**
 * link_get_direction Acesses the link structure to get the direction
 */
DIRECTION link_get_direction(Link *link)
{
	/*No error value for direction - should be checked before - we return default value*/
	if (link == NULL)
	{
		return N;
	}

	return link->dir;
}

/**
 * link_get_status Acesses the link structure to get the status
 */
LINKSTATUS link_get_status(Link *link)
{
	/*No error value for direction - should be checked before - we return default value*/
	if (link == NULL)
	{
		return CLOSED;
	}

	return link->st;
}

/** 				link PRINT functions 					**/

/**
 * link_print Acesses the link structure to print all its fields
 */
STATUS link_print(Link *link)
{
	/*Error control*/
	if (link == NULL)
	{
		return ERROR;
	}

	/* 1. Print the id and the name of the link */
	fprintf(stdout, "--> Link (Id: %ld; Name: %s; Origin: %ld; Destination: %ld; Direction: %d; Status: %d;)\n", link->id, link->name, link->or, link->dest, link->dir, link->st);

	return OK;
}

STATUS link_print_to_save(Link *link, FILE *file)
{
  if (!link || !file)
  {
    return ERROR; 
  }

  fprintf(file, "#l:%ld|%s|%ld|%ld|%d|%d|\n", link->id, link->name, link->or, link->dest, link->dir, link->st);

  return OK;
}

/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000 /*!< Maximun length of a string*/

#define DESCR_SIZE 2000 /*!< Maximun length of a description*/

#define MAX_PLAYER_HEALTH 15 /*!< Maximun health of the player*/

#define NO_ID -1 /*!< Default id assigned*/

typedef long Id; /*!< type of the id variable*/

/**
 * @brief Possible values of a boolean
 */
typedef enum
{
  FALSE, /*!< The condition is not given*/
  TRUE   /*!< The condition is given*/
} BOOL;

/**
 * @brief Possible values of STATUS
 */
typedef enum
{
  ERROR, /*!< Executed with error*/
  OK     /*!< Executed without error*/
} STATUS;

/**
 * @brief Possible values of status
 */
typedef enum
{
  OPENED, /*!< Link is opened*/
  CLOSED  /*!< Link is closed*/
} LINKSTATUS;

/**
 * @brief Directions that can be taken
 */
typedef enum
{
  UNKN = -1, /*!< Unknown direction*/
  N,         /*!< Moves up*/
  S,         /*!< Moves down*/
  E,         /*!< Moves to the right*/
  W,         /*!< Moves to the left*/
  U,         /*!< Moves up*/
  D          /*!< Moves down*/
} DIRECTION;

#endif
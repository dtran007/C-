/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  SpaceShip.h
 *  * Author: Danny Tran
 *  * Description:  SpaceShip Interface file for all Ships to Derive From
 *  * Date: 17 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */


#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "LinkedList.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class SpaceShip
{

	public:

		/** @pre None.
		 *   @post Destructor
		 */
		virtual ~SpaceShip() {};

		/** @pre None.
		 *   @post Pure Virtual Method for derived Classes to return attackPower
		 *   @return None.
		 */
		virtual int attackPower() const = 0;

		/** @pre None.
		 *   @post Pure Virtual Method for derived Classes to return currentHull
		 *   @return None.
		 */
		virtual int currentHull() const = 0;

		/** @pre None.
		 *   @post Pure Virtual Method for derived Classes to return maxHull
		 *   @return None.
		 */
		virtual int maxHull() const = 0;

		/** @pre None.
		 *   @post Pure virtual Method for derived Classes to return takeDamage
		 *   @return None.
		 */
		virtual bool takeDamage( int amount ) = 0;

		/** @pre None.
		 *   @post Pure virtual Method for derived classes to return shields
		 *   @return None.
		 */
		virtual bool shields() const = 0;

		/** @pre None.
		 *   @post Pure Virtual Method for derived classes to return universe
		 *   @return None.
		 */
		virtual string universe() const = 0;

		/** @pre None.
		 *   @post Pure Virtual Method for derived classes to return status
		 *   @return None.
		 */
		virtual string status() const = 0;

		/** @pre None.
		 *   @post Pure Virtual Method for derived classes to return name.
		 *   @return None.
		 */ //Added Method for ship commander's name to compare same universe
		virtual string name() const = 0;

		/** @pre None.
		 *   @post Pure Virtual Method for derived classes to return lastwhisper.
		 *   @return None.
		 */  //Added method for cout the last words of a ship upon dying from destructor
		virtual string lastwhisper() const = 0;
};
#endif

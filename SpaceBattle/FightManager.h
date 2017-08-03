/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  FightManager.h
 *  * Author: Danny Tran
 *  * Description: Header File for FightManager Class
 *  * Date: 17 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H

#include "SpaceShip.h"
#include "StarTrekShip.h"
#include "StarWarsShip.h"
#include "LinkedList.h"

using namespace std;

class FightManager
{
	public:

		/** @pre None.
		 *   @post Constructor called to import file data into LinkedList
		 *   @return None.
		 */
		FightManager(string filename);

		/** @pre None.
		 *   @post Empty Constructor
		 *   @return None.
		 */
		FightManager();

		/** @pre Assumes an already instantiated LinkedList of SpaceShip class from Constructor
		 *   @post None.
		 *   @return Output of Universe winner between StarWars and StarTrek
		 */
		void Fight();

		/** @pre None.
		 *   @post Deconstructor deletes LinkedList of SpaceShips
		 *   @return None.
		 */
		~FightManager();

	private:

		/** @pre None.
		 *   @post Pointer to LinkedList of SpaceShips
		 *   @return None.
		 */
		LinkedList<SpaceShip*>* ListofShips;

};
#endif

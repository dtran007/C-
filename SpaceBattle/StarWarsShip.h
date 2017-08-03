/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  StarWarsShip.h
 *  * Author: Danny Tran
 *  * Description:  Header File for StarTrekShip Class
 *  * Date: 17 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef STARWARSSHIP_H
#define STARWARSSHIP_H

#include "SpaceShip.h"
#include "LinkedList.h"



class StarWarsShip : public SpaceShip
{

	private:
		/** @pre None.
		 *   @post None.
		 */
		string m_universe;

		/** @pre None.
		 *   @post None.
		 */
		string m_pilotName;

		/** @pre None.
		 *   @post None.
		 */
		int m_attackPower;

		/** @pre None.
		 *   @post None.
		 */
		int m_maxHull;

		/** @pre None.
		 *   @post None.
		 */
		bool m_shieldStatus;

		/** @pre None.
		 *   @post None.
		 */
		string m_lastWords=""; //Star Wars only

		/** @pre None.
		 *   @post None.
		 */
		int m_currentHull; //Created


	public:

		/** @pre None.
		 *   @post Constructor with parameter to set values to StarWars variables
		 *   @return None.
		 */
		StarWarsShip(string universe, string pilotName, int attackPower, int maxHull, bool shieldStatus, string lastWords);


		/** @pre None.
		 *   @post Parameterless Constructor
		 *   @return None.
		 */
		StarWarsShip();


		/** @pre None.
		 *   @post Destructor
		 *   @return Final Message from Ship
		 */
		~StarWarsShip();


		/** @pre None.
		 *   @post None.
		 *   @return m_attackPower
		 */
		int attackPower() const;


		/** @pre None.
		 *   @post None.
		 *   @return m_currentHull
		 */
		int currentHull() const;


		/** @pre None.
		 *   @post None.
		 *   @return m_maxHull
		 */
		int maxHull() const;


		/** @pre None.
		 *   @post None.
		 *   @return if ship dies or not after taking damage
		 */
		bool takeDamage(int amount);


		/** @pre None.
		 *   @post None.
		 *   @return m_shieldStatus
		 */
		bool shields() const;


		/** @pre None.
		 *   @post None.
		 *   @return m_universe
		 */
		string universe() const;


		/** @pre None.
		 *   @post None.
		 *   @return string with ship status
		 */
		string status() const;


		/** @pre None.
		 *   @post None.
		 *   @return m_captainName
		 */
		string name()const;


		/** @pre None.
		 *   @post None.
		 *   @return lastwhisper
		 */
		string lastwhisper() const;


};
#endif

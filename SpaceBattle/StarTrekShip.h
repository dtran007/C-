/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  StarTrekShip.h
 *  * Author: Danny Tran
 *  * Description:  Header File for StarTrekShip Class
 *  * Date: 17 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef STARTREKSHIP_H
#define STARTREKSHIP_H

#include "SpaceShip.h"
#include "LinkedList.h"

class StarTrekShip : public SpaceShip
{
	private:
		/** @pre None.
		 *   @post None.
		 */
		string m_universe="";

		/** @pre None.
		 *   @post None.
		 */
		string m_captainName="";

		/** @pre None.
		 *   @post None.
		 */
		int m_attackPower;

		/** @pre None.
		 *   @post None.
		 */
		int m_crewNumber;  //StarTrek Only

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
		int m_currentHull;

	public:

		/** @pre None.
		 *   @post Constructor with parameter to set values to StarTrek variables
		 *   @return None.
		 */
		StarTrekShip(string universe, string captainName, int attackPower, int crewNumber, int maxHull, bool shieldStatus);


		/** @pre None.
		 *   @post Parameterless Constructor
		 *   @return None.
		 */
		StarTrekShip();


		/** @pre None.
		 *   @post Destructor
		 *   @return Final Message from Ship
		 */
		~StarTrekShip();

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
		string name() const;


		/** @pre None.
		 *   @post None.
		 *   @return lastwhisper
		 */
		string lastwhisper() const;

};
#endif

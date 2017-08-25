/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Package.h
 *  * Author: Danny Tran
 *  * Description: Package Class Header File
 *  * Date: 21 April 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package
{
	private:
		std::string m_priority;
		std::string m_content;
		std::string m_destination;

	public:
		/** @pre None.
		 *   @post Package constructor.
		 *   @return None.
		 */
		Package();

		/** @pre None.
		 *   @post Constructor with parameters.
		 *   @return None.
		 */
		Package(std::string priority, std::string content, std::string destination);

		/** @pre None.
		 *   @post Destructor.
		 *   @return None.
		 */
		~Package();

		/** @pre None.
		 *   @post None.
		 *   @return string of Package Priority.
		 */
		std::string getPriority();

		/** @pre None.
		 *   @post set Priority of Package.
		 *   @return None.
		 */
		void setPriority(std::string priority);

		/** @pre None.
		 *   @post None.
		 *   @return string of Package Content.
		 */
		std::string getContent();

		/** @pre None.
		 *   @post set Content of Package.
		 *   @return None.
		 */
		void setContent(std::string content);

		/** @pre None.
		 *   @post None.
		 *   @return string of Package Destination.
		 */
		std::string getDestination();

		/** @pre None.
		 *   @post set Destination of Package.
		 *   @return None.
		 */
		void setDestination(std::string destination);

		/** @pre None.
		 *   @post None.
		 *   @return Bool of package Priority.
		 */
		bool operator==(const Package& rhs) const;

		/** @pre None.
		 *   @post None.
		 *   @return Bool of Package Priorty followed by Content.
		 */
		bool operator<(const Package& rhs) const;

		/** @pre None.
		 *   @post None.
		 *   @return Bool of Package Priority followed by Content.
		 */
		bool operator>(const Package& rhs) const;

		//enums ended up not being implemented
		//	enum shipPriority{whenever, ground, TwoDay, overnight};
};
#endif

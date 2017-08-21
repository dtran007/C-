/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  NotFoundException.h
 *  * Author: Danny Tran
 *  * Description:  NotFoundExcpetion headerfile
 *  * Date: 31 Mar 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#ifndef NOTFOUNDEXCEPTION_H
#define NOTFOUNDEXCEPTION_H

#include <iostream>
#include <string>
#include <stdexcept>


class NotFoundException : public std::runtime_error
{
	public:

		/** @pre None.
		 *   @post Throw a customized exception
		 *   @return None.
		 */
		NotFoundException(std::string message);

};
#endif

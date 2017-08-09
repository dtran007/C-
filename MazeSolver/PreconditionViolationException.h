/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  PreconditionViolationException.h
 *  * Author: Danny Tran
 *  * Description:  PreconditionViolationException headerfile
 *  * Date: 3 Mar 2017
 *  *
 *  ---------------------------------------------------------------------------- */
#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H

#include <iostream>
#include <string>
#include <stdexcept>

class PreconditionViolationException : public std::runtime_error
{
	public:

		/** @pre None.
		 *   @post Throw a customized runtime_error.
		 *   @return None.
		 */
		PreconditionViolationException(std::string message);

};
#endif

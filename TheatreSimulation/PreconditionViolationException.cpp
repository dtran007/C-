/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  PreconditionViolationException.cpp
 *  * Author: Danny Tran
 *  * Description:  PreconditionViolationException implementation file
 *  * Date: 25 Feb 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(std::string message) : std::runtime_error(message)
{

}

/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  NotFoundException.cpp
 *  * Author: Danny Tran
 *  * Description:  NotFoundException implementation file
 *  * Date: 31 Mar 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#include "NotFoundException.h"

NotFoundException::NotFoundException(std::string message)
	: std::runtime_error(message)
{

}

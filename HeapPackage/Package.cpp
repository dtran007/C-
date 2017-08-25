/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  Package.cpp
 *  * Author: Danny Tran
 *  * Description: Package Class
 *  * Date: 21 April 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#include "Package.h"


bool Package::operator==(const Package& rhs) const
{

	int thisvar;
	int rhsvar;

	if(this->m_priority == "overnight")
	{
		thisvar = 0;
	}
	else if(this->m_priority == "2-Day")
	{
		thisvar = 1;
	}
	else if(this->m_priority == "ground")
	{
		thisvar = 2;
	}
	else if(this->m_priority == "whenever")
	{
		thisvar = 3;
	}

	if(rhs.m_priority == "overnight")
	{
		rhsvar = 0;
	}
	else if(rhs.m_priority == "2-Day")
	{
		rhsvar = 1;
	}
	else if(rhs.m_priority == "ground")
	{
		rhsvar = 2;
	}
	else if(rhs.m_priority == "whenever")
	{
		rhsvar = 3;
	}


	return(thisvar==rhsvar);
}

bool Package::operator<(const Package& rhs) const
{

	int thisvar;
	int rhsvar;

	if(this->m_priority == "overnight")
	{
		thisvar = 0;
	}
	else if(this->m_priority == "2-Day")
	{
		thisvar = 1;
	}
	else if(this->m_priority == "ground")
	{
		thisvar = 2;
	}
	else if(this->m_priority == "whenever")
	{
		thisvar = 3;
	}

	if(rhs.m_priority == "overnight")
	{
		rhsvar = 0;
	}
	else if(rhs.m_priority == "2-Day")
	{
		rhsvar = 1;
	}
	else if(rhs.m_priority == "ground")
	{
		rhsvar = 2;
	}
	else if(rhs.m_priority == "whenever")
	{
		rhsvar = 3;
	}


	if(thisvar == rhsvar)
	{
		if( this->m_content < rhs.m_content)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	return(thisvar<rhsvar);
}


bool Package::operator>(const Package& rhs) const
{

	int thisvar;
	int rhsvar;

	if(this->m_priority == "overnight")
	{
		thisvar = 0;
	}
	else if(this->m_priority == "2-Day")
	{
		thisvar = 1;
	}
	else if(this->m_priority == "ground")
	{
		thisvar = 2;
	}
	else if(this->m_priority == "whenever")
	{
		thisvar = 3;
	}

	if(rhs.m_priority == "overnight")
	{
		rhsvar = 0;
	}
	else if(rhs.m_priority == "2-Day")
	{
		rhsvar = 1;
	}
	else if(rhs.m_priority == "ground")
	{
		rhsvar = 2;
	}
	else if(rhs.m_priority == "whenever")
	{
		rhsvar = 3;
	}


	if(thisvar == rhsvar)
	{
		if( this->m_content > rhs.m_content)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	return(thisvar>rhsvar);
}

Package::Package()
{

}

Package::Package(std::string priority, std::string content, std::string destination)
{
	m_priority = priority;
	m_content = content;
	m_destination = destination;

}


std::string Package::getPriority()
{
	return(m_priority);
}

void Package::setPriority(std::string priority)
{
	m_priority = priority;
}

std::string Package::getContent()
{
	return(m_content);
}

void Package::setContent(std::string content)
{
	m_content = content;
}

std::string Package::getDestination()
{
	return(m_destination);
}

void Package::setDestination(std::string destination)
{
	m_destination = destination;
}

Package::~Package()
{

}

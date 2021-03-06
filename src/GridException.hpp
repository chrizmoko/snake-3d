// GridException.hpp
//
// An general type of exception that is thrown by the grid for various reasons.

#ifndef GRIDEXCEPTION_HPP
#define GRIDEXCEPTION_HPP

#include <exception>
#include <string>



class GridException : public std::exception
{
public:
	// Creates the exception with containing a message that is passed in.
	GridException(const std::string& msg)
		: std::exception{}, message_{msg}
	{
	}

	// Creates a copy of the exception from an existing one.
	GridException(const GridException& e)
		: std::exception{e}, message_{e.message_}
	{
	}

	// Copies the contents of another exception to this one.
	GridException& operator=(const GridException& e)
	{
		message_ = e.message_;
		return *this;
	}

	// what() is an override from the base class std::exception. This returns
	// the message that was passed in on creation of the exception.
	const char* what() const noexcept override
	{
		return message_.c_str();
	}

protected:
	std::string message_;
};



#endif
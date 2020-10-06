// SnakeDirection.hpp
//
// An enumeration of the possible directions that the snake can move in. Since
// the snake exists in a 3-dimensional space, the snake can move in the
// positive and negative directions of each dimension.

#ifndef SNAKEDIRECTION_HPP
#define SNAKEDIRECTION_HPP



enum class SnakeDirection
{
	XPositive,
	XNegative,
	YPositive,
	YNegative,
	ZPositive,
	ZNegative
};



#endif
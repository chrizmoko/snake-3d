// Snake.hpp
//
// A representation of the snake in the game and consists of a chain of
// positions. The snake can move aroud in 3-dimensional space.

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "SnakeDirection.hpp"
#include "GridPoint.hpp"
#include <queue>
#include <vector>



class Snake
{
public:
	// Creates a snake of length one at the starting position. The speed (s) of
	// the snake defined as the number of positions traveled within a second.
	// The speed must be a positive value, otherwised undefined behavior may
	// occur.
	Snake(const GridPoint& start, float s);

	// Creates a copy of a snake from an existing one.
	Snake(const Snake& snake);

	// move() moves the snake forwards by one unit in the direction that it is
	// provided.
	void move(SnakeDirection direction);

	// append() prevents the tail end of the snake from moving by keeping the
	// position of the tail. In other words, the next time the snake moves, the
	// previous tail position will remaining effectively increasing the length
	// of the snake by one. Multiple calls to append() will be reflected in the
	// snake after each call to the move() method. For example, two calls to
	// append() will be fully realized in the snake after two calls to move().
	void append();

	// appendsWaiting() returns the number of positions appended that are in
	// waiting to be reflected in the snake. If there are three appends in the
	// waitlist, and move() is called once, then 2 will be returned since there
	// are now only two appends waiting to be reflected in the snake.
	int appendsWaiting() const noexcept;

	// length() returns the number of positions that the snake is made up of.
	int length() const noexcept;

	// getHead() returns the position of the head of the snake. The head of
	// the snake is first position of the chain of positions.
	const GridPoint& getHead() const noexcept;

	// getTail() returns the position of the tail of the snake. The tail of
	// the snake is the last position of the chain positions.
	const GridPoint& getTail() const noexcept;

	// getSegment() returns positions that the snake occupies and stores them
	// in a std::vector. The head of the snake would be the first element and
	// the tail would be the last element in the std::vector.
	std::vector<GridPoint> getSegments() const;

	// setSpeed() sets the speed of the snake to the one provided. Speed is
	// defined as the number of positions traveled within a second. The speed
	// must be a positive value, otherwise undefined behavior may occur.
	void setSpeed(float s);

	// getSpeed() returns the current speed of the snake.
	float getSpeed() const noexcept;

private:
	std::queue<GridPoint> segments;
	int appends;
	float speed;
};



#endif
// Snake.cpp
//
// Implementation of Snake.hpp.

#include "Snake.hpp"



Snake::Snake(const GridPoint& start, float s)
	: segments{std::queue<GridPoint>{}}, appends{0}, speed{s}
{
	segments.push(start);
}

Snake::Snake(const Snake& snake)
	: segments{snake.segments}, appends{snake.appends}, speed{snake.speed}
{
}

#include <iostream>

void Snake::move(SnakeDirection direction)
{
	GridPoint pos = segments.back();

	switch (direction)
	{
	case SnakeDirection::XNegative:
		--pos.x;
		break;
	case SnakeDirection::XPositive:
		++pos.x;
		break;
	case SnakeDirection::YNegative:
		--pos.y;
		break;
	case SnakeDirection::YPositive:
		++pos.y;
		break;
	case SnakeDirection::ZNegative:
		--pos.z;
		break;
	case SnakeDirection::ZPositive:
		++pos.z;
		break;
	}

	segments.push(pos);
	if (appends > 0)
	{
		--appends;
	}
	else
	{
		segments.pop();
	}
}

void Snake::append()
{
	++appends;
}

int Snake::appendsWaiting() const noexcept
{
	return appends;
}

int Snake::length() const noexcept
{
	return segments.size();
}

const GridPoint& Snake::getHead() const noexcept
{
	return segments.back();
}

const GridPoint& Snake::getTail() const noexcept
{
	return segments.front();
}

std::vector<GridPoint> Snake::getSegments() const
{
	std::vector<GridPoint> result(segments.size());
	std::queue<GridPoint> copy(segments);

	for (std::size_t i = 0; i < segments.size(); ++i)
	{
		result.at(segments.size() - 1 - i) = copy.front();
		copy.pop();
	}

	return result;
}

void Snake::setSpeed(float s)
{
	speed = s;
}

float Snake::getSpeed() const noexcept
{
	return speed;
}
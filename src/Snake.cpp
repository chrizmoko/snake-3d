// Snake.cpp
//
// Implementation of Snake.hpp.

#include "Snake.hpp"
#include <queue>
#include <vector>
#include "SnakeDirection.hpp"
#include "GridPoint.hpp"



Snake::Snake(const GridPoint& start, float speed)
	: queue_{std::queue<GridPoint>{}}, num_appends_{0}, speed_{speed}
{
	queue_.push(start);
}

Snake::Snake(const Snake& snake)
	: queue_{snake.queue_},
	  num_appends_{snake.num_appends_},
	  speed_{snake.speed_}
{
}

void Snake::move(SnakeDirection direction)
{
	GridPoint pos = queue_.back();

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

	queue_.push(pos);
	if (num_appends_ > 0)
	{
		--num_appends_;
	}
	else
	{
		queue_.pop();
	}
}

void Snake::append()
{
	++num_appends_;
}

int Snake::appendsWaiting() const noexcept
{
	return num_appends_;
}

int Snake::length() const noexcept
{
	return queue_.size();
}

const GridPoint& Snake::getHead() const noexcept
{
	return queue_.back();
}

const GridPoint& Snake::getTail() const noexcept
{
	return queue_.front();
}

std::vector<GridPoint> Snake::getPositionsOccupied() const
{
	std::vector<GridPoint> result(queue_.size());
	std::queue<GridPoint> copy(queue_);

	for (std::size_t i = 0; i < queue_.size(); ++i)
	{
		result.at(queue_.size() - 1 - i) = copy.front();
		copy.pop();
	}

	return result;
}

void Snake::setSpeed(float speed)
{
	speed_ = speed;
}

float Snake::getSpeed() const noexcept
{
	return speed_;
}
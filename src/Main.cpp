#include <iostream>
#include "Snake.hpp"
#include "GridPoint.hpp"



std::ostream& operator<<(std::ostream& os, const GridPoint& point)
{
	os << '(' << point.x << ", " << point.y << ", " << point.z << ')';
	return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<GridPoint>& vector)
{
	os << "Vector[";
	if (vector.size() > 0)
	{
		for (std::size_t i = 0; i < vector.size() - 1; ++i)
		{
			os << vector.at(i) << ", ";
		}
		os << vector.at(vector.size() - 1);
	}
	os << "]";
	return os;
}

int main()
{
	std::cout << "Hello world!" << std::endl;

	Snake snake{{0, 0, 0}, 0.8f};
	std::cout << snake.getHead() << " " << snake.getTail() << std::endl;

	snake.move(SnakeDirection::XPositive);
	std::cout << snake.getHead() << " " << snake.getTail() << std::endl;

	snake.append();
	snake.append();

	snake.move(SnakeDirection::XPositive);
	std::cout << snake.getHead() << " " << snake.getTail() << std::endl;

	snake.move(SnakeDirection::XPositive);
	std::cout << snake.getHead() << " " << snake.getTail() << std::endl;

	snake.move(SnakeDirection::YPositive);
	std::cout << snake.getHead() << " " << snake.getTail() << std::endl;

	std::cout << snake.getSegments() << std::endl;

	Snake snake2 = snake;
	std::cout << snake.getSegments() << " " << snake2.getSegments() << std::endl;

	snake2.move(SnakeDirection::XPositive);
	std::cout << snake.getSegments() << " " << snake2.getSegments() << std::endl;

	std::cin.get();
}
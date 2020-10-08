#include <iostream>
#include "Snake.hpp"
#include "Grid.hpp"
#include "GridPoint.hpp"
#include <SDL2/SDL.h>



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

std::ostream& operator<<(std::ostream& os, const GridCell cell)
{
	switch (cell)
	{
	case GridCell::Empty:
		os << "Empty";
		break;
	case GridCell::Food:
		os << "Food";
		break;
	case GridCell::Snake:
		os << "Snake";
		break;
	}
	return os;
}

int main(int argc, char* argv[])
{
	std::cout << "Hello world!" << std::endl;
	std::cin.get();

	return 0;
}
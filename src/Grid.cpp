// Grid.cpp
//
// Implementation of Grid.hpp.

#include "Grid.hpp"
#include "GridCell.hpp"
#include "GridException.hpp"



Grid::Grid(int x_length, int y_length, int z_length)
	: x_length_{x_length},
	  y_length_{y_length},
	  z_length_{z_length},
	  grid_{nullptr}
{
	if (x_length_ < 0 || y_length_ < 0 || z_length_ < 0)
	{
		throw GridException("Grid dimensions must be positive values.");
	}

	try
	{
		grid_ = new GridCell[x_length_ * y_length_ * z_length_];
		fillGrid(GridCell::Empty);
	}
	catch (...)
	{
		delete[] grid_;
		throw;
	}
}

Grid::Grid(const Grid& grid)
	: x_length_{grid.x_length_},
	  y_length_{grid.y_length_},
	  z_length_{grid.z_length_},
	  grid_{nullptr}
{
	try
	{
		grid_ = new GridCell[x_length_ * y_length_ * z_length_];
	}
	catch (...)
	{
		delete[] grid_;
		throw;
	}
}

Grid::~Grid() noexcept
{
	delete[] grid_;
}

void Grid::clear() noexcept
{
	fillGrid(GridCell::Empty);
}

int Grid::lengthX() const noexcept
{
	return x_length_;
}

int Grid::lengthY() const noexcept
{
	return y_length_;
}


int Grid::lengthZ() const noexcept
{
	return z_length_;
}

bool Grid::isValidCell(int x, int y, int z) const noexcept
{
	return (x >= 0 && x < x_length_ && y >= 0 && y < y_length_ &&
			z >= 0 && z < z_length_);
}

void Grid::setCellAt(int x, int y, int z, GridCell cell)
{
	if (!isValidCell(x, y, z))
	{
		throw GridException("Position (x, y, z) must be within grid bounds.");
	}
	grid_[(x * y_length_ * z_length_) + (y * z_length_) + z] = cell;
}

GridCell Grid::getCellAt(int x, int y, int z)
{
	if (!isValidCell(x, y, z))
	{
		throw GridException("Position (x, y, z) must be within grid bounds.");
	}
	return grid_[(x * y_length_ * z_length_) + (y * z_length_) + z];
}

void Grid::fillGrid(GridCell cell) noexcept
{
	for (int x = 0; x < x_length_; ++x)
	{
		for (int y = 0; y < y_length_; ++y)
		{
			for (int z = 0; z < z_length_; ++z)
			{
				grid_[(x * y_length_ * z_length_) + (y * z_length_) + z] = cell;
			}
		}
	}
}
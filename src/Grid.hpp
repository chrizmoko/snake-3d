// Grid.hpp
//
// A 3-dimensional grid that represents the boundaries that the snake can
// move in. The grid is a collection of cells that are identified with a
// (x, y, z) position. Each position is identified within the ranges of
// 0 <= x <= xLength - 1, 0 <= y <= yLength - 1, and 0 <= z <= xLegnth - 1.

#ifndef GRID_HPP
#define GRID_HPP

#include "GridCell.hpp"



class Grid
{
public:
	// Creates a 3-dimensional grid with the following dimensions. Initially,
	// all spaces in the grid are empty.
	Grid(int x_length, int y_length, int z_length);

	// Creates a copy of the grid from an existing one.
	Grid(const Grid& grid);

	// Safely deallocates the grid to prevent memory leaks.
	~Grid() noexcept;

	// clear() clears the grid so that all cells are empty.
	void clear() noexcept;

	// lengthX() returns the length of the grid along the x-axis.
	int lengthX() const noexcept;

	// lengthY() returns the length of the grid along the y-axis.
	int lengthY() const noexcept;

	// lengthZ() returns the length of the grid along the z-axis.
	int lengthZ() const noexcept;

	// isValidCell() returns true if the provided (x, y, z) position is within
	// the boundaries of the grid. Otherwise, false is returned.
	bool isValidCell(int x, int y, int z) const noexcept;

	// setCellAt() changes the type of cell at the provided (x, y, z) position
	// to the provided cell (Empty, Food, Snake).
	void setCellAt(int x, int y, int z, GridCell cell);

	// getCellAt() returns the contents of the cell at the provided (x, y, z)
	// position. The cell contents are either Empty, Food, or Snake.
	GridCell getCellAt(int x, int y, int z);

private:
	int x_length_;
	int y_length_;
	int z_length_;
	GridCell* grid_;

private:
	// FillGrid() fills all spaces in the grid with the provided GridCell.
	void fillGrid(GridCell cell) noexcept;
};



#endif
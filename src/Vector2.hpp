// Vector2.hpp
//
// A two-dimensional vector where the components are floats.

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>



class Vector2
{
public:
	float x;
	float y;

public:
	// Create a vector whose components are zero.
	Vector2()
		: x{0}, y{0}
	{
	}

	// Create a vector with the given component values.
	Vector2(float vx, float vy)
		: x{vx}, y{vy}
	{
	}

	// unit() returns a the unit vector of the vector.
	Vector2 unit() const
	{
		float mag = sqrt((x * x) + (y * y));
		return {x / mag, y / mag};
	}


	Vector2& operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	Vector2& operator-=(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	Vector2& operator*=(float other)
	{
		x *= other;
		y *= other;

		return *this;
	}

	Vector2& operator/=(float other)
	{
		x /= other;
		y /= other;

		return *this;
	}

	Vector2 operator+() const
	{
		return {x, y};
	}

	Vector2 operator-() const
	{
		return {-x, -y};
	}

	Vector2 operator+(const Vector2& other) const
	{
		return {x + other.x, y + other.y};
	}
	
	Vector2 operator-(const Vector2& other) const
	{
		return {x - other.x, y - othery};
	}
};

Vector2 operator*(const Vector2& vector, float scalar)
{
	return {vector.x * scalar, vector.y * scalar};
}

Vector2 operator*(float scalar, const Vector2& vector)
{
	return {vector.x * scalar, vector.y * scalar};
}



#endif
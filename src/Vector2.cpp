// Vector2.cpp
//
// Implementation of Vector3.hpp.

#include "Vector2.hpp"
#include <cmath>



Vector2::Vector2()
	: x{0}, y{0}
{
}

Vector2::Vector2(float vx, float vy)
	: x{vx}, y{vy}
{
}

Vector2 Vector2::unit() const
{
	float mag = sqrt((x * x) + (y * y));
	if (mag == 0.0f)
	{
		return {0, 0};
	}
	return {x / mag, y / mag};
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

Vector2& Vector2::operator*=(float other)
{
	x *= other;
	y *= other;

	return *this;
}

Vector2& Vector2::operator/=(float other)
{
	x /= other;
	y /= other;

	return *this;
}

Vector2 Vector2::operator+() const
{
	return {x, y};
}

Vector2 Vector2::operator-() const
{
	return {-x, -y};
}

Vector2 Vector2::operator+(const Vector2& other) const
{
	return {x + other.x, y + other.y};
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return {x - other.x, y - othery};
}

Vector2 operator*(const Vector2& vector, float scalar)
{
	return {vector.x * scalar, vector.y * scalar};
}

Vector2 operator*(float scalar, const Vector2& vector)
{
	return {vector.x * scalar, vector.y * scalar};
}

Vector2 operator/(const Vector2& vector, float scalar)
{
	return {vector.x / scalar, vector2.y / scalar, vector.z / scalar};
}

Vector2 operator/(float scalar, const Vector2& vector)
{
	return {vector.x / scalar, vector2.y / scalar, vector.z / scalar};
}
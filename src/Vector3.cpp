// Vector3.cpp
//
// Implementation of Vector3.hpp.

#include "Vector3.hpp"
#include <cmath>



Vector3::Vector3()
	: x{0}, y{0}, z{0}
{
}

Vector3::Vector3(float vx, float vy, float vz)
	: x{vx}, y{vy}, z{vz}
{
}

Vector3 Vector3::unit() const
{
	float mag = sqrt((x * x) + (y * y) + (z * z));
	if (mag == 0.0f)
	{
		return {0, 0, 0};
	}
	return {x / mag, y / mag, z / mag};
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

Vector3& Vector3::operator-=(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;

	return *this;
}

Vector3& Vector3::operator*=(float other)
{
	x *= other;
	y *= other;
	z *= other;

	return *this;
}

Vector3& Vector3::operator/=(float other)
{
	x /= other;
	y /= other;
	z /= other;

	return *this;
}

Vector3 Vector3::operator+() const
{
	return {x, y, z};
}

Vector3 Vector3::operator-() const
{
	return {-x, -y, -z};
}

Vector3 Vector3::operator+(const Vector3& other) const
{
	return {x + other.x, y + other.y, z + other.z};
}

Vector3 Vector3::operator-(const Vector3& other) const
{
	return {x - other.x, y - other.y, z - other.z};
}

Vector3 operator*(const Vector3& vector, float scalar)
{
	return {vector.x * scalar, vector.y * scalar, vector.z * scalar};
}

Vector3 operator*(float scalar, const Vector3& vector)
{
	return {vector.x * scalar, vector.y * scalar, vector.z * scalar};
}

Vector3 operator/(const Vector3& vector, float scalar)
{
	return {vector.x / scalar, vector.y / scalar, vector.z / scalar};
}

Vector3 operator/(float scalar, const Vector3& vector)
{
	return {vector.x / scalar, vector.y / scalar, vector.z / scalar};
}
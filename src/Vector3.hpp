// Vector3.hpp
//
// A three-dimensional vector where the componenets are floats.

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <cmath>



class Vector3
{
public:
	float x;
	float y;
	float z;

public:
	// Create a vector whose components are zero.
	Vector3()
		: x{0}, y{0}, z{0}
	{
	}

	// Create a vector with the given componenet values.
	Vector3(float vx, float vy, float vz)
		: x{vx}, y{vy}, z{vz}
	{
	}

	// unit() returns a unit vector of the vector.
	Vector3 unit() const
	{
		float mag = sqrt((x * x) + (y * y) + (z * z));
		return {x / mag, y / mag, z / mag};
	}

	Vector3& operator+=(const Vector3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	Vector3& operator-=(const Vector3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	Vector3& operator*=(float other)
	{
		x *= other;
		y *= other;
		z *= other;

		return *this;
	}

	Vector3& operator/=(float other)
	{
		x /= other;
		y /= other;
		z /= other;

		return *this;
	}

	Vector3 operator+() const
	{
		return {x, y, z};
	}

	Vector3 operator-() const
	{
		return {-x, -y, -z};
	}

	Vector3 operator+(const Vector3& other) const
	{
		return {x + other.x, y + other.y, z + other.z};
	}

	Vector3 operator-(const Vector3& other) const
	{
		return {x - other.x, y - other.y, z - other.z};
	}
};

Vector3 operator*(const Vector3& vector, float scalar)
{
	return {vector.x * scalar, vector.y * scalar, vector.z * scalar};
}

Vector3 operator*(float scalar, const Vector3& vector)
{
	return {vector.x * scalar, vector.y * scalar, vector.z * scalar};
}



#endif
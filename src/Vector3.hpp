// Vector3.hpp
//
// A three-dimensional vector where the componenets are floats.

#ifndef VECTOR3_HPP
#define VECTOR3_HPP



class Vector3
{
public:
	float x;
	float y;
	float z;

public:
	// Create a vector whose components are zero.
	Vector3();

	// Create a vector with the given componenet values.
	Vector3(float vx, float vy, float vz);

	// unit() returns the unit vector of the vector.
	Vector3 unit() const;

	Vector3& operator+=(const Vector3& other);

	Vector3& operator-=(const Vector3& other);

	Vector3& operator*=(float other);

	Vector3& operator/=(float other);

	Vector3 operator+() const;

	Vector3 operator-() const;

	Vector3 operator+(const Vector3& other) const;

	Vector3 operator-(const Vector3& other) const;
};

Vector3 operator*(const Vector3& vector, float scalar);

Vector3 operator*(float scalar, const Vector3& vector);

Vector3 operator/(const Vector3& vector, float scalar);

Vector3 operator/(float scalar, const Vector3& vector);



#endif
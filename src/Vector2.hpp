// Vector2.hpp
//
// A two-dimensional vector where the components are floats.

#ifndef VECTOR2_HPP
#define VECTOR2_HPP



class Vector2
{
public:
	float x;
	float y;

public:
	// Create a vector whose components are zero.
	Vector2();

	// Create a vector with the given component values.
	Vector2(float vx, float vy);

	// unit() returns a the unit vector of the vector.
	Vector2 unit() const;


	Vector2& operator+=(const Vector2& other);

	Vector2& operator-=(const Vector2& other);

	Vector2& operator*=(float other);

	Vector2& operator/=(float other);

	Vector2 operator+() const;

	Vector2 operator-() const;

	Vector2 operator+(const Vector2& other) const;
	
	Vector2 operator-(const Vector2& other) const;
};

Vector2 operator*(const Vector2& vector, float scalar);

Vector2 operator*(float scalar, const Vector2& vector);

Vector2 operator/(const Vector2& vector, float scalar);

Vector2 operator/(float scalar, const Vector2& vector);



#endif
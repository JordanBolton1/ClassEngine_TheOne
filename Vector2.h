# pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	//Operators that will allow us to perform math functions on the vector
	Vector2 operator+(const Vector2& OtherVector);
	Vector2 operator+=(const Vector2& OtherVector);

	Vector2 operator-(const Vector2& OtherVector);
	Vector2 operator-=(const Vector2& OtherVector);

	Vector2 operator*(const float& Scalar);
	Vector2 operator*=(const float& Scalar);

	Vector2 operator/(const float& Scalar);
	Vector2 operator/=(const float& Scalar);

	//boolean operators
	bool operator==(const Vector2& OtherVector);
	bool operator!=(const Vector2& OtherVector);

	//what is the length of both the x and y
	float Length();

	void Normalise();
	Vector2 Normalised();

	//This is a quick function to return a 0,0 vector
	Vector2 Zero();

	//Coordinates stored in the vector
	float x;
	float y;
};
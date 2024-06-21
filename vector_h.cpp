#include "vector_h.h"

VECTOR::Vector::Vector()
{
	x = y = mag = ang = 0.0;
	stat = rect;
}

VECTOR::Vector::Vector(double d1, double d2, Status s)
{
	stat = s;
	if (stat == rect)
	{
		x = d1;
		y = d2;
		rect_pol();

	}
	else if(stat==pol)
	{
		mag = d1;
		ang = d2 /rad_deg;
		pol_rect();
	}
	else
	{
		std::cout << "incorrect 3rd argument.vector set to 0" << std::endl;
		x = y = mag = ang = 0.0;
		stat = rect;
     }
}
VECTOR::Vector::~Vector()
{

}
VECTOR::Vector VECTOR::Vector::operator+(const Vector& v)const
{
	Vector tmp;
	tmp = Vector(x + v.x, y + v.y);
	return tmp;
}
VECTOR::Vector VECTOR::Vector::operator-(const Vector& v)const
{
	Vector tmp;
	tmp = Vector(x - v.x, y - v.y);
	return tmp;
}
VECTOR::Vector VECTOR::Vector::operator*(const double &n)const
{
	return Vector(n * x, n * y);
}

VECTOR::Vector VECTOR::operator*(const double& n, const Vector& v)
{
	Vector tmp;
	tmp.x = n * v.x;
	tmp.y = n * v.y;
	tmp.mag = sqrt(tmp.x*tmp.x+ tmp.y*tmp.y);
	tmp.ang = atan2(tmp.y, tmp.x);
	//VECTOR::Vector::rect_pol();
	tmp.stat = v.stat;
}
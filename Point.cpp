//#include <iostream>
#include "Point.h"

//using namespace std;
//iostream과 namespace는 Point.h에 포함됨.

ostream& operator<<(ostream& out, const Point& right)
{
	out << "(" << right._x << ", " << right._y << ")"; //output 스트림에 차곡차곡 넣고
	return out; //고놈을 lv로 리턴해야 캐스케이딩 가능.
}

istream& operator>>(istream& in, Point& right) //입력문 (x1, y1) (x2, y2)
{
	in.ignore(10, '(');
	in >> right._x;
	in.ignore(10, ' ');
	in >> right._y;
	return in; //위랑 비슷함. in안에 있는걸 차곡차곡 x랑 y에 담아주고, ignore로 숫자 직전 문자까지 제거하여 숫자만 받을 수 있도록 해준다.
}

int operator*(const Point& left, const Point& right)
{
	return left._x * right._x + left._y * right._y; //조건대로 sop를 리턴. rv임.
}

Point& operator-=(Point& left, const Point& right) //p1 -= p2 캐스케이딩 가능해야함.
{
	left._x -= right._x;
	left._y -= right._y;
	return left;
}

Point operator++(Point& left, int) //postfix increment
{
	Point temp{ left }; //임시객체
	++left._x;
	++left._y;
	return temp; //캐스케이딩 불필요함. rv로 리턴. 애초에 레퍼런스 해도 임시 지역 객체라 무쓸모.
}

bool operator!=(const Point& left, const Point& right) //x1과 x2가 다르거나, y1나 y2가 다르면 1을 리턴.
{
	return (left._x != right._x || left._y != right._y);
}

bool operator<=(const Point& left, const Point& right) //left의 좌표합이 right의 좌표합보다 작거나 같을때 1을 리턴.
{
	return (left._x + left._y <= right._x + right._y);
}

Point::Point() :_x{ 0 }, _y{ 0 } {} //생성자.

Point& Point::operator++() //레퍼런스로 리턴, 매개변수가 없는걸 보니 이놈은 ++a와 같은 전위연산자.
{
	++_x;
	++_y;
	return *this; //본인을 lv로 리턴. 캐스케이딩 가능.
}

bool Point::operator==(const Point& right)
{
	return (_x == right._x && _y == right._y); //보이는 그대로.
}

Point Point::operator+(const Point& right)
{
	Point temp;
	temp._x = _x + right._x;
	temp._y = _y + right._y;
	return temp; //임시객체를 리턴. 레퍼런스로 리턴하면 안됨.
}

Point& Point::operator+=(const Point& right) //cascading 가능해야함.
{
	_x += right._x; //조건대로.
	_y += right._y;
	return *this; //본인의 레퍼런스를 리턴하여 캐스케이딩을 허용.
}

bool Point::operator>(const Point& right)
{
	return (_x + _y > right._x + right._y); //조건에 부합하면 1을 리턴. 아니면 0을 리턴.
}
//#include <iostream>
#include "Point.h"

//using namespace std;
//iostream�� namespace�� Point.h�� ���Ե�.

ostream& operator<<(ostream& out, const Point& right)
{
	out << "(" << right._x << ", " << right._y << ")"; //output ��Ʈ���� �������� �ְ�
	return out; //����� lv�� �����ؾ� ĳ�����̵� ����.
}

istream& operator>>(istream& in, Point& right) //�Է¹� (x1, y1) (x2, y2)
{
	in.ignore(10, '(');
	in >> right._x;
	in.ignore(10, ' ');
	in >> right._y;
	return in; //���� �����. in�ȿ� �ִ°� �������� x�� y�� ����ְ�, ignore�� ���� ���� ���ڱ��� �����Ͽ� ���ڸ� ���� �� �ֵ��� ���ش�.
}

int operator*(const Point& left, const Point& right)
{
	return left._x * right._x + left._y * right._y; //���Ǵ�� sop�� ����. rv��.
}

Point& operator-=(Point& left, const Point& right) //p1 -= p2 ĳ�����̵� �����ؾ���.
{
	left._x -= right._x;
	left._y -= right._y;
	return left;
}

Point operator++(Point& left, int) //postfix increment
{
	Point temp{ left }; //�ӽð�ü
	++left._x;
	++left._y;
	return temp; //ĳ�����̵� ���ʿ���. rv�� ����. ���ʿ� ���۷��� �ص� �ӽ� ���� ��ü�� ������.
}

bool operator!=(const Point& left, const Point& right) //x1�� x2�� �ٸ��ų�, y1�� y2�� �ٸ��� 1�� ����.
{
	return (left._x != right._x || left._y != right._y);
}

bool operator<=(const Point& left, const Point& right) //left�� ��ǥ���� right�� ��ǥ�պ��� �۰ų� ������ 1�� ����.
{
	return (left._x + left._y <= right._x + right._y);
}

Point::Point() :_x{ 0 }, _y{ 0 } {} //������.

Point& Point::operator++() //���۷����� ����, �Ű������� ���°� ���� �̳��� ++a�� ���� ����������.
{
	++_x;
	++_y;
	return *this; //������ lv�� ����. ĳ�����̵� ����.
}

bool Point::operator==(const Point& right)
{
	return (_x == right._x && _y == right._y); //���̴� �״��.
}

Point Point::operator+(const Point& right)
{
	Point temp;
	temp._x = _x + right._x;
	temp._y = _y + right._y;
	return temp; //�ӽð�ü�� ����. ���۷����� �����ϸ� �ȵ�.
}

Point& Point::operator+=(const Point& right) //cascading �����ؾ���.
{
	_x += right._x; //���Ǵ��.
	_y += right._y;
	return *this; //������ ���۷����� �����Ͽ� ĳ�����̵��� ���.
}

bool Point::operator>(const Point& right)
{
	return (_x + _y > right._x + right._y); //���ǿ� �����ϸ� 1�� ����. �ƴϸ� 0�� ����.
}
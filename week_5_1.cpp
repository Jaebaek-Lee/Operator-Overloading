#include <iostream>
#include "Point.h"

using namespace std;

int main() {
	Point p1, p2;
	cout << "Input 2 points: ";
	cin >> p1 >> p2;//>>연산자 안에서 문자를 좀 거를 필요가 있지 않을까?

	if (p1 == p2) cout << "p1 == p2" << endl;
	if (p1 != p2) cout << "p1 != p2" << endl;
	if (p1 > p2) cout << "p1 > p2" << endl;
	if (p1 <= p2) cout << "p1 <= p2" << endl;

	cout << endl;
	cout << "p1 + p2 = " << (p1 + p2) << endl;//더하기는 객체고
	cout << "p1 * p2 = " << (p1 * p2) << endl;//곱하기는 value이다

	cout << endl;
	p1 -= p2++; //++먼저...
	cout << "p1 -= p2++" << endl;
	++p1 += p2; //++먼저...
	cout << "++p1 += p2" << endl;
	cout << "p1 = " << p1 << endl;
}

//int a = 0;
//(a += 3) += 5;//증감연산자는 L-value로 리턴되어야함. 이놈은 "a += 3"처럼 독자적으로 쓰일 수 있어야 하니까.
//cout << a;
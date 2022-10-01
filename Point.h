#include <iostream>
#ifndef POINT_H
#define POINT_H
#pragma once

using namespace std;
//헤더파일에 iostream이랑 usingnamespace 안하면 엄청난 오류들을 맛보게 될 것.
class Point
{
	/*Why friend ??? -- << 랑 >> 는 당연하다.cout 객체 안에다가 오버로딩 함수 만들기라도 할거냐고~~
	나머지는 그냥 좌측에 L-Value가 오는 등의 상황을 위해 그렇게 한게 아닐까?*/
	friend ostream& operator<<(ostream&, const Point&);
	//캐스케이딩이 가능해야하기 때문에, 본인을 Lvalue로 리턴해줘야한다.
	//const가 붙은 이유 : cout << (p1 + p2);에서 << 우측은 Rvalue임. 이걸 받을 수 있어야한다. 다른 방법들은 전부 개손해보는 코드이다.
	//가령 const와 &를 빼서 rV를 받는다면? 복사비용이 발생하여 효율감소. 그럼 +연산자의 리턴을 참조자로(lV로) 하고 const를 뺀다면? 리턴 과정에서 메모리가 해제되는 객체를 리턴해버린다.
	//그럼 Point&&는 안되나요? - 그럼 좌측값을 못받잖아!
	friend istream& operator>>(istream&, Point&);
	//cin >> p1 >> p2;cin안의 스트림에서 빼내고 p1 p2에 삽입. 캐스케이딩이 가능해야함. 본인을 리턴한다.
	//객체 내부의 값을 수정해줘야하기 때문에 const가 붙지 않으며, &가 필요하다(안하면 입력값 반영이 지역변수로 들어감).
	friend int operator*(const Point&, const Point&);
	//조건을 보면, p1 * p2 = x1 * x2 + y1 * y2라는 하나의 값이다. 두 개의 값이 포함된 객체가 아니다. 그래서 그냥 int타입으로 리턴.
	//이놈을 섞은 p1 + p2 * p2같은게 생기면 p1 + int를 받을 수 있는 함수를 또 만들어야겠지. 지금 만든건 r벨류 객체를 받는 +함수 뿐이다. but 그런 입력은 없으니 추가로 만들지는 않겠음.
	friend Point& operator-=(Point&, const Point&);
	//복합대입연산자. 좌측은 항상 Lv라서 객체를 참조하고, 우측에는 뭐가올지 모르니까 그냥 const를 붙임.
	//이놈은 캐스케이딩 되어야함. 레퍼런스 붙여서 lv로 리턴. ex) rv += 3이런거 안되니까.
	friend Point operator++(Point&, int);
	//후위 연산자. 임시객체를 생성하고 본인을 +1한 뒤 임시객체를 리턴한다.(참조로 리턴하면 무의미해짐. 곧 메모리 해제될 지역객체 참조해서 뭐할라고?)
	//그리고 후위 연산자는 캐스케이딩이 불가능하다. rv로 리턴해야함. 본질을 따르자. int는 전위연산자와 구분하기 위한 더미 매개변수.
	friend bool operator!=(const Point&, const Point&);
	//비교연산자... 좌항이나 우항에 lvalue가 올 수도, rvalue가 올 수도 있으니 const를 붙여줬다.
	friend bool operator<=(const Point&, const Point&);
	//위와 같다.
public:
	Point();
	Point& operator++();
	//전위 연산자. ++a; 그냥 호출한 객체 본인의 변수를 +1해주고 본인을 리턴한다. 따라서 따로 매개변수가 필요없음. 그리고 lv로 리턴해야 캐스케이딩 가능.
	//++(5) 같은거 안되니까.
	bool operator==(const Point&);
	//직접 호출한거라... 매개변수는 하나만 필요하다.
	Point operator+(const Point&);
	//안에서 더한 값을 넣은 임시객체를 리턴해주기 때문에 value로 리턴한다. 이걸 레퍼런스로 하면 메모리 망한다. 그렇다고 *this를 리턴하면 +가 여러개일때 객체의 값이 바뀌는 비극 발생.
	Point& operator+=(const Point&);
	//멤버이고, 좌항에는 lv만 오니까 굳이 신경쓸 필요 없이 우항만 매개변수에. 우항은 l or r
	//a += 3orb 캐스케이딩 가능하게 lv
	bool operator>(const Point&);
	//멤버로 하라고 하셨으니 좌항엔 객체일 것. 우항만 넣어주고, 이놈은 r or l

private:
	int _x;
	int _y;
};

#endif

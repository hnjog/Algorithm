#include<iostream>

using namespace std;

struct pos
{
	int y, x;
};

struct square
{
	int miny, minx;
	int maxy, maxx;
};

// 기준 a로 잡을테니 바꿔가면서 결정하기
int check(square& a, square& b)
{
	// x 나 y가 너무 멀어서 아예 겹칠 가능성이 없다
	if (a.maxx < b.minx ||
		a.minx > b.maxx ||
		a.maxy < b.miny ||
		a.miny > b.maxy)
	{
		return 4;
	}

	// 외부 한점씩만 겹치는 경우
	if ((a.maxx == b.minx &&
		a.maxy == b.miny) ||
		(a.minx == b.maxx &&
			a.maxy == b.miny) ||
		(a.maxx == b.minx &&
			a.miny == b.maxy) ||
		(a.minx == b.maxx &&
			a.miny == b.maxy))
	{
		return 3;
	}

	// 한면이 겹치는 경우
	if ((a.maxx == b.minx &&
		a.maxy > b.miny) ||
		(a.maxx == b.minx &&
			a.miny < b.maxy) ||
		(a.minx == b.maxx &&
			a.maxy > b.miny) ||
		(a.minx == b.maxx &&
			a.miny < b.maxy) ||
		(a.maxy == b.miny &&
			a.maxx > b.minx) ||
		(a.maxy == b.miny &&
			a.minx < b.maxx) ||
		(a.miny == b.maxy &&
			a.maxx > b.minx) ||
		(a.miny == b.maxy &&
			a.minx < b.maxx))
	{
		return 2;
	}

	return 1;
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		square s1, s2;
		cin >> s1.minx >> s1.miny >> s1.maxx >> s1.maxy;
		cin >> s2.minx >> s2.miny >> s2.maxx >> s2.maxy;

		cout << char('a' + check(s1, s2) - 1) << '\n';
	}

	return 0;
}
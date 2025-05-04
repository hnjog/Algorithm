#include<iostream>
#include<vector>
#include<string>

using namespace std;

int h, w, maxV;
bool alphaBets[26];

void recur(vector<string>& map,int nowY, int nowX,int nowCount);

void func(vector<string>& map)
{
	recur(map, 0, 0,1);
}

void recur(vector<string>& map, int nowY, int nowX, int nowCount)
{
	if (nowY < 0 || nowX < 0 ||
		nowY >= h || nowX >= w)
		return;

	int v = int(map[nowY][nowX] - 'A');

	if (alphaBets[v])
		return;

	alphaBets[v] = true;
	if (nowCount > maxV)
		maxV = nowCount;

	recur(map,nowY + 1, nowX, nowCount + 1);
	recur(map,nowY - 1, nowX, nowCount + 1);
	recur(map,nowY, nowX + 1, nowCount + 1);
	recur(map,nowY, nowX - 1, nowCount + 1);

	alphaBets[v] = false;
}

int main()
{
	cin >> h >> w;

	vector<string> vec;

	for (int i = 0; i < h; i++)
	{
		string temp;
		cin >> temp;
		vec.push_back(temp);
	}

	func(vec);
	cout << maxV;
}
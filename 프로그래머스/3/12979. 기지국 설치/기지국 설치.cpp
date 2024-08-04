#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int tempPos = 0;

	for (int s : stations)
{
	s--;
	int tempL = s - w - tempPos;
	tempPos = s + w + 1;

	if (tempL > 0)
	{
		int wide = (w * 2 + 1);
		int v = tempL / wide;
		if (tempL % wide != 0)
			v++;

		answer += v;
	}
}

if (tempPos <= n)
{
	int tempL = n - tempPos;

	if (tempL > 0)
	{
		int wide = (w * 2 + 1);
		int v = tempL / wide;
		if (tempL % wide != 0)
			v++;

		answer += v;
	}
}

	return answer;
}
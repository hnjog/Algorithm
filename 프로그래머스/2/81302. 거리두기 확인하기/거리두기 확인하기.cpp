#include <string>
#include <vector>

using namespace std;

struct pos
{
	int y, x;
};

bool CheckDistance(const pos& a, const pos& b, const vector<string>& map)
{
	int minx = a.x;
	int maxx = b.x;

	if (maxx < minx)
		swap(maxx, minx);

	int miny = a.y;
	int maxy = b.y;

	if (maxy < miny)
		swap(maxy, miny);

	int dis = maxy - miny + maxx - minx;

	if (dis == 1)
		return false;

	if (dis > 2)
		return true;

	if (maxy == miny)
	{
		if (map[miny][minx + 1] == 'X')
			return true;

		return false;
	}

	if (maxx == minx)
	{
		if (map[miny + 1][minx] == 'X')
			return true;

		return false;
	}

	// 대각선 상황들
	if (maxx == a.x)
	{
		if (maxy == a.y)
		{
			if (map[miny + 1][minx] == 'X' &&
				map[miny][minx + 1] == 'X')
				return true;
		}
		else // / 상황
		{
			// a가 위쪽
			if (map[a.y][b.x] == 'X' &&
				map[b.y][a.x] == 'X')
				return true;
		}
	}
	else // a가 작은 쪽 x
	{
		if (maxy == b.y) // b가 y가 크다면 위와 동일한 \ 상황임
		{
			if (map[miny + 1][minx] == 'X' &&
				map[miny][minx + 1] == 'X')
				return true;
		}
		else // / 상황
		{
			// a는 아래쪽
			if (map[b.y][a.x] == 'X' &&
				map[a.y][b.x] == 'X')
				return true;
		}
	}

	return false;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (auto& p : places)
	{
		vector<pos> pla;
		int h = p.size();
		int w = p[0].size();
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (p[i][j] == 'P')
					pla.push_back({ i,j });
			}
		}

		int size = answer.size();
		bool isRight = true;
		for (int i = 0; i < pla.size(); i++)
		{
			for (int j = i + 1; j < pla.size(); j++)
			{
				if (CheckDistance(pla[i], pla[j], p) == false)
				{
					isRight = false;
					break;
				}
			}
			if (isRight == false)
				break;
		}

		if (isRight)
			answer.push_back(1);
		else
			answer.push_back(0);

	}

	return answer;
}
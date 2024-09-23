#include <string>
#include <vector>
#include<map>
#include<math.h>

using namespace std;

bool check(const vector<string>& place)
{
	map<pair<int, int>, bool> ps;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (place[i][j] == 'P')
			{
				ps.insert({ { i,j }, false });
			}
		}
	}

	for (auto it1 = ps.begin(); it1 != ps.end(); it1++)
	{
		for (auto it2 = it1; it2 != ps.end(); it2++)
		{
			if (it1 == it2)
				continue;

			// 이미 검사함
			if (it1->second)
				continue;

			const pair<int, int>& oPos = it1->first;
			const pair<int, int>& tPos = it2->first;

			int yDis = abs(oPos.first - tPos.first);
			int xDis = abs(oPos.second - tPos.second);

			// 이 공간은 잘못됬음
			if (xDis + yDis == 1)
				return false;

			// 거리 3 이상이면 조건 만족한다
			if (xDis + yDis >= 3)
				continue;

			// 거리가 2일때
			// 그 사이에 X로 막혀있는지를 확인하기

			// 1자형으로 떨어져 있는 경우
			if (xDis == 0 || yDis == 0)
			{
				if (xDis == 0) // |
				{
					int yValue = (oPos.first + tPos.first) / 2;
					if (place[yValue][oPos.second] != 'X')
					{
						return false;
					}
				}
				else // -
				{
					int xValue = (oPos.second + tPos.second) / 2;
					if (place[oPos.first][xValue] != 'X')
					{
						return false;
					}
				}
			}
			else // 대각선
			{
				int xValue = oPos.second - tPos.second;
				int yValue = oPos.first - tPos.first;

				if (xValue < 0)
				{
					if (yValue < 0)
					{
						// x와 y 값 모두 tPos가 큰 상황
						if (place[tPos.first][oPos.second] != 'X' ||
							place[oPos.first][tPos.second] != 'X')
						{
							return false;
						}
					}
					else
					{
						// x값은 tPos가, y값은 oPos가 큰 상황
						if (place[oPos.first][tPos.second] != 'X' ||
							place[tPos.first][oPos.second] != 'X')
						{
							return false;
						}
					}
				}
				else // x값이 oPos가 더 크다
				{
					if (yValue < 0)
					{
						// x값은 oPos가, y값은 tPos가 큰 상황
						if (place[oPos.first][tPos.second] != 'X' ||
							place[tPos.first][oPos.second] != 'X')
						{
							return false;
						}
					}
					else
					{
						// x와 y 값 모두 oPos가 큰 상황
						if (place[oPos.first][tPos.second] != 'X' ||
							place[tPos.first][oPos.second] != 'X')
						{
							return false;
						}
					}
				}
			}
		}
		it1->second = true;
	}

	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (const auto& place : places)
	{
		if (check(place))
		{
			answer.push_back(1);
		}
		else
		{
			answer.push_back(0);
		}
	}

	return answer;
}
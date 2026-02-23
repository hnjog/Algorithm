#include<iostream>
#include<vector>
#include<set>

using namespace std;

int maxV = 0;

int getDis(int y1, int y2, int x1, int x2)
{
	return abs(y1 - y2) + abs(x1 - x2);
}

void GetV(const vector<vector<int>>& originMap, vector<int>& arv, int d, int ac)
{
	int count = 0;

	vector<vector<int>> gm = originMap;

	// 궁수 위치에서 가장 가까운 녀석들을 이번턴 제거
	int n = gm.size();
	int m = gm[0].size();

	while (ac > 0)
	{
		set<pair<int, int>> pus;

		for (int a = 0; a < 3; a++)
		{
			int ary = n;
			int arx = arv[a];

			int maxDis = d;
			pair<int, int> dd = { -1,-1 };

			bool bFind = false;
			// 위쪽에서 왼쪽 기준으로 함
			// '가장 가까운' 녀석을 찾아야 함 -> 여러개라면 가장 왼쪽의 녀석을 공격함
			int l = max(n - d, 0);
			for (int i = n - 1; i >= l; i--)
			{
				for (int j = 0; j < m; j++)
				{
					if (gm[i][j] == 1)
					{
						int dis = getDis(i, ary, j, arx);
						if (dis < maxDis)
						{
							dd = { i,j };
							
							maxDis = dis;
							bFind = true;
						}
						else if (dis == maxDis)
						{
							if (bFind == false ||
								j < dd.second)
							{
								dd = { i,j };
								bFind = true;
							}
						}
					}
					if (maxDis == 1 && bFind)
						break;
				}
				if (maxDis == 1 && bFind)
					break;
			}

			if (bFind)
			{
				pus.insert(dd);
			}
		}

		for (auto& p : pus)
		{
			count++;
			ac--;
			gm[p.first][p.second] = 0;
		}

		// 위치 땡기기
		for (int i = n - 1; i > 0; i--)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == n - 1 && gm[i][j] == 1)
					ac--;

				gm[i][j] = gm[i - 1][j];
			}
		}

		for (int j = 0; j < m; j++)
		{
			gm[0][j] = 0;
		}
	}

	if (count > maxV)
		maxV = count;
}

void Recur(const vector<vector<int>>& originMap, vector<int>& arv, int c, int d, int ac)
{
	if (c >= 3)
	{
		GetV(originMap, arv, d, ac);
		return;
	}

	if (arv.empty())
	{
		for (int i = 0; i < originMap[0].size(); i++)
		{
			arv.push_back(i);
			Recur(originMap, arv, c + 1, d, ac);
			arv.pop_back();
		}
	}
	else
	{
		int v = arv.back();

		for (int i = v + 1; i < originMap[0].size(); i++)
		{
			arv.push_back(i);
			Recur(originMap, arv, c + 1, d, ac);
			arv.pop_back();
		}
	}
}

int main()
{
	int n, m, d;
	cin >> n >> m >> d;

	vector<vector<int>> maps(n, vector<int>(m, 0));

	int ac = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 1)
				ac++;
		}
	}

	/*
		궁수는 총 m개의 자리에 총 3개 배치 가능함
		궁수는 맵 밖의 n+1 위치에 있는 성에 배치 가능

		사정거리 d 에서 가장 가까운 것을 공격
		+ 여러개라면 가장 왼쪽

		또한, '겹칠'수 있음

		적들은 y로 하나씩 이동하며, 맵을 벗어나면 제거됨

		적들이 모두 제거된 경우,
		게임 종료

		궁수를 적절히 배치하였을때
		적을 가장 많이 '궁수로 제거하는 수'를 문제

	*/

	vector<int> arv;

	Recur(maps, arv, 0, d, ac);

	cout << maxV;

	return 0;
}
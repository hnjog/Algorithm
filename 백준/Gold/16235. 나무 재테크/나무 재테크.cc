#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int dirY[8] = { -1,-1,-1,0,0,1,1,1 };
const int dirX[8] = { -1,0,1,-1,1,-1,0,1 };

class Area
{
protected:
	int y, x;
	int nowVal;
	int wVal;
	deque<int> nFTQ; // 아직 못 먹은 나무들 - 나이별 오름차순
	deque<int> fTQ; // 먹은 나무들 (봄 끝난 이후, nTFQ로 다시 값을 준다)
	vector<int> deadTreeVec;

public:
	Area(int y, int x, int val)
		:y(y),x(x), wVal(val)
	{
		nowVal = 5;
	}

	// 나무 심기
	void setTree(int age)
	{
		nFTQ.push_front(age);
	}

	int getTreeCount()
	{
		return nFTQ.size();
	}

	void spring()
	{
		while (nFTQ.empty() == false)
		{
			int n = nFTQ.front();
			nFTQ.pop_front();

			if (nowVal < n)
			{
				deadTreeVec.push_back(n);
			}
			else
			{
				nowVal -= n;
				fTQ.push_back(n + 1);
			}
		}

		nFTQ = fTQ;
		fTQ.clear();
	}

	void summer()
	{
		for (int d : deadTreeVec)
		{
			nowVal += (d / 2);
		}

		deadTreeVec.clear();
	}

	void fall(vector<vector<Area>>& maps)
	{
		int r = maps.size();
		int c = maps[0].size();

		int n = nFTQ.size();
		for (int i = 0; i < n; i++)
		{
			int v = nFTQ.front();
			nFTQ.pop_front();

			if (v % 5 == 0)
			{
				for (int d = 0; d < 8; d++)
				{
					int ny = y + dirY[d];
					int nx = x + dirX[d];

					if (ny < 0 || ny >= r ||
						nx < 0 || nx >= c)
						continue;

					maps[ny][nx].setTree(1);
				}
			}

			nFTQ.push_back(v);
		}
	}

	void winter()
	{
		nowVal += wVal;
	}

};

int main()
{
	/*
		k년이 지난후 살아있는 나무의 개수 구하기

		1년마다 벌어지는 일
		봄 : 나무가 자신의 나이만큼 양분 먹고, 나이 1 증가
			 다만 하나의 칸에 여러 나무 존재시, 어린 나무부터 양분 먹음
			 양분을 못먹는 나무는 사망

		여름 : 죽은 나무가 양분으로 변하여 나이 / 2 가 나무가 있던 칸에 추가됨

		가을 : 나이가 5의 배수인 나무가 번식
			 번식하는 나무는 자신 위치 기준 8방향 번식 (번식한 나무의 나이는 1)

		겨울 : 로봇이 지정된 양의 양분을 각 칸에 부여함

	*/

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<Area>> maps(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int t;
			cin >> t;

			maps[i].emplace_back(Area(i, j, t));
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> y >> x >> z;
		maps[y-1][x-1].setTree(z);
	}

	for (int i = 0; i < k; i++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maps[i][j].spring();
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maps[i][j].summer();
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maps[i][j].fall(maps);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maps[i][j].winter();
			}
		}
	}

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			count += maps[i][j].getTreeCount();
		}
	}

	cout << count;

	return 0;
}
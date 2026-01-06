#include<iostream>
#include<vector>

using namespace std;

int main()
{
	/*
		주어지는 플로이드 연결된 배열을 보고

		맵에 연결된 최단 루트들의 합을 구하는 문제
		(즉, 플로이드-워셜 전개 후의 값을 보고,
		전개 전에 주어진 edge들의 비용 합을 보는 문제)

		이전에 보았던

		dist[i] + w == dist[j]
		-> w를 가지는 간선은 최소 비용에 포함

		이거랑 비슷해보이는데...

		dist[i][k] + dist[k][j] == dist[i][j]?

		일단 생각해볼 점

		원래 플로이드-워셜의 정의
		dist[i][j] = i->j 까지의 최단거리

		그렇기에
		i -> j 사이에서
		k를 경유하면 더 빠른가?에 대하여
		다음과 같은 체크
		dist[i][k] + dist[k][j] > dist[i][j]

		이런식으로 최단거리 갱신

		그렇기에
		dist[i][k] + dist[k][j] == dist[i][j]

		이 결과가 나온다면
		dist[i][j] 는 '원래 있는 도로'가 아니며,

		다른 도시를 경유하는 도로
		(아마 맞지 않을까? 비용이 우연히 같은 경우에 대한 처리?)
		(하지만 k가 i,j 양쪽에 경로가 존재하니 맞지 않음? - 그것도 '최단 경로'이므로)

		풀이법?
		k->i->j for 돌리면서

		dist[i][k] + dist[k][j] == dist[i][j] 를 검사?

		그냥 vector<bool> 같은거 만들어서
		저게 체크되는 애들은 false처리 하기?

		이후, true 인 녀석들만 값에 넣어준다던가?

		-1 처리에 대하여
		- 반드시 플로이드-워셜의 결과물이 '들어온다'는 보장이 없다는 뜻임!

		따라서


	*/

	int n;
	cin >> n;

	vector<vector<int>> maps(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> maps[i][j];

	vector<vector<bool>> origin(n, vector<bool>(n, true));

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == k)
				continue;

			for (int j = 0; j < n; j++)
			{
				if (i == j || j == k)
					continue;

				if (maps[i][k] + maps[k][j] == maps[i][j])
				{
					origin[i][j] = false;
				}
				else if (maps[i][k] + maps[k][j] < maps[i][j])
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (origin[i][j])
			{
				ret += maps[i][j];
			}
		}
	}


	cout << ret;

	return 0;
}
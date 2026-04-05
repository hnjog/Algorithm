#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pii;

struct Compare
{
	bool operator()(const pii& a, const pii& b)
	{
		if (a.second == b.second)
			return a.first > b.first;

		return a.second > b.second;
	}
};

int main()
{
	/*
		1번 내용은 임의의 접근이 가능해야 함 (vector 등)
		2번 내용은 가장 작은 값 + 같으면 인덱스 작은거로 인덱스 출력

		단순히 2개의 자료구조에 동일한 값을 사용하는 것은 별로일듯함
		- vector + pq or map
		  1로인해 바뀐 내용이 2에 적용되어야 하는데, 그러면 결국 순회해야 함

		고민할 점
		map을 통해 가능한가?
		- map<int,pair<int,int> 를 통해 인덱스와 인덱스 + 값 저장(인덱스를 추가 저장하는 이유는 2번의 비교를 위해)

		반드시 바로 동기화할 필요 없음

		1번에서
		값을 바꾼후 pq에 다시 집어넣음

		2번에서 top로 꺼냈을때,
		해당 vec가 유효한지를 체크하고
		맞다면 그대로 출력, 아니라면 pop하면 됨

	*/

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> vec(n + 1, 0);
	priority_queue<pii, vector<pii>, Compare> pq;

	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
		pq.push({ i,vec[i] });
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int q;
		cin >> q;

		if (q == 1)
		{
			int a, b;
			cin >> a >> b;
			vec[a] = b;
			pq.push({ a,b });
		}
		else
		{
			while (pq.empty() == false)
			{
				int idx = pq.top().first;
				int v = pq.top().second;

				if (v == vec[idx])
				{
					cout << idx << '\n';
					break;
				}
				pq.pop();
			}
		}
	}


	return 0;
}
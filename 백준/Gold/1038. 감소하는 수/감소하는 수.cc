#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

char vs[10] = { '0','1','2','3','4','5','6','7','8','9'};

struct Compare
{
	bool operator()(string& a, string& b)
	{
		if (a.size() == b.size())
			return a > b;
		return a.size() > b.size();
	}
};

int main()
{
	int n;
	cin >> n;

	// 백트래킹
	// 
	// 1 0
	// 2 1,0
	// 
	// ...
	// 
	// 이런식으로
	// 앞자리부터 나아가는 방식으로 구할 수 있음
	// 
	// 고민할점
	// 
	// 재귀 구현 방식
	// - string을 써야 하나?
	// - 1,2,3,4,5,6,7,8,9 를 어떻게 붙이지?
	// 
	// 음...
	// nowCount -> n 까지 진행
	// 
	// 종료 조건?
	// nowCount == n
	// 
	// nowcount++;
	// 
	// for(int i = 1; i< 가장 앞자리 수;i++)
	// {
	//    재귀(현재 수 * 10 + i)
	// }
	// 
	//

	string temp = ""; // 역순으로 쌓은후 마지막에 뒤집기
	int nowC = -1;
	int idx = 1;

	// 오히려 queue 같은 bfs 쪽으로 푸는게 더 좋을듯??

	priority_queue<string, vector<string>, Compare> pq;
	pq.push(temp);

	while (pq.empty() == false)
	{
		string t = pq.top();
		pq.pop();

		if (nowC == n)
		{
			cout << t;
			return 0;
		}

		nowC++;

		if (t.empty())
		{
			for (int i = 0; i < 10; i++)
			{
				pq.push(std::move(vs[i] + t));
			}
		}
		else
		{
			int b = t[0] - '0';
			for (int i = b + 1; i < 10; i++)
			{
				pq.push(std::move(vs[i] + t));
			}
		}
	}
	
	cout << -1;

	return 0;
}
#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

/*
	트리용 구조체를 만들면 될듯
	다만, map을 통해 자동 정렬하게 함

	출력 및 입력 시 depth를 고려해야 함

	포인터를 고려하거나 map 에 대한 고려가 필요해 보임

	입력 시의 고려 사항
	- Depth를 통하여 입력 값을 받아야 함


	출력 시의 고려 사항
	- 현재 자기자신 출력 이후
	  먼저 자식들의 print 함수를 호출함
*/

struct TreeNode
{
	map<string, TreeNode> tm;
	string now;

	void input(int depth, vector<string>& vec)
	{
		now = vec[depth];

		if (depth < vec.size() - 1)
		{
			tm[vec[depth + 1]].input(depth + 1, vec);
		}
	}

	void print(int height)
	{
		string t;
		for (int i = 0; i < height; i++)
		{
			t.push_back('-'); 
			t.push_back('-');
		}
		cout << t << now << '\n';
		if (tm.empty())
			return;

		for (auto& p : tm)
		{
			p.second.print(height + 1);
		}
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	map<string, TreeNode> tmap;

	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;

		vector<string> vc(k);

		for (int j = 0; j < k; j++)
		{
			cin >> vc[j];
		}

		tmap[vc[0]].input(0, vc);
	}


	for (auto& p : tmap)
	{
		p.second.print(0);
	}

	return 0;
}
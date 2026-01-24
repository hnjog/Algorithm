#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

struct infos
{
	int l, r, c;
};

bool SortedCheck(vector<int>& arr)
{
	int n = arr.size();

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}

struct datas
{
	vector<int> arr;
	int cost;
};

struct Compare
{
	bool operator()(datas& a, datas& b)
	{
		return a.cost > b.cost;
	}
};

int getV(const vector<int>& originArr, vector<infos>& iv)
{
	priority_queue<datas, vector<datas>, Compare> pq;

	map<vector<int>,int> arm;

	pq.push({ originArr, 0 });
	arm[originArr] = 0;

	while (pq.empty() == false)
	{
		vector<int> nowArr = pq.top().arr;
		int nowc = pq.top().cost;
		pq.pop();

		if (SortedCheck(nowArr))
		{
			return nowc;
		}

		for (infos& i : iv)
		{
			int a = i.l;
			int b = i.r;
			int c = i.c + nowc;
			vector<int> copyArr = nowArr;
			swap(copyArr[a], copyArr[b]);

			if (arm.find(copyArr) != arm.end())
			{
				if(arm[copyArr] <= c)
					continue;
			}

			arm[copyArr] = c;
			pq.push({ copyArr,nowc + i.c });
		}
	}

	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arrs(n);
	for (int i = 0; i < n; i++)
		cin >> arrs[i];

	int m;
	cin >> m;

	vector<infos> iv(m);
	for (int i = 0; i < m; i++)
	{
		cin >> iv[i].l >> iv[i].r >> iv[i].c;
		iv[i].l--;
		iv[i].r--;
	}

	cout << getV(arrs, iv);

	return 0;
}
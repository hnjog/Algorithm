#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

void recur(const vector<int>& nums, vector<int>& selected,unordered_set<int>& selectIdx,int m)
{
	int count = selected.size();
	if (count == m)
	{
		for (int v : selected)
			cout << v << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (selectIdx.find(i) != selectIdx.end())
			continue;

		selected.push_back(nums[i]);
		selectIdx.insert(i);
		recur(nums, selected, selectIdx, m);
		selected.pop_back();
		selectIdx.erase(i);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> vec(n);

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		vec[i] = t;
	}

	sort(vec.begin(), vec.end());
	vector<int> selected;
	unordered_set<int> selectIdx;
	recur(vec, selected, selectIdx, m);

	return 0;
}
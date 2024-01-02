#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
	int a, b;
	cin >> a >> b;

	vector<int> valVec;

	valVec.clear();
	
	int temp;
	for (int i = 0; i < a + b; i++)
	{
		cin >> temp;
		valVec.emplace_back(temp);
	}

	sort(valVec.begin(), valVec.end());

	for (auto com : valVec)
	{
		cout << com << " ";
	}

	return 0;
}
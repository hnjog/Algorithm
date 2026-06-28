#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void Cycle(vector<int>& arr)
{
	queue<int> q;
	for (int a : arr)
		q.push(a);

	int i = 1;

	while (true)
	{
		int f = q.front();
		q.pop();

		if (f - i <= 0)
		{
			q.push(0);
			break;
		}

		q.push(f - i);
		i++;
		if (i > 5)
			i = 1;
	}

	for (int i = 0; i < 8; i++)
	{
		arr[i] = q.front();
		q.pop();
	}
}

int main(int argc, char** argv)
{
	int test_case;
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int n;
		cin >> n;

		vector<int> arr(8);
		for (int i = 0; i < 8; i++)
			cin >> arr[i];

		Cycle(arr);

		cout << '#' << n;
		for (int a : arr)
			cout << ' ' << a;
		cout << '\n';
	}
	return 0;
}
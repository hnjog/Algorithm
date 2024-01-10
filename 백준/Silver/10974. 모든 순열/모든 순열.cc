#include<iostream>
#include<memory.h>
#include<vector>

using namespace std;

int n;
void dfs(bool visited[], int point, vector<int>& buf)
{
	if (point == n)
	{
		for (auto a : buf)
		{
			cout << a << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == true)
			continue;

		visited[i] = true;
		buf.push_back(i + 1);
		dfs(visited, point + 1,buf);
		buf.pop_back();
		visited[i] = false;
	}

}

int main()
{
	cin >> n;
	bool* visited = new bool[n];
	memset(visited, 0, sizeof(bool) * n);
	vector<int> buf;
	buf.clear();

	dfs(visited, 0,buf);

	delete[] visited;
	return 0;
}
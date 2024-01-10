#include<iostream>
#include<unordered_set>
#include<memory.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 0, m = 0;
	unordered_set<int> cards;
	int* answers;

	cin >> n;

	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		cards.insert(temp);
	}

	cin >> m;
	answers = new int[m];
	memset(answers, 0, sizeof(int) * m);

	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		if (cards.find(temp) != cards.end())
		{
			answers[i] = 1;
		}
	}

	for (int i = 0; i < m; i++)
	{
		cout << answers[i] << " ";
	}

	delete[] answers;
	return 0;
}
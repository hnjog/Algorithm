#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

void Func(unordered_set<char>& us, int n)
{
	string str = to_string(n);

	for (char c : str)
		us.insert(c);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		unordered_set<char> us;

		int n;
		cin >> n;
		int idx = 0;

		while (us.size() < 10)
		{
			idx++;
			Func(us, n * idx);
		}

		cout << '#' << test_case << ' ' << idx * n << '\n';
	}
	return 0;
}
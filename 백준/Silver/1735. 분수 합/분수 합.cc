#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n1, n2, m1, m2;
	cin >> n1 >> n2 >> m1 >> m2;

	int s1 = n1 * m2 + n2 * m1;
	int s2 = n2 * m2;
	int l = s1 / 2;

	for (int i = 2; i < l; i++)
	{
		if (s1 % i == 0 && s2 % i == 0)
		{
			s1 /= i;
			s2 /= i;
			i--;
		}
	}

	cout << s1 << " " << s2;
}
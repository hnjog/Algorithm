#include<string>
#include<iostream>
#include<set>

using namespace std;

int main()
{
	int n;
	cin >> n;

	set<string> chongSet;
	chongSet.insert("ChongChong");
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;

		if (chongSet.find(a) != chongSet.end() ||
			chongSet.find(b) != chongSet.end())
		{
			chongSet.insert(a);
			chongSet.insert(b);
		}
	}

	cout << chongSet.size();
}
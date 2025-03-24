#include<iostream>
#include<vector>
#include<math.h>
#include <iomanip>

using namespace std;

typedef pair<long long, long long> pii;

int main()
{
	int n;
	vector<pii> vec;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long t1, t2;
		cin >> t1 >> t2;
		vec.push_back({ t1,t2 });
	}

	// 쇼팽 사용하려면 마지막 점이 첫점과 같아야 하므로
	vec.push_back(vec[0]);

	long double sum = 0.0;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		sum += (vec[i].first * vec[i + 1].second) - (vec[i].second * vec[i + 1].first);
	}

	sum = abs(sum) / 2.0;

	sum = round(sum * 100.0) / 100.0;

	cout << fixed << setprecision(1) << sum;

}
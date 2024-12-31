#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
	int low = 0;
	int high = 200000;
	int cSize = cores.size();
	if (n <= cSize)
		return n;

	while (low + 1 < high)
	{
		int mid = (low + high) / 2;
		int cnt = cSize;

		for (int i = 0; i < cSize; i++)
			cnt += mid / cores[i];

		if (cnt < n)
			low = mid;
		else
			high = mid;
	}

	int cnt = cSize;

	for (int i = 0; i < cSize; i++)
		cnt += low / cores[i];

	for (int i = 0; i < cSize; i++)
	{
		if ((low + 1) % cores[i] == 0)
			cnt++;

		if (cnt == n)
			return i + 1;

	}

	return 0;
}
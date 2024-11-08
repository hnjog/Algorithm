#include<algorithm>

using namespace std;

int getMax(int w, int b)
{
	if (w == b)
		return w;

	int minV = min(w, b);

	int ret = 1;

	for (int i = 2; i <= minV; i++)
	{
		if (w % i == 0 && b % i == 0)
		{
			ret = i;
		}
	}

	return ret;
}

long long solution(int w, int h) {
	long long answer = (long long)w * h - (w + h - getMax(w,h));

	return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
	int answer = 0;
	sort(people.begin(), people.end());

	int pSize = people.size();
	int lastJ = pSize - 1;

	for (int i = 0; i <= lastJ; i++)
	{
		while (people[i] + people[lastJ] > limit &&
			lastJ > i)
		{
			// 어차피 정렬하였기에, 가장 작은값도 합쳐서 limit를 넘어버리면 무조건
			// 혼자서 보트 타야 하기에
			answer++;
			lastJ--;
		}

		answer++;
        if (people[i] + people[lastJ] <= limit)
	        lastJ--;
	}

	return answer;
}
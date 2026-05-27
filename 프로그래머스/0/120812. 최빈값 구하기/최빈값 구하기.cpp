#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> _array) {
    	int answer = 0;

	int iArraySize = _array.size();

	if (iArraySize == 0)
		return -1;

	sort(_array.begin(), _array.end());

	int iCurrentComponent = _array[0];	// 현재 요소
	int iCurrentCount = 1;				// 현재 요소의 개수

	int iMaxComponent = iCurrentComponent;	// 가장 큰 요소
	int iMaxCount = iCurrentCount;			// 가장 큰 요소의 개수

	for (int i = 1; i < iArraySize;i++)
	{
		// 현재 숫자가 현재 요소와 같다면
		if (iCurrentComponent == _array[i])
		{
			iCurrentCount++;

			if (iMaxCount == iCurrentCount) // 총 요소가 현재 요소와 같은 상황이다
			{
				iMaxComponent = -1;
			}
			else if (iMaxCount < iCurrentCount)
			{
				iMaxCount = iCurrentCount;
				iMaxComponent = iCurrentComponent;
			}
		}
		else
		{
			iCurrentComponent = _array[i];
			iCurrentCount = 1;
		}

	}

	answer = iMaxComponent;
	if (iMaxCount == 1 && iArraySize != 1)
		answer = -1;

	return answer;
}
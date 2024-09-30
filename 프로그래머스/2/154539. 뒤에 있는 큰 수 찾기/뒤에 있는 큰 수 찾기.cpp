#include <vector>
#include<stack>

using namespace std;

typedef pair<int, int> pii;

vector<int> solution(vector<int> numbers) {
	const int nSize = numbers.size();
	vector<int> answer(nSize, -1);

	// 자기 값과 인덱스 넣어놓을 생각
	stack<pii> st;

	for (int i = 0; i < nSize; i++)
	{
		int nowNum = numbers[i];
		while (st.empty() == false)
		{
			auto p = st.top();
			if (nowNum > p.first)
			{
				st.pop();
				answer[p.second] = numbers[i];
			}
			else
			{
				break;
			}
		}

		st.push({ nowNum,i });
	}

	return answer;
}
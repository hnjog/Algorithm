#include <string>
#include <stack>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

// "00:00" -> 계산
int getTimeValue(string str)
{
	string str1(str.begin(), str.begin() + 2);
	string str2(str.begin() + 3, str.begin() + 5);

	int ret = stoi(str1) * 60;
	ret += stoi(str2);

	return ret;
}

vector<string> solution(vector<vector<string>> plans) {
	sort(plans.begin(), plans.end(), [](const vector<string>& a, const vector<string>& b) {
		int a1v = getTimeValue(a[1]);
		int b1v = getTimeValue(b[1]);

		return a1v < b1v;
		});

	struct node
	{
		string task;
		int timeValue;
		int progressRemain;
	};

	vector<string> answer;
	stack<node> st;
	queue<node> q;
	for (vector<string> v : plans)
	{
		q.push({ v[0],getTimeValue(v[1]),stoi(v[2])});
	}

	int nowTime = 0;

	while (q.empty() == false ||
		st.empty() == false)
	{
		// q가 비어있음
		if (q.empty())
		{
			auto v2 = st.top();
			answer.push_back(v2.task);
			st.pop();
			continue;
		}

		auto v = q.front();
		q.pop();

		// st가 비어있음 (맨 처음 시작 포함)
		if (st.empty())
		{
			nowTime = v.timeValue;
			st.push(v);
			continue;
		}

		int nextStartTime = v.timeValue;
		int nowTaskEnd = nowTime + st.top().progressRemain;

		// 현재 작업이 더 빨리 끝나거나 끝나자 마자 시작할 수 있음
		if (nowTaskEnd <= nextStartTime)
		{
			answer.push_back(st.top().task);
			st.pop();
			nowTime = nowTaskEnd;
			
			// 다음 과제 시작 시간보다
			// 현재 시간 + 미뤄둔 시간이 짧은 경우
			while (st.empty() == false)
			{
				if (nowTime + st.top().progressRemain > nextStartTime)
				{
					st.top().progressRemain -= (nextStartTime - nowTime);
					break;
				}

				nowTime += st.top().progressRemain;
                answer.push_back(st.top().task);
				st.pop();
			}

		}
		else // 다음 과제가 중간에 들어옴
		{
			st.top().progressRemain -= (nextStartTime - nowTime);
		}

		nowTime = nextStartTime;
		st.push(v);
	}

	return answer;
}
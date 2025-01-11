#include <string>
#include <vector>

using namespace std;

const char calcs[3] = { '+' ,'-','*' };
// 임의의 연산자 우선순위를 선택하여
// 가장 절댓값이 큰 값을 만들기
//

bool isEnd(string& str)
{
	for (int i = 0; i < 3; i++)
	{
		if (str.find(calcs[i]) != string::npos)
			return false;
	}

	return true;
}

// 현재 문자열, 정답값, 현재값, 방문한 연산자 index
void dfs(vector<long long> numbers, vector<char> operators, long long& answer, vector<bool>& visited, int nowIdx)
{
	if (operators.size() == 0)
	{
		if (numbers[0] < 0)
			numbers[0] *= -1;

		if (answer < numbers[0])
			answer = numbers[0];

		return;
	}

	if (visited[nowIdx])
		return;

	visited[nowIdx] = true;

	for (int i = 0; i < operators.size(); i++)
	{
		if (operators[i] == calcs[nowIdx])
		{
			long long result = 0;
			switch (calcs[nowIdx])
			{
			case '*':
				result = numbers[i] * numbers[i + 1];
				break;
			case '+':
				result = numbers[i] + numbers[i + 1];
				break;
			case '-':
				result = numbers[i] - numbers[i + 1];
				break;
			}

			numbers[i] = result;
			numbers.erase(numbers.begin() + i + 1);
			operators.erase(operators.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		dfs(numbers, operators, answer, visited, i);
	}

	visited[nowIdx] = false;
}

void dfsStart(vector<long long>& numbers, vector<char>& operators, long long& answer, vector<bool>& visited)
{
	for (int i = 0; i < 3; i++)
	{
		dfs(numbers, operators, answer, visited, i);
	}
}

long long solution(string expression) {
	long long answer = 0;

	vector<long long> numbers;
	vector<char> operators;
	vector<bool> visited(3, false);

	string number = "";
	for (size_t i = 0; i < expression.length(); i++) {
		char ch = expression[i];

		if (isdigit(ch) || (ch == '-' && (i == 0 || operators.size() < numbers.size())))
		{
			number += ch;
		}
		else
		{
			if (!number.empty())
			{
				numbers.push_back(std::stoll(number));
				number.clear(); // 숫자 초기화
			}
			// 연산자일 경우
			if (ch == '*' || ch == '+' || ch == '-')
			{
				operators.push_back(ch);
			}
		}
	}
	numbers.push_back(std::stoll(number));

	dfsStart(numbers, operators, answer, visited);

	return answer;
}

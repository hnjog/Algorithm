#include <string>
#include <vector>

using namespace std;

const int c_MaxAlpha = 10;
const char alphabets[11] = "abcdefghij";

string solution(int age) {
	string answer = "";

	int index = 10;

	answer += alphabets[age % index];

	while (true)
	{
		if (index > age)
		{
			break;
		}

		index *= 10;
		int temp = (age % index - age % (index / 10)) / (index / 10);

		answer += alphabets[temp];
	}

	int size = answer.size();
	for (int i = 0; i < size / 2; i++)
	{
		char temp = answer[i];
		answer[i] = answer[size - i - 1];
		answer[size - i - 1] = temp;
	}

	return answer;
}
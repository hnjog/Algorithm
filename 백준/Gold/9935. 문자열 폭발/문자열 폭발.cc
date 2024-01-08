#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a; // 전체 문자열 변수
	string b; // 폭발 문자열 변수
	string t = ""; // 임시 문자열 

	cin >> a >> b;
	const size_t a_len = a.length(); // 전체 문자열 길이
	const size_t b_len = b.length(); // 폭발 문자열 길이

	for (int i = 0; i < a_len; i++)
	{
		t += a[i]; // 문자 추가

		// 임시 문자 길이가 폭발 문자열 보다 크거나 같을 때
		if (t.length() >= b_len)
		{
			// 폭발 문자열 있는지 확인하는 flag
			bool flag = true;

			for (int j = 0; j < b_len; j++)
			{
				// 현재 끝범위 - b_len에서
				// 폭발 문자열인지를 검사한다
				if (t[t.length() - b_len + j] != b[j])
				{
					flag = false;
					break;
				}
			}

			// 폭발 문자열일 경우 삭제 
			if (flag == true)
			{
				t.erase(t.end() - b_len, t.end());
			}
		}
	}

	// 남아 있는 문자열이 없는 경우
	if (t.empty() == true)
	{
		cout << "FRULA";
	}
	else
	{
		cout << t;
	}

	return 0;
}

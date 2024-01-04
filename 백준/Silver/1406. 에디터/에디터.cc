#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	deque<char> queL,queR;
	string str;
	int iCount;
	cin >> str >> iCount;

	for (char c : str)
	{
		queL.push_back(c);
	}

	// 커서를 기준으로 queL과 queR을 이용
	// 시간 제한이 빡빡하지만
	// 메모리 제한은 다소 널널하므로
	// deque 2개 사용
	// 왼쪽 큐(커서 왼쪽)
	// 오른쪽 큐(커서 오른쪽)
	// 기본적으로 P 입력 시 오른쪽 큐에 push_front
	// B 입력 시 왼쪽 큐에서 pop_back\
	// L입력 시 queL의 뒤를 하나 빼서 오른쪽 큐에 push_front
	// R입력 시 queR의 앞을 하나 빼서 왼쪽 큐에 push_back
	// 출력시 queL부터 출력 후, queR 출력
	const char ind[] = {'L','D','B','P'};
	for (int i = 0; i < iCount; i++)
	{
		char temp;
		cin >> temp;
		switch (temp)
		{
		case 'L':
		{
			if (queL.size() == 0)
			{
				break;
			}

			char t = queL.back();
			queL.pop_back();
			queR.push_front(t);
		}
		break;

		case 'D':
		{
			if (queR.size() == 0)
			{
				break;
			}

			char t = queR.front();
			queR.pop_front();
			queL.push_back(t);
		}
		break;

		case 'B':
		{
			if (queL.size() == 0)
			{
				break;
			}

			queL.pop_back();
		}
		break;

		case 'P':
		{
			char addC;
			cin >> addC;

			queL.push_back(addC);
		}
		break;
		default:
			break;
		}
	}

	for (auto l : queL)
	{
		cout << l;
	}

	for (auto r : queR)
	{
		cout << r;
	}

	return 0;
}
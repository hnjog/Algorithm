
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//N 최대 50개
// word로 미리 '필요한 알파벳'들을 저장해둔다
int word[50];   
int N, K;

int maxi = 0;

//선택을 할수 있는 개수, 시작점 , 체크 여부
void DFS(int toPick, int start, int checked)
{
	// 재귀 종료
	if (toPick == 0)
	{
		// 그 알파벳들로 N개 단어 중 몇개 읽을 수 있는지 카운트해서 최대값 찾기
		// checked로 저장을 해둔 알파벳으로
		// word 배열을 돌면서 해당 checked와 비트 체크를 해준다
		// and 연산으로 자기 자신이 나왔다는 것은
		// 그 단어가 필요로 하는 알파벳을 모두 골랐다는 뜻
		int cnt = 0;
		for (int i = 0; i < N; i++) 
		{
			if ((word[i] & checked) == word[i])
			{
				cnt++;
			}
		}

		if (maxi < cnt)
		{
			maxi = cnt;
		}
		return;
	}

	for (int i = start; i < 26; i++) 
	{
		//방문 안 한 경우에만
		if ((checked & (1 << i)) == 0) 
		{
			// int 변수로 체크해주기
			checked |= (1 << i);
			DFS(toPick - 1, i, checked); // 재귀
			checked &= ~(1 << i); // 이후 풀어준다
		}

	}
}

int main() 
{
	int checked = 0;
	cin >> N >> K;

	string str;
	for (int i = 0; i < N; i++) 
	{
		cin >> str;

		int num = 0;
		for (int j = 0; j < str.length(); j++) 
		{
			num |= 1 << (str[j] - 'a');
		}
		word[i] = num;
	}

	//anta ~ tica 읽으려면 최소 a,n,t,i,c 5개 이상은 알고 있어야함
	if (K < 5) 
	{
		cout << 0;
	}  
	else if (K == 26)
	{
		cout << N;
	}
	else 
	{
		//a, n, t, i, c 를 이미 알고 있음을 초기화.
		checked |= 1 << ('a' - 'a');
		checked |= 1 << ('n' - 'a');
		checked |= 1 << ('t' - 'a');
		checked |= 1 << ('i' - 'a');
		checked |= 1 << ('c' - 'a');

		DFS(K - 5, 0, checked);
		cout << maxi;
	}

	return 0;
}
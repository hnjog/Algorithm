#include<iostream>
#include<string>
#include<vector>
#include<limits.h>

using namespace std;

long maxV = INT_MIN;

long AllCalc(vector<int>& vv, vector<char>& ops)
{
	long ret = vv[0];

	// 이거 생각해보니까 곱하기, 나누기 있으면 그거 먼저 계산해야 함 X -> 연산자 우선순위는 모두 동일 (쓰여 있음)
	for (int i = 0; i < ops.size(); i++)
	{
		char c = ops[i];

		switch (c)
		{
		case '+':
		{
			ret += vv[i + 1];
		}
			break;
		case '-':
		{
			ret -= vv[i + 1];
		}
		break;
		case '*':
		{
			ret *= vv[i + 1];
		}
		break;
		}
	}

	return ret;
}

long Calc(int v1, int v2, char op)
{
	long ret = v1;
	switch (op)
	{
	case '+':
	{
		ret += v2;
	}
	break;
	case '-':
	{
		ret -= v2;
	}
	break;
	case '*':
	{
		ret *= v2;
	}
	break;
	}

	return ret;
}

void Recur(const vector<int>& vv, const vector<char>& ops, vector<int>& nowvv, vector<char>& nowops, int opIdx,bool bUse)
{
	int oS = ops.size();
	if (opIdx >= oS)
	{
		long tv = AllCalc(nowvv, nowops);
		maxV = max(maxV, tv);
		return;
	}
	// 그냥 가기
	// vv의 opIdx + 1을 nowops에 push_back하고
	// ops도 nowops에 push_back
	//
	{
		nowvv.push_back(vv[opIdx + 1]);
		nowops.push_back(ops[opIdx]);
		Recur(vv, ops, nowvv, nowops, opIdx + 1,false);
		nowops.pop_back();
		nowvv.pop_back();
	}


	// 현재 op로 계산 진행
	// nowvv의 현재 인덱스와 vv의 opIdx + 1 의 op 처리
	// 이미 처리한 연산자이기에 nowops 에는 넣지 않음
	if(bUse == false)
	{
		int o = nowvv.back();
		nowvv.pop_back();
		int t = Calc(o, vv[opIdx + 1], ops[opIdx]);
		nowvv.push_back(t);
		Recur(vv, ops, nowvv, nowops, opIdx + 1,true);
		nowvv.pop_back();
		nowvv.push_back(o);
	}
}

int main()
{
	/*
		음...

		- 괄호 안에는 하나의 연산자만 허용 : 중복 괄호 허용 x

		현재 연산 결과를 '우선시'한것과 아닌것으로 분기를 타는 방식인듯?

		결국 모든 분기를 봐야 하므로
		백트래킹 이라 생각함

		값 나누기?
		정수 타입 / 연산자

		연산자는 두 수의 사이에 존재

		- 우선시한 경우 
		  : 사실상 이게 괄호를 닫은 것이므로,
		    두 값을 연산 후, 다음으로 넘겨야 함
			(+ 이 때는 연산자를 다시 봐야 할듯?)

		- 아닌 경우
		  : 넘김!
		    다만 마지막에 도달한 경우는 몰아둔 연산을 전부 진행해야 함

		생각해볼 점?
		- 사용할 자료구조?
		  : 백트래킹을 해야 하기에 추가/제거가 원할한 자료구조여야 함
		    다만 문제는 '중간' 삽입/삭제가 될 수 있음(연산 순서가 있으므로)
			그렇다고 string으로 하자니 수가 연산 결과가 10을 넘거나 음수이면 계산이 다소 복잡해짐

		  - 일단 정수부와 연산자 부분을 나누어서 인덱스로 처리하는 방식은??
		  - 맞긴한데, 이러면 vector를 써야하나? -> 중간 연속 삽입,삭제가 부담스럽긴한데
		    -> 그렇다면 처음 시작할때 새로운 벡터를 통해 진행해야 함

			기존 수/연산자 말고
			신규 수/연산자 벡터에 쌓은 후,
			나중에 한꺼번에 계산하기
	*/

	int n;
	cin >> n;

	string v;
	cin >> v;

	vector<int> vv;
	vector<char> ops;

	for (char c : v)
	{
		if (c == '+' ||
			c == '-' ||
			c == '*')
		{
			ops.push_back(c);
		}
		else
		{
			vv.push_back(c - '0');
		}
	}

	vector<int> tvv;
	tvv.reserve(vv.size());
	tvv.push_back(vv[0]);
	vector<char> tops;
	tops.reserve(ops.size());

	Recur(vv, ops, tvv, tops, 0,false);

	cout << maxV;

	return 0;
}
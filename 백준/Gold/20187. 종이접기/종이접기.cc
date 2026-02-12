#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int getIdx(char c, int now)
{
	int ret = -1;
	switch (c)
	{
	case 'D':
	case 'U':
	{
		switch (now)
		{
		case 0:
			ret = 2;
			break;
		case 1:
			ret = 3;
			break;
		case 2:
			ret = 0;
			break;
		case 3:
			ret = 1;
			break;
		}
	}
	break;
	case 'R':
	case 'L':
	{
		switch (now)
		{
		case 0:
			ret = 1;
			break;
		case 1:
			ret = 0;
			break;
		case 2:
			ret = 3;
			break;
		case 3:
			ret = 2;
			break;
		}
	}
	break;
	}

	return ret;
}

vector<vector<int>> Pages(char c,vector<vector<int>>& input)
{
	int h = input.size();
	int w = input[0].size();

	switch (c)
	{
	case 'D':
	case 'U':
	{
		h *= 2;
	}
	break;
	case 'R':
	case 'L':
	{
		w *= 2;
	}
	break;
	}

	vector<vector<int>> ret(h, vector<int>(w));

	switch (c)
	{
	case 'D':
	{
		int halfh = h / 2;
		// 반대로 위를 향해 올린다
		// 따라서 halfh ~ h 까지는 기존 input 값을 유지시킴
		// 그리고 0~halfg 까지는 대비되게 짜야 함

		for (int i = 0; i < halfh; i++)
		{
			for (int j = 0; j < w; j++)
			{
				// 이쪽은 뒤집히므로, y축 역순이여야 함
				ret[i][j] = getIdx(c, input[halfh - i - 1][j]);
			}
		}

		for (int i = halfh; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				// 이쪽은 정순이여야 함
				ret[i][j] = input[i - halfh][j];
			}
		}
	}
	break;
	case 'U':
	{
		int halfh = h / 2;
		// 반대로 아래로 내림
		// 따라서 0~ halfh 까지는 정순
		// halfh ~ h 까지 역순

		for (int i = 0; i < halfh; i++)
		{
			for (int j = 0; j < w; j++)
			{
				ret[i][j] = input[i][j];
			}
		}

		for (int i = halfh; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				ret[i][j] = getIdx(c,input[h - i - 1][j]);
			}
		}
	}
	break;
	case 'R':
	{
		int halfw = w / 2;
		// 반대로 왼쪽으로 확장
		// 0~halfw 까지 역순
		// halfw~w 까지 정순

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < halfw; j++)
			{
				ret[i][j] = getIdx(c, input[i][halfw - j - 1]);
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = halfw; j < w; j++)
			{
				ret[i][j] = input[i][j - halfw];
			}
		}

	}
	break;
	case 'L':
	{
		int halfw = w / 2;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < halfw; j++)
			{
				ret[i][j] = input[i][j];
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = halfw; j < w; j++)
			{
				ret[i][j] = getIdx(c, input[i][w - j - 1]);
			}
		}
	}
	break;
	}

	return ret;
}

int main()
{
	/*
		문제 정리
		- 특정 중심점을 기준으로 '절반'으로 접음
			D : 가로를 기준으로 접지만 (윗면이 아랫면으로 오도록)
			U : 가로를 기준으로 접지만 (아랫면이 윗면으로 오도록)
			R : 세로를 기준으로 접지만 (왼쪽면이 오른쪽에 오도록)
			L : 세로를 기준으로 접지만 (오른쪽면이 왼쪽에 오도록)
		- 이런 방식을 통해 1x1이 될때까지 접음
		- 이후 0,1,2,3 방향에 구멍을 뚫은 후, 다시 종이를 폈을때
		  각 종이에 뚤린 구멍의 방향을 출력
		  (종이를 필때는 역순으로 핌)

		일단 k에 따라서 2^k 크기의 정사각형이 존재하게 됨

		생각을 바꿔보자면
		처음에 1x1 로 시작하고
		'접힌 종이'가 아예 반대방향으로 '펴진다'고 생각하면 될수도?

		ex)
		1x1 종이에서
		특정 방향에 구멍 뚫고 시작 (ex : 3)

		3

		만약 다음 실행이 D가 들어왔다면
		반대로 위를 향해 올려야 함
		1x2
		1
		3

		그 다음 R이 들어오면
		왼쪽으로 핌
		0 1
		2 3

		따라서
		범위가 늘어나며,
		특정 점 부분에서 '대칭'하는 부분으로
		인덱스가 바뀌게 됨
	*/

	int k;
	cin >> k;

	stack<char> os;
	for (int i = 0; i < k * 2; i++)
	{
		char c;
		cin >> c;
		os.push(c);
	}

	vector<vector<int>> ret(1, vector<int>(1));

	cin >> ret[0][0];

	for (int i = 0; i < k * 2; i++)
	{
		ret = Pages(os.top(), ret);
		os.pop();
	}

	int h = ret.size();
	int w = ret[0].size();

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << ret[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
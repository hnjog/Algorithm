#include<iostream>
#include<vector>

using namespace std;

int main()
{
	/*
		빗물 문제

		양측에서 '접근'하며 진행하는 문제

		0. 먼저 '가장 높은 길이'와 그 인덱스를 저장
			(다만 가장 높은 길이가 여러개라면 '중앙'에 있는 것을 선발)
		1. 왼쪽과 오른쪽에서 각각 그 인덱스를 향해 다가가기
		2. 각각 진행하며, 왼쪽 최대 높이, 오른쪽 최대 높이를 저장하기

		- 현재 진행 높이가 최대 높이보다 작다면,
		  그 차이수 만큼 물 양 증가
		- 현재 진행 높이가 최대 높이보다 크다면,
		  최대 높이를 현재 높이로 갱신
		
		3. 마지막으로 '가장 높은 길이'에 도달하였을때,
		   정지
	*/

	int h, w;
	cin >> h >> w;

	vector<int> vs(w);
	
	int bh = 0;
	int bi = 0;
	for (int i = 0; i < w; i++)
	{
		cin >> vs[i];

		if (vs[i] > bh)
		{
			bh = vs[i];
			bi = i;
		}
	}

	int wC = 0;

	int li = 0;
	int lh = vs[li];

	while (li < bi)
	{
		li++;
		int th = vs[li];
		
		if (th < lh)
		{
			wC += (lh - th);
		}
		
		if (th > lh)
		{
			lh = th;
		}
	}

	int ri = w - 1;
	int rh = vs[ri];

	while (ri > bi)
	{
		ri--;
		int th = vs[ri];

		if (th < rh)
		{
			wC += (rh - th);
		}

		if (th > rh)
		{
			rh = th;
		}
	}

	cout << wC;

	return 0;
}
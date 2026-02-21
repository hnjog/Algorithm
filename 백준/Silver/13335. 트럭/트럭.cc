#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, int> pii;

int main()
{
	int n, w, l;
	cin >> n >> w >> l;

	queue<int> vq;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		vq.push(t);
	}

	int sum = 0;
	int time = 1;

	queue<pii> wq;
	
	while (vq.empty() == false ||
		wq.empty() == false)
	{
		if (wq.empty() == false)
		{
			sum -= wq.front().first;
			time = wq.front().second;
			wq.pop();
		}

		int count = 0;
		while (vq.empty() == false &&
			sum + vq.front() <= l && // 다리 중량 못넘음
			wq.size() < w) // 다리 위에 있는 차량의 수가 '다리 길이'를 넘을 순 없음
		{
			int t1 = time + w + count;
			if (wq.empty() == false)
			{
				t1 = max( wq.back().second + 1,t1);
			}
			
			wq.push({ vq.front(), t1 });
			sum += vq.front();
			vq.pop();
			count++;
		}
	}

	cout << time;

	return 0;
}
#include<math.h>
#include<limits.h>

using namespace std;

typedef long long ll;

ll getMinValue(int step)
{
	return pow(3, step) + step * 2;
}

void dfs(int nowValue, int& answer, int mV, int pV)
{
	// 현재 값이 너무 적거나, 곱하기 수가 하나도 안남아 있다
	if (nowValue < 3 || mV == 0)
		return;

	// 더하기가 너무 많은 상황이다
	if (pV > mV * 2)
		return;

	if (pV == 0 && mV > 0)
	{
		while (mV > 1)
		{
			// 곱하기만 남았는데 3의 배수가 아닌 상황이므로 return
			if (nowValue % 3 != 0)
				return;

			nowValue /= 3;

			mV--;
		}
	}

	// 시작이 반드시 *이므로
	if (nowValue == 3 && mV == 1 && pV == 0)
	{
		answer++;
		return;
	}

	if (nowValue % 3 == 0)
		dfs(nowValue / 3, answer, mV - 1, pV);

	dfs(nowValue - 1, answer, mV, pV - 1);
}

int solution(int n) {
	int step = 1;
	int answer = 0;

	// 몇 번째 3의 배수에 위치하였는지를 체크하기
	{
		while (n >= getMinValue(step))
		{
			step++;
		}

		// 해당 step의 위치의 다음 단계이므로
		// 1빼준다
		step--;
	}

	// 어차피 마지막은 반드시 ++ 로 끝나기에
	// 미리 n과 plus의 수를 조절해준다
	dfs(n - 2, answer, step, step * 2 - 2);

	return answer;
}
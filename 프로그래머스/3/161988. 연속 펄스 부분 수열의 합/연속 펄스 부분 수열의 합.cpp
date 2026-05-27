#include <string>
#include <vector>
#include<math.h>
#include<limits.h>

using namespace std;

// 펄스를 곱해준 배열을 생성
vector<int> purse(vector<int> v, int num) 
{
	for (int i = 0; i < v.size(); i++) 
	{
		v[i] = v[i] * num;
		num *= -1;
	}
	return v;
}

long long solution(vector<int> sequence) {
    const size_t sSize = sequence.size();
    long long answer = LONG_MIN;

    if (sSize == 1) 
    {
        answer = abs(sequence[0]);
        return answer;
    }

    // 1로 시작하는 펄스 벡터
    vector<int> seq1 = purse(sequence, 1);
    // -1로 시작하는 펄스 벡터
    vector<int> seq2 = purse(sequence, -1);

    vector<long long> dp1(sSize); // 1 dp 배열
    vector<long long> dp2(sSize);// -1 dp 배열

    dp1[0] = seq1[0];
    dp2[0] = seq2[0];

    for (int i = 1; i < sSize; i++)
    {
        // 이전까지 더한 합이 그냥 지금 새로 시작하는 것보다 못하면 버리고 새로 시작
        dp1[i] = max(dp1[i - 1] + (long long)seq1[i], (long long)seq1[i]);
        answer = max(answer, dp1[i]);
    }

    for (int i = 1; i < sSize; i++) 
    {
        // 이전까지 더한 합이 그냥 지금 새로 시작하는 것보다 못하면 버리고 새로 시작
        dp2[i] = max(dp2[i - 1] + (long long)seq2[i], (long long)seq2[i]);
        answer = max(answer, dp2[i]);
    }

    return answer;
}
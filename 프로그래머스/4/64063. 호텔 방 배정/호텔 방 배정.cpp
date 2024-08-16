#include <vector>
#include<unordered_map>

using namespace std;

long long FindParent(long long num, unordered_map<long long, long long>& roomMap)
{
	if (roomMap[num] == 0) // 자동 0으로 초기화를 이용
		return num;
	
	return roomMap[num] = FindParent(roomMap[num], roomMap);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	unordered_map<long long, long long> roomMap;
	// union-find
	for (auto num : room_number)
	{
		if (roomMap[num] == 0)
		{
			answer.push_back(num);
			roomMap[num] = FindParent(num + 1,roomMap);
		}
		else
		{
			long long nextNum = FindParent(num, roomMap);
			answer.push_back(nextNum);
			roomMap[nextNum] = FindParent(nextNum + 1, roomMap);
		}
	}

	return answer;
}
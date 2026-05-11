#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

void GetV(unordered_map<string, string>& pm, unordered_map<string, int>& am, string& nowEarn, int amount)
{
    if (amount == 0)
		return;
    
	string& parent = pm[nowEarn];
	int paAmount = amount / 10;
	int nowAmount = amount - paAmount;

	am[nowEarn] += nowAmount;
	if (parent != "-")
	{
		GetV(pm, am, parent, paAmount);
	}
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer;
	unordered_map<string, string> pm;
	unordered_map<string, int> am;

	int es = enroll.size();

	for (int i = 0; i < es; i++)
	{
		pm[enroll[i]] = referral[i];
	}

	int ss = seller.size();

	for (int i = 0; i < ss; i++)
	{
		GetV(pm, am, seller[i], amount[i] * 100);
	}

	answer.reserve(es);
	for (string& e : enroll)
	{
		answer.push_back(am[e]);
	}

	return answer;
}
#include <string>
#include <vector>

using namespace std;

bool isInSkillTree(const string& skillTree, size_t skillTree_idx, const string& targetSkillTree, size_t targetSkillTree_idx)
{
	bool isFind = false;

	size_t sSize = skillTree.size();
	size_t tSize = targetSkillTree.size();

	// 스킬 트리 내에 있거나,
	// 나중에 배울 수 있음
	if (skillTree_idx >= sSize ||
		targetSkillTree_idx >= tSize)
		return true;

	char nowC = targetSkillTree[targetSkillTree_idx];

	for (size_t i = 0; i < sSize; i++)
	{
		// 찾았음
		if (skillTree[i] == nowC)
		{
			// 그런데 현재 위치보다 뒤에 있는 녀석임
			if (i > skillTree_idx)
			{
				return false;
			}

			// 다음 위치로
			return isInSkillTree(skillTree, skillTree_idx + 1, targetSkillTree, targetSkillTree_idx + 1);
		}
	}

	//못 찾은 경우 다음 문자로 넘어가기 위함
	return isInSkillTree(skillTree, skillTree_idx, targetSkillTree, targetSkillTree_idx + 1);
}

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (const auto& s : skill_trees)
	{
		if (isInSkillTree(skill, 0, s, 0))
			answer++;
	}

	return answer;
}
#include <string>
#include <vector>
#include<algorithm>
#include<memory>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	struct node
	{
		int index;
		int x;
		int y;
	};

	vector<node> vec;
	for (int i = 0; i < nodeinfo.size();i++)
	{
		vec.push_back(node{i + 1,nodeinfo[i][0],nodeinfo[i][1]});
	}

	sort(vec.begin(), vec.end(), [](const node& a, const node& b) {
		if (a.y == b.y)
			return a.x < b.x;

		return a.y > b.y;
		});

	// tree 만들어서 넣기

	struct treeNode
	{
		node value;
		unique_ptr<treeNode> left;
		unique_ptr<treeNode> right;

		void insert(node _value)
		{
			if (value.x > _value.x)
			{
				if (left == nullptr)
				{
					left = make_unique<treeNode>();
					left->value = _value;
				}
				else
				{
					left->insert(_value);
				}
			}
			else if (value.x < _value.x)
			{
				if (right == nullptr)
				{
					right = make_unique<treeNode>();
					right->value = _value;
				}
				else
				{
					right->insert(_value);
				}
			}
		}

		void preOrder(vector<int>& answer)
		{
			answer.push_back(value.index);
			if(left != nullptr)
				left->preOrder(answer);
			if (right!= nullptr)
				right->preOrder(answer);
		}

		void postOrder(vector<int>& answer)
		{
			if (left != nullptr)
				left->postOrder(answer);

			if (right != nullptr)
				right->postOrder(answer);

			answer.push_back(value.index);
		}
	};

	treeNode root = { vec[0],nullptr,nullptr };

	for (int i = 1; i < vec.size(); i++)
	{
		root.insert(vec[i]);
	}

	vector<int> temp;
	root.preOrder(temp);
	answer.push_back(temp);
	temp.clear();
	root.postOrder(temp);
	answer.push_back(temp);

	return answer;
}
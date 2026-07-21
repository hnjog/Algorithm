class Solution {
public:
	int countStudents(vector<int>& students, vector<int>& sandwiches) {
		queue<int> q1, q2;
		for (int st : students)
		{
			q1.push(st);
		}

		for (int st : sandwiches)
		{
			q2.push(st);
		}

		while (q2.empty() == false)
		{
			bool bNotPickup = true;
			for (int i = 0; i < q1.size(); i++)
			{
				if (q1.front() == q2.front())
				{
					bNotPickup = false;
					q1.pop();
					q2.pop();
					break;
				}
				else
				{
					q1.push(q1.front());
					q1.pop();
				}
			}

			if (bNotPickup)
				break;
		}

		return q2.size();
	}
};
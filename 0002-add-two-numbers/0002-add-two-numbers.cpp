class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		vector<int> vv1,vv2;
		ListNode* temp = l1;
		while (true)
		{
			vv1.push_back(temp->val);
			temp = temp->next;
			if (temp == nullptr)
				break;
		}

		temp = l2;
		while (true)
		{
			vv2.push_back(temp->val);
			temp = temp->next;
			if (temp == nullptr)
				break;
		}

		
		string st;
		int idx = max(vv1.size(), vv2.size());
		bool bNext = false;
		for (int i = 0; i < idx; i++)
		{
			int v1 = 0, v2 = 0;;
			if (i < vv1.size())
				v1 = vv1[i];

			if (i < vv2.size())
				v2 = vv2[i];

			int r = v1 + v2;
			if (bNext)
			{
				r++;
				bNext = false;
			}

			if (r >= 10)
			{
				bNext = true;
				r -= 10;
			}

			st.push_back(r + '0');
		}
        
		if (bNext)
			st.push_back(1 + '0');
        
		ListNode* now = new ListNode();
		ListNode* start = now;

		for (int i=0;i<st.size();i++)
		{
			now->val = st[i] - '0';
			if (i != st.size() - 1)
			{
				now->next = new ListNode();
				now = now->next;
			}
		}

		return start;
	}
};
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		set<int> sv;

		ListNode* temp = head;

		while (temp != nullptr)
		{
			sv.insert(temp->val);
			temp = temp->next;
		}

		if (sv.empty())
			return head;

		auto it = sv.begin();
		ListNode* newHead = new ListNode(*it);
		temp = newHead;
		it++;
		for (; it != sv.end(); it++)
		{
			temp->next = new ListNode(*it);
			temp = temp->next;
		}

		return newHead;
	}
};
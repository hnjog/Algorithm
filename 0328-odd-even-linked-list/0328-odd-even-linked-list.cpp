class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode* head1 = nullptr;
		ListNode* idx1 = nullptr;
		ListNode* head2 = nullptr;
		ListNode* idx2 = nullptr;

		ListNode* temp = head;
		int idx = 0;
		while (temp != nullptr)
		{
			idx++;
			ListNode* now = temp;
			temp = temp->next;

			if (idx % 2 == 1)
			{
				if (head1 == nullptr)
				{
					head1 = now;
					idx1 = now;
					continue;
				}

				ListNode* ti = idx1;
				ti->next = now;
				idx1 = now;
			}
			else
			{
				if (head2 == nullptr)
				{
					head2 = now;
					idx2 = now;
					continue;
				}

				ListNode* ti = idx2;
				ti->next = now;
				idx2 = now;
			}
		}
		
		if(idx2 != nullptr)
			idx2->next = nullptr;

		if(idx1 != nullptr)
			idx1->next = head2;

		return head1;
	}
};
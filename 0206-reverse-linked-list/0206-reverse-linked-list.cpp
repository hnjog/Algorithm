/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr)
			return head;
		
		ListNode* temp = head;
		ListNode* newhead = new ListNode(head->val);

		while (true)
		{
			temp = temp->next;
			if (temp == nullptr)
				break;
			ListNode* t = new ListNode(temp->val);
			t->next = newhead;
			newhead = t;
		}

		return newhead;
	}
};
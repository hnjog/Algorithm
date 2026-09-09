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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* temp = nullptr;
        ListNode* ret = nullptr;
        if (l1 != nullptr &&
            l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            else
            {
                temp = l2;
                l2 = l2->next;
            }
        }
        else if (l2 != nullptr)
        {
            temp = l2;
            l2 = l2->next;
        }
        else if (l1 != nullptr)
        {
            temp = l1;
            l1 = l1->next;
        }
        else
        {
            return nullptr;
        }

        ret = temp;

        while (l1 != nullptr &&
            l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }

            if (temp->next != nullptr)
                temp = temp->next;
        }

        while (l1 != nullptr)
        {
            temp->next = l1;
            l1 = l1->next;
            if (temp->next != nullptr)
                temp = temp->next;
        }

        while (l2 != nullptr)
        {
            temp->next = l2;
            l2 = l2->next;
            if (temp->next != nullptr)
                temp = temp->next;
        }

        return ret;
    }
};
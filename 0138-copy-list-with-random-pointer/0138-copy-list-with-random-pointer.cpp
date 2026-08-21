/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr)
			return head;

		unordered_map<Node*, Node*> nmap;

		Node* temp = head;
		while (temp != nullptr)
		{
			nmap[temp] = new Node(temp->val);
			temp = temp->next;
		}

		temp = head;
		while (temp != nullptr)
		{
			nmap[temp]->next = nmap[temp->next];
			nmap[temp]->random = temp->random == nullptr ? nullptr : nmap[temp->random];
            temp = temp->next;
		}

		return nmap[head];
	}
};

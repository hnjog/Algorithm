class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* start = head;
		ListNode* now = head;

		while (now != nullptr)
		{
			int nowV = now->val;

			if (now->next == nullptr)
				break;

			int nextV = now->next->val;
			
			// 다음 것과 정렬이 되어 있음
			if (nowV <= nextV)
			{
				now = now->next;
				continue;
			}

			ListNode* nn = now->next;
			now->next = nn->next; // 현재 노드의 연결 끊기 (4 -> 1)

			// 다음 것이 현재 내 값보다 작음
			// 처음부터 확인하여 위치할 자리를 찾기
			// 
			ListNode* temp = start;
			ListNode* prev = nullptr;
			// temp 위치의 값이 다음 위치의 값보다 작다면 계속 넘어감
			while (temp->val <= nextV)
			{
				prev = temp;
				temp = temp->next;
			}

			nn->next = temp;

			// 시작점과 바뀌었다면
			if (prev == nullptr)
			{
				// 시작 위치 변경
				start = nn;
			}
			else
			{
				prev->next = nn;
			}

			// 현재의 now를 갱신하지 않고 다시 시작
		}

		return start;
	}
};
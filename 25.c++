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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;

        while (true) {
            // Check if there are at least k nodes left
            ListNode* kth = prevGroup;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }

            if (!kth) break;

            ListNode* groupStart = prevGroup->next;
            ListNode* nextGroup = kth->next;

            // Reverse the current group
            ListNode* prev = nextGroup;
            ListNode* curr = groupStart;

            while (curr != nextGroup) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect the reversed group
            prevGroup->next = kth;
            prevGroup = groupStart;
        }

        return dummy.next;
    }
};
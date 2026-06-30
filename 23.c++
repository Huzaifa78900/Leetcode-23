
#include <vector>
#include <queue>

class Solution {
public:
    // Custom comparator to structure the Min-Heap based on node values
    struct compare {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Min-heap to keep track of the smallest node among the heads of the lists
        std::priority_queue<ListNode*, std::vector<ListNode*>, compare> minHeap;
        
        // Push the head of each non-empty linked list into the min-heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Process the nodes until the heap is empty
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            // Append the smallest node to our merged list
            tail->next = smallest;
            tail = tail->next;
            
            // If the extracted node has a next node, push it into the heap
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};
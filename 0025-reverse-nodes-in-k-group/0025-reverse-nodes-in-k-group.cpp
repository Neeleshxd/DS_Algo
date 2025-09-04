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
    if (!head || k == 1) return head;  // Base case: if list is empty or k=1, return original list
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode *prev = dummy, *curr = dummy, *next = dummy;
    
    int count = 0;
    while (curr->next) {  // Calculate the length of the list
        curr = curr->next;
        count++;
    }
    
    while (count >= k) {  // Process in groups of k
        curr = prev->next;
        next = curr->next;
        
        // Reverse k nodes
        for (int i = 1; i < k; i++) {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        
        prev = curr;
        count -= k;
    }
    
    return dummy->next;
}
};
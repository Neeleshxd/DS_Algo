/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if( head == nullptr || head->next == nullptr ) return nullptr ;
        ListNode*fast = head ;
        ListNode*slow = head ;
        while( fast != nullptr && fast->next != nullptr ){
            slow = slow->next ;
            fast = fast->next->next ;
            if( slow == fast ){
                ListNode*curr = head ;
                while(slow != curr ){
                    curr = curr->next ;
                    slow = slow->next ; 
                }
                   return curr ; 
            }
        }
        return nullptr ; 
    }
};
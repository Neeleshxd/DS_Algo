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
    ListNode* deleteMiddle(ListNode* head) {
        if( head->next == nullptr ) return nullptr ; 
        int length = 0 ; 
        ListNode*tail = head ;
        while( tail != nullptr ){
            length++; 
            tail = tail->next ; 
        }
        int mid = length / 2 ; 
        ListNode*temp = head ; 
        for( int i = 0 ; i < mid-1 ; i++ ){
            temp = temp->next ; 
        }
        temp->next = temp->next->next ; 
        return head ; 
    }
};
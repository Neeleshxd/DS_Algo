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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( head == nullptr || head->next == nullptr ) return nullptr ; 
        ListNode*tail = head ; 
        int length = 0 ; 
        while( tail != nullptr ){
            length +=1 ;
            tail = tail->next ; 
        }
        int m = length - n ; 
        ListNode*temp = head ; 
        if( m!= 0 ){
          for( int i = 0 ; i < m -1  ; i++ ){
         temp = temp->next ; 
        }
        if( temp->next->next != nullptr ){
            temp->next = temp->next->next ; 
        }else{
            temp->next = nullptr ; 
        }
        }else{
            head = head->next ; 
            temp->next =nullptr ; 
        }
        return head ; 
    }
};
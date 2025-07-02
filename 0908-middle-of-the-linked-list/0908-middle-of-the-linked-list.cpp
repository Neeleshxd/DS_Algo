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
    ListNode* middleNode(ListNode* head) {
       ListNode*tail = head ; 
       int count = 0 ;
       while( tail != nullptr ){
        count+=1 ;
        tail = tail->next ; 
       }
       int mid = count / 2 ; 
       ListNode*newhead = head ; 
       for( int i = 0 ; i < mid ; i++ ){
        newhead = newhead->next ; 
       }
       return newhead ; 
    }
};
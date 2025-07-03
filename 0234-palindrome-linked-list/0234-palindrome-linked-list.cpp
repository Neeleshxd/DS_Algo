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
     ListNode* reverse(ListNode* head) {
        ListNode*newhead = nullptr ; 
        ListNode*curr; 
        while( head != nullptr ){
            curr =head->next ;
            head->next = newhead ;
            newhead = head ; 
            head = curr ; 
        }
        return newhead ; 
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow = head ; 
        ListNode*fast = head ; 
        while( fast != nullptr && fast->next != nullptr ){
            slow = slow->next ;
            fast = fast->next->next ; 
        }
        ListNode*newhead = reverse(slow) ; 
        ListNode*start = head ; 
        ListNode*second = newhead ; 
        while(second != nullptr ){
            if( start->val != second->val ){
                reverse(newhead) ;
                return false ; 
            }
            start = start->next ;
            second = second->next ; 
        }
        reverse(newhead) ; 
        return true ; 
    }
};
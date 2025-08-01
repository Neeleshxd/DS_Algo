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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0 ; 
        ListNode*first = l1 ;
        ListNode*second = l2 ; 
        ListNode*dummy= new ListNode(-1) ; 
        ListNode*temp = dummy ; 
        while( l1 != nullptr && l2 != nullptr ){
            int val1 = l1->val ; 
            int val2 = l2->val ; 
            int sum = val1 + val2 + carry ; 
            carry = sum / 10 ; 
            int new_node = sum % 10 ; 
            temp->next = new ListNode(new_node) ; 
            temp = temp->next ; 
            l1= l1->next ;
            l2 = l2->next ; 
        }
        while( l1 != nullptr ){
                int sum = l1->val + carry ; 
                carry = sum / 10 ;
                int new_node = sum % 10 ; 
                temp->next = new ListNode(new_node) ;
                temp = temp->next ; 
                l1 = l1->next ; 
        }
          while( l2 != nullptr ){
                int sum = l2->val + carry ; 
                carry = sum / 10 ;
                int new_node = sum % 10 ; 
                temp->next = new ListNode(new_node) ;
                temp = temp->next ; 
                l2 = l2->next ; 
        }
         if( carry > 0 ){
            temp->next = new ListNode(carry) ; 
            temp =temp->next ; 
         }
        return dummy->next ; 
    }
};
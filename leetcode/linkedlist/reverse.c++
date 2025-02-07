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
    ListNode* reverseList(ListNode* head) {
        ListNode*curr =nullptr ;
        ListNode*temp = head ; 
        while(temp != nullptr ){
        head = head->next ; 
        temp->next = curr ;
        curr=temp;
        temp=head;
        }
        return curr ; 
    }
};//Tc O(n) SC O(1) 
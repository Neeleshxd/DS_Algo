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
    ListNode* oddEvenList(ListNode* head) {
        if( head == nullptr || head->next == nullptr ) return head ; 
        ListNode*dummy = new ListNode(-1,nullptr) ; 
        ListNode*odd = head ;
        ListNode*even = head->next ; 
        dummy->next = even ; 
        while( odd->next != nullptr && even->next != nullptr ){
            odd->next =nullptr ; 
            odd->next = even->next ; 
            even->next = nullptr ; 
            odd = odd->next ; 
            even->next = odd->next ;
            even = even->next ; 
        }
        odd->next = dummy->next ; 
        dummy->next = nullptr ;
        return head ;  
    }
};
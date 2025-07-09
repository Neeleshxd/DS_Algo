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
    ListNode* sortList(ListNode* head) {
        if( head == nullptr || head->next == nullptr ) return head ; 
        vector<int>temp ; 
        ListNode*temp1 = head ; 
        while( temp1 != nullptr ){
            temp.push_back(temp1->val) ; 
            temp1 = temp1->next ; 
        }
        sort(temp.begin(),temp.end()) ; 
        ListNode*dummy = new ListNode(-1) ; 
        ListNode*t = dummy ; 
        for( int i = 0 ; i < temp.size() ; i++ ){
             t->next = new ListNode(temp[i]) ; 
             t = t->next ; 
        }
        return dummy->next ; 
    }
};
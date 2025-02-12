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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode*temp = headA;
            ListNode*temp1 = headB ; 
            int length1= 0;
            int length2 = 0;
    
            while( temp != nullptr  ){
            length1++;
            temp = temp->next ; 
            }
            while( temp1 != nullptr ){
            length2++;
            temp1 = temp1->next ; 
            }
            int diff = abs(length1 - length2 );
    
            ListNode*slow = headA;
            ListNode*fast = headB;
            int count = 0 ; 
            if( length1 > length2 && diff > 0 ){
            while( count != diff ){
                count++;
                slow = slow->next;
            }
            }else{
                while( count != diff ){
                count++;
                fast = fast->next ;
                }
            }
    
            while( fast != nullptr && slow != nullptr ){
                if( slow == fast ){
                    return slow ; 
                }
                fast = fast->next ;
                slow = slow->next ; 
            }
        return nullptr ; 
        }
    }; //TC: O(N+M) SC: O(1) where n is the size of the linked list
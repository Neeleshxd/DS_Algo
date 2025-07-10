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
       ListNode*tail1 = headA ;
       ListNode*tail2 = headB ; 
       int length1 = 0 ;
       int length2 = 0 ; 
       while( tail1 != nullptr ){
        length1++; 
         tail1 = tail1->next ; 
       } 
       while(tail2 != nullptr ){
        length2++ ;
        tail2 = tail2->next ; 
       }
       int skip = abs(length1 - length2) ; 
       ListNode*first = headA;
       ListNode*second = headB ; 
       if( length1 > length2 ){
         while( skip >  0 ){
            skip--;
            first = first->next ; 
         }
       }else{
         while( skip >  0 ){
            skip--;
            second = second->next ; 
         }
       }
       while( first != nullptr ){
            if(first == second){
                return first ; 
            }
            first = first->next ;
            second = second->next ; 
       }
       return nullptr ; 
    }
};
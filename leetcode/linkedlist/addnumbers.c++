//Better solution//1st approach
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
            ListNode*dummy = new ListNode(-1);
            ListNode*temp = dummy ; 
            ListNode*sum ; 
            int remainder ;
            int quotient ; 
            int curr_sum ; 
            while( l1!= nullptr && l2!= nullptr ){
              curr_sum = l1->val + l2->val; 
    
              if (quotient != 0) { 
              curr_sum += quotient;  
              quotient = 0; 
              }
              if(curr_sum >= 10 ){
                 remainder = curr_sum % 10 ;
                 quotient =  curr_sum / 10 ; 
                sum = new ListNode(remainder);
              }else{
                sum = new ListNode(curr_sum) ; 
                }
              temp->next = sum ;
              temp = temp->next;  
              l1 = l1->next;
              l2 = l2->next; 
              }
             
            while(l1 != nullptr ){
            curr_sum = l1->val ;
            if( quotient != 0 ){
                curr_sum +=  quotient ; 
                quotient = 0 ; 
            } 
             if(curr_sum >= 10 ){
                 remainder = curr_sum % 10 ;
                 quotient =  curr_sum / 10 ; 
                sum = new ListNode(remainder);
              }else{
                sum = new ListNode(curr_sum) ; 
                }
    
            temp->next = sum ;
            temp = temp->next;  
            l1= l1->next;
            }
            while(l2 != nullptr ){
            curr_sum = l2->val ;
            if( quotient != 0 ){
                curr_sum +=  quotient ; 
                quotient = 0 ; 
            } 
             if(curr_sum >= 10 ){
                 remainder = curr_sum % 10 ;
                 quotient =  curr_sum / 10 ; 
                sum = new ListNode(remainder);
              }else{
                sum = new ListNode(curr_sum) ; 
                }
    
            temp->next = sum ;
            temp = temp->next;  
            l2= l2->next;
            }
            if( quotient != 0 ){
                temp->next = new ListNode(quotient) ; 
            }
            return dummy->next ;
        }
    }; //Tc O(max(N,M)) SC O(1) where N is the maximum length of the two linked lists
    //Best solution
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
//2nd approach
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode*dummy = new ListNode(-1);
            ListNode*temp = dummy ;  
            int quotient = 0 ; 
            while( l1!= nullptr || l2!= nullptr ||quotient != 0){
              int sum = quotient ; 
              if(l1){
                sum += l1->val ; 
                l1= l1->next ; 
              }
              if(l2){
                sum+= l2->val ;
                l2 = l2->next;
              }
              quotient = sum / 10;
              temp->next = new ListNode(sum % 10);
              temp = temp->next; 
              }
             
            return dummy->next ;
        }
    }; //Tc O(O(Max(N,M))) SC O(O(Max(N,M))) where N is the maximum length of the two linked lists
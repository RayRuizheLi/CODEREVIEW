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
        ListNode* runner1 = l1; 
        ListNode* runner2 = l2; 
        ListNode* head = new ListNode(0);
        ListNode* cur = head; 
        int carry = 0; 
        
        while(runner1 != nullptr || runner2 != nullptr){
            int r1 = 0;
            int r2 = 0; 
            
            if(runner1 != nullptr){
                r1 = runner1->val; 
                runner1 = runner1->next; 
            }
            
            if(runner2 != nullptr){
                r2 = runner2->val;
                runner2 = runner2->next; 
            }
                        
            cur->next = new ListNode((r1 + r2 + carry) % 10);
            cur = cur->next; 
            
            carry = (r1 + r2 + carry) / 10;
        }
        
        if(carry != 0){
            cur->next = new ListNode(carry);
        }
        
        return head->next; 
    }
};

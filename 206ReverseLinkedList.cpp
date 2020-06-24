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
        if(!head || !head->next) return head; 
        
        ListNode* cur = head; 
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        
        while(cur){
            // prepare for what next cur is 
            next = cur->next;
            
            //cur's next points to previous node 
            cur->next = prev; 
            
            //the previous node of next cycle is cur 
            prev = cur; 
            
            //set cur to the next node 
            cur = next; 
        }
        
        return prev; 
    }
};

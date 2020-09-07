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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //Mistake: my algorithm fails on edge caes wherethe element removed is the head
        
        //This solves the problem of my edge case.
        ListNode* dummy = new ListNode(0);
        dummy->next = head; 
        ListNode* runner1 = dummy;
        ListNode* runner2 = dummy;
        
        for(int i = 0; i < n + 1; ++i) runner1 = runner1->next; 
        
        while(runner1 != nullptr){
            runner1 = runner1->next; 
            runner2 = runner2->next;
        }
        
        runner2->next = runner2->next->next; 
        
        return dummy->next; 
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Idea: two pointers, maintain a gap of n 
        //ex: n = 2, we maintain gap n + 1 = 3 
        //dummy 1 2 3 4 5 6 
        // | f
        // | s
        //dummy 1 2 3 4 5 6 
        //          | f
        // | s
        //dummy 1 2 3 4 5 null
        //                 | f
        //          | s
        
        
        //the solution explanantion is great for this question. 
        
        //We use dummy to solve cases such as [1], n = 1
        
        //dummy does not prevent cases such as [1], n = 10. 
        //this is fine for this question since all n are valid. 
        ListNode* dummy = new ListNode();
        dummy->next = head; 
    
        //why not start from head? 
        ListNode* first = dummy; 
        ListNode* second = dummy; 
        
        // n + 1 because we want second to stop at the node right before
        //   the nth from the back. 
        for(int i = 1; i <= n + 1; ++i) first = first->next; 
        
        //move first to the end, maintaining the gap 
        while(first != nullptr){
            first = first->next; 
            second = second->next; 
        }
        
        //remove nth node from the back
        cout << "second->val: " << second->val << endl;
        second->next = second->next->next; 
        
        return dummy->next;
        
    }
};

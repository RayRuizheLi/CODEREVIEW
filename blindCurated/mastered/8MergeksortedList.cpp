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
    struct comp{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists){
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        
        // push the head of each linked list into pq 
        for(ListNode* x: lists){
            if(x) pq.push(x);
        }
        
        ListNode* cur = new ListNode(0);
        ListNode* dummy =  cur; 
        
        while(!pq.empty()){
            // we take the smallest node in the pq. 
            cur->next = pq.top(); 
            pq.pop();
            cur = cur->next; 
            
            // If there are nodes after the smallest node, send it to the pq 
            //  to be sorted. 
            if(cur->next){
                pq.push(cur->next);
            }
        }
        
        return dummy->next; 
    }
};

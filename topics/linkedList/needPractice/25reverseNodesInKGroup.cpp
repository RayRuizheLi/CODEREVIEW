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
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* cur = head; 
            ListNode* prev = nullptr; 
            ListNode* next = nullptr; 
            
            int count = 0; 
            
            // Exit when not amount of nodes in linkedlist is less than k
            while(count < k && cur != nullptr){
                cur = cur->next;
                ++count;
            }
            
            if(count < k) return head; 
            
            // Actual loop for reversing
            cur = head; 
            count = 0; 
            
            while(count < k){
                count++; 
                
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next; 
            }
            
            if(cur != nullptr) head->next = reverseKGroup(cur, k);
            
            return prev; 
        }
};

// None-recursive 

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* cur = head;
            ListNode* next = nullptr;
            ListNode* prev = nullptr; 
            ListNode* lastHead = nullptr;
            ListNode* newHead = head;
            ListNode* finalHead = nullptr; 
            
            int count = 0, iter = 0; 
                        
            while(cur != nullptr){
                cur = cur->next;
                ++count; 
            }
            
            if(count < k) return head;
            
            iter = count / k; 
            cur = head;
            
            //cout << "iter: " << iter << endl; 
            
            for(int i = 0; i < iter; ++i){
                count = 0; 
                
                while(count < k){
                    ++count; 
                    
                    next = cur->next; 
                    cur->next = prev;
                    prev = cur; 
                    cur = next;
                }
                
                if(i != 0){
                    lastHead->next = prev;
                }else{
                    finalHead = prev;
                }
                
                lastHead = newHead;
                newHead = cur;
                
                prev = nullptr;
            }
            
            lastHead->next = cur; 
            
            return finalHead; 
        }
};

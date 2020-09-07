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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head = ListNode(0);
        ListNode *curr = &head;
        curr->next = l1;
        
        while (curr->next && l2)
        {
            if (curr->next->val > l2->val)
            {
                ListNode *temp = curr->next;
                curr->next = l2;
                l2 = temp;
            }
            curr = curr->next;
        }
        
        // if cur->next is not nullptr, we are done. 
        // if cur->next is nullptr, then we may have items left in l2. 
        // even if l2 do not have items, it is fine to assign cur->next to be nullptr. 
        
        if (!curr->next)
            curr->next = l2;
        
        return head.next;
    }
};
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
//         ListNode head = ListNode(); 
//         ListNode* cur = &head; 
        
//         /*
//         ListNode* head = new ListNode(); 
//         ListNode* cur = head;
        
//         The above also works, but is slower.
//         */
        
//         while(l1 != nullptr && l2 != nullptr){
//             if(l1->val < l2->val){
//                 cur->next = l1; 
                
//                 l1 = l1->next; 
//             }else{
//                 cur->next = l2;
                
//                 l2 = l2->next; 
//                 cout << "l2" << endl;
//             }
            
//             // Need this line to move to the next pointer 
//             cur = cur->next; 
//         }
        
//         if(l1 != nullptr){
//             cur->next = l1; 
            
//         }
        
//         if(l2 != nullptr){
//             cur->next = l2; 
//         }
        
//         return head.next;
//     }
// };


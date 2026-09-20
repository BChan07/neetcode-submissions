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
    bool hasCycle(ListNode* head) {
        ListNode* itr1; 
        ListNode* itr2;
        if(head == nullptr){
            return false;
        }
        else if(head->next == head){
            return true;
        }

        itr1 = head;
        itr2 = head->next;
        
        while(itr1 != itr2){
            if((itr1->next == nullptr) || (itr2->next == nullptr) || itr2 == nullptr){
                return false;
            }
            itr1 = itr1->next;
            itr2 = itr2->next->next;
        }
        return true;
    }
};

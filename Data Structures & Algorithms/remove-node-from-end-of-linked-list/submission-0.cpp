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
        ListNode* itr = head, *itr2;
    int size = 0;
    int i = 0;

    while(itr != nullptr){
        itr = itr->next;
        size++;
    }

    if(n == size){
        itr2 = head;
        head = head->next;
        delete itr2;
        return head;
    }

    itr = head;

    while(i < size-n-1){
        itr = itr->next;
        i++;
    }

    itr2 = itr->next;
    itr->next = itr->next->next;
    delete itr2;
    return head;
    }
};

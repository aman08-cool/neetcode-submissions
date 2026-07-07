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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        //Find Middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //Preserve the second list head, then break into lists;
        ListNode* second = slow->next;
        slow->next = NULL;

        //reverse second half
        ListNode* prev = NULL;
        while(second){
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        //Merge
        ListNode* first = head;
        second = prev;
        while(second){
            ListNode* next1 = first->next;
            ListNode* next2 = second->next;

            first->next = second;
            second->next = next1;

            first = next1;
            second = next2;
        }

    }
};

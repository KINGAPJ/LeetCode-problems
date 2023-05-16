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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)   
            return head;

        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* p = temp;

        while(p->next != NULL && p->next->next != NULL){
            ListNode* t1 = p;
            p = p->next;
            t1->next = p->next;

            ListNode* t2 = p->next->next;
            p->next->next = p;
            p->next = t2;
        }

        return temp->next;
    }
};
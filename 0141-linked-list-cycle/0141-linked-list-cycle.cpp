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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next || !head->next->next)
            return false;
        ListNode *hare = head, *tort = head;
        hare = hare->next->next;
        tort = tort->next;
        while(hare && tort){
            if(hare == tort)
                return true;
            if(!hare->next || !hare->next->next)
                return false;
            tort = tort->next;
            hare = hare->next->next;
        }
        return false;
    }
};
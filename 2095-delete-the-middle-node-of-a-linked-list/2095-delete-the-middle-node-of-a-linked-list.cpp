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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next)
            return nullptr;
        ListNode* tr = head;
        int cnt = 0;
        while(tr){
            cnt++;
            tr = tr->next;
        }
        tr = new ListNode(0, head);
        for(int i = 0; i < cnt/2; i++, tr = tr->next);
        ListNode* dlt = tr->next;
        tr->next = tr->next->next;
        delete(dlt);
        return head;
    }
};
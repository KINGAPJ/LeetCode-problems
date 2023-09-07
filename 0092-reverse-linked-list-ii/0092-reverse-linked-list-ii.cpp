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
    ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode *pre = NULL, *next = NULL, *temp = head;
        while(head != end){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        temp->next = end;
        return pre;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next)
            return head;
        ListNode *st = new ListNode(), *en = head, *ret = NULL;
        st->next = head, ret = st;
        for(int i = 0; i < left - 1; i++)
            st = st->next;
        for(int i = 0; i < right - 1; i++)
            en = en->next;
        st->next = reverse(st->next, en->next);
        return ret->next;
    }
};
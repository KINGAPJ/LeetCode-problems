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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *kth = nullptr, *trav = head;
        int n = 0;
        while(trav){
            n++;
            if(n == k)
                kth = trav;
            trav = trav->next;
        }
        trav = head;
        for(int i = 0; i < n-k; i++, trav = trav->next);
        swap(trav->val, kth->val);
        return head;
    }
};
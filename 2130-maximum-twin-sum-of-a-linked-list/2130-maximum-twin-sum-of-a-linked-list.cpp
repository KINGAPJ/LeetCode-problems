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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* trav = head;
        while(trav){
            trav = trav->next;
            n++;
        }
        int ans[n/2];
        memset(ans, 0, sizeof(ans));
        trav = head;
        for(int i = 0; i < n/2; i++, trav = trav->next);
        for(int i = 0; i < n/2; i++){
            ans[i] += head->val;
            head = head->next;
            ans[n/2-1-i] += trav->val;
            trav = trav->next;
        }
        return *max_element(ans, ans+n/2);
    }
};
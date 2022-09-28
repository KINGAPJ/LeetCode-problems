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
        ListNode *ans = new ListNode(), *trav = new ListNode();
        trav = head;
        int len = 0;
        while(trav){
            trav = trav->next; len++;
        }
        ans->next = head, trav = ans;
        while(len != n){
            trav = trav->next;
            len--;
        }
        trav->next = trav->next->next;
        return ans->next;
    }
};
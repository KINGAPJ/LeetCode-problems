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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less = new ListNode();
        ListNode *more = new ListNode();
        ListNode *lesstrav = less, *moretrav = more, *trav = head;
        while(trav){
            if(trav->val < x){
                lesstrav->next = trav;
                lesstrav = lesstrav->next;                
            }else{
                moretrav->next = trav;
                moretrav = moretrav->next;
            }
            trav = trav->next;
        }
        moretrav->next = NULL;
        lesstrav->next = more->next;
        return less->next;
    }
};
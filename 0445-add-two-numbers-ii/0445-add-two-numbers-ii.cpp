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
    /*
        recursion: O(n) time and O(n) space(equalising is O(n) auxiliary.. recursion is
        O(n) stack space)
        Step 1. make length equal using dummy nodes
        Step 2. pass carry by reference by adding recursively to l1 after going to tail nodes
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        // Step 1:
        int len1 = 0, len2 = 0;
        ListNode *trav1 = l1, *trav2 = l2;
        while(trav1){
            len1++; trav1 = trav1->next;
        }
        while(trav2){
            len2++; trav2 = trav2->next;
        }
        for(int i = 0; i < (len1 - len2); i++){
            ListNode* dummy = new ListNode();
            dummy->next = l2;
            l2 = dummy;
        }
        for(int i = 0; i < (len2 - len1); i++){
            ListNode* dummy = new ListNode();
            dummy->next = l1;
            l1 = dummy;
        }
        ListNode *dummy1 = new ListNode(), *dummy2 = new ListNode();
        dummy1->next = l1; l1 = dummy1;
        dummy2->next = l2; l2 = dummy2;
        
        // Step 2:
        int carry = 0;
        recur(l1, l2, carry);
        
        if(l1->val == 0)
            return l1->next;
        return l1;
    }
    void recur(ListNode* l1, ListNode* l2, int& carry){
        if(!l1 || !l2)
            return;
        recur(l1->next, l2->next, carry);
        l1->val += l2->val + carry;
        carry = l1->val/10;
        l1->val %= 10;
    }
};

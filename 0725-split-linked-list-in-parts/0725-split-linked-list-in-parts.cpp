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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        ListNode* trav = head;
        vector<ListNode*> ans;
        while(trav){
            cnt++;
            trav = trav->next;
        }
        int extra = cnt % k;
        int nodes = cnt/k;
        trav = head;
        while(extra--){
            ListNode* start = trav;
            for(int i = 0; i < (nodes+1)-1; i++){
                trav = trav->next;
            }
            ListNode* end = trav;
            trav = trav->next;
            end->next = NULL;
            ans.push_back(start);
        }
        while(trav){
            ListNode* start = trav;
            for(int i = 0; i < nodes-1; i++){
                trav = trav->next;
            }
            ListNode* end = trav;
            trav = trav->next;
            end->next = NULL;
            ans.push_back(start);
        }
        while(ans.size() < k){
            ans.push_back(NULL);
        }
        return ans;
    }
};
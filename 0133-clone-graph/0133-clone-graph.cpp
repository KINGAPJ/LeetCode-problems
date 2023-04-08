/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* root;
    unordered_map<int, Node*> vis;
public:
    void dfs(Node* node){
        vis.insert({node->val, node});
        vector<Node*> currNbr;
        for(auto &i: node->neighbors){
            Node* nbr = NULL;
            if(!vis.count(i->val)){
                nbr = new Node(i->val, i->neighbors);
                dfs(nbr);
            }else
                nbr = vis[i->val];
            currNbr.push_back(nbr);
        }
        node->neighbors = currNbr;
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        root = new Node(node->val, node->neighbors);
        dfs(root);
        return root;
    }
};
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
    map<int, Node*> vis;
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
    void bfs(Node* node){
        queue<Node*> q;
        // vis.insert({node->val, node});
        q.push(node);
        while(q.size()){
            auto u = q.front();
            q.pop();
            vis.insert({u->val, u});
            vector<Node*> currNbr;
            for(auto &i: u->neighbors){
                Node* nbr = NULL;
                if(!vis.count(i->val)){
                    nbr = new Node(i->val, i->neighbors);
                    vis.insert({i->val, nbr});
                    q.push(nbr);
                }else
                    nbr = vis[i->val];
                currNbr.push_back(nbr);
            }
            u->neighbors = currNbr;
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        root = new Node(node->val, node->neighbors);
        // dfs(root);
        bfs(root);
        return root;
    }
};
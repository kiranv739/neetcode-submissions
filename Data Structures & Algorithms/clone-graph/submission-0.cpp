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
public:
    void dfs(Node* node,unordered_map<Node*,Node*>& m){
        
        for(auto n:node->neighbors){
            if(m.find(n)==m.end()){
                Node* clone = new Node(n->val);
                m[n] = clone;
                m[node]->neighbors.push_back(m[n]);
                dfs(n,m);
            }
            else{
                m[node]->neighbors.push_back(m[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*,Node*> m;
        Node* clone_node = new Node(node->val);
        m[node] = clone_node;

        dfs(node,m);

        return clone_node;
    }
};

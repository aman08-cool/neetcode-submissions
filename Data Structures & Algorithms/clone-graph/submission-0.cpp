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
    unordered_map<Node*, Node*> mp;
    Node* dfs(Node* node){
        //if node already cloned , return its copy
        if(mp.count(node)){
            return mp[node];
        }
        //create a new node with same value
        Node* clone = new Node(node->val);
        //store in map
        mp[node] = clone;

        //Clone all neighbor
        for(auto n : node->neighbors){
            clone->neighbors.push_back(dfs(n));
        }
        return clone;
        
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        return dfs(node);
    }
};

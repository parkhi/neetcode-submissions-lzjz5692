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
    Node* dfs (Node* node, unordered_map<Node*,Node*>& copy) {
        if(node == nullptr) {
            return nullptr;
        }

        if(copy.count(node)) {
            return copy[node];
        }

        Node* newnode = new Node(node->val);
        copy.insert({node , newnode});

        for(Node* ad : node->neighbors) {            
            newnode->neighbors.push_back(dfs(ad, copy));
        }

        return newnode;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> copy;

        return dfs(node , copy);
        
    }
};

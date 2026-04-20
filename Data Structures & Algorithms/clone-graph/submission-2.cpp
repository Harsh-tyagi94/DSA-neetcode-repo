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
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*, Node*> ump;
        queue<Node*> q;
        q.push(node);
        Node* clone = new Node(node->val);
        ump[node] = clone;

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            for(auto neigh:curr->neighbors) {
                if(ump.find(neigh) == ump.end()) {
                    Node* newnode = new Node(neigh->val);
                    ump[neigh] = newnode;
                    q.push(neigh);
                }
                ump[curr]->neighbors.push_back(ump[neigh]);
            }
        }
        return ump[node];
    }
};

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
private:
    Node* helper(Node* node,unordered_map<Node*,Node*>& mp){
        if(node==nullptr){
            return nullptr;
        }
        vector<Node*> res;
        Node* clone=new Node(node->val);
        mp[node]=clone;
        for(auto neighbour:node->neighbors){
            if(mp.find(neighbour)!=mp.end()){
                res.push_back(mp[neighbour]);
            }
            else{
                res.push_back(helper(neighbour,mp));
            }
            clone->neighbors=res;
        }
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        return helper(node,mp);
    }
};

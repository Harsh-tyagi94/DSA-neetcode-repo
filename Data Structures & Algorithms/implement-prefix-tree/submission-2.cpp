class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;

    TrieNode() {
        for(int i=0;i<26;i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        if(search(word)) return;
        TrieNode* curr = root;
        for(auto w:word) {
            if(curr->children[w-'a'] == NULL) {
                curr->children[w-'a'] = new TrieNode();
            }
            curr = curr->children[w-'a'];
        }
        curr->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto w:word) {
            int i = w-'a';
            if(curr->children[i] == NULL) return false;
            curr = curr->children[i];
        }
        return curr->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto w:prefix) {
            int i = w-'a';
            if(curr->children[i] == NULL) return false;
            curr = curr->children[i];
        }
        return true;
    }
};

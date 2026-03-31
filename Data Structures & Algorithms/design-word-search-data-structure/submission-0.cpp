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

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return dfs(word,0,root);
    }

    bool dfs(string& word,int pos,TrieNode* node) {

        TrieNode* curr = node;

        for(int k=pos ; k<word.size() ; k++) {
            char w = word[k];
            if(w == '.') {
                for(int i=0 ; i<26 ; i++) {
                    if(curr->children[i] && dfs(word,k+1,curr->children[i])) {
                        return true;
                    }
                }
                return false;
            } else {
                if(curr->children[w-'a'] == nullptr) return false;
            }
            curr = curr->children[w-'a'];
        }

        return curr->isTerminal;
    }
};

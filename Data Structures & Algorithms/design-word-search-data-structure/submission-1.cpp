class TrieNode {
    TrieNode* characters[26];
    bool isWord;
public:
    TrieNode() {
        for(int i=0;i<26;i++) characters[i] = nullptr;
        isWord = false;
    }
    friend class WordDictionary;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        if(search(word)) return;
        for(char w:word) {
            int k = w-'a';
            if(curr->characters[k] == nullptr) 
                curr->characters[k] = new TrieNode();
            curr = curr->characters[k];
        }
        curr->isWord = true;
    }
    
    bool searchWithTwist(string word, int index, TrieNode* curr) {
        for(int i=index;i<word.length();i++) {
            int k = word[i]-'a';
            if(word[i] == '.') {
                for(int w=0;w<26;w++) {
                    if(curr->characters[w] && 
                        searchWithTwist(word, i+1, curr->characters[w])) return true;
                }
                return false;
            }
            if(curr->characters[k] == nullptr) return false;
            curr = curr->characters[k];
        }
        return curr->isWord;
    }
    bool search(string word) {
        TrieNode* curr = root;
        return searchWithTwist(word, 0, curr);
    }
};

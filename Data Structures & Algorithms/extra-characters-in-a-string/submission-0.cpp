class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        isWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void addWord(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        for (const string& word : dictionary) {
            trie.addWord(word);
        }

        vector<int> dp(s.size() + 1, -1);
        return dfs(0, s, trie, dp);
    }

private:
    int dfs(int i, const string& s, Trie& trie, vector<int>& dp) {
        if (i == s.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int res = 1 + dfs(i + 1, s, trie, dp);
        TrieNode* curr = trie.root;

        for (int j = i; j < s.size(); ++j) {
            if (!curr->children[s[j] - 'a']) break;
            curr = curr->children[s[j] - 'a'];
            if (curr->isWord) {
                res = min(res, dfs(j + 1, s, trie, dp));
            }
        }

        dp[i] = res;
        return res;
    }
};
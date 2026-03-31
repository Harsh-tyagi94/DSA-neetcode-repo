class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord || find(wordList.begin(),wordList.end(),endWord) == wordList.end()) {
            return 0;
        }

        wordList.push_back(beginWord);

        unordered_map<string,vector<string>> ump;

        for(auto word:wordList) {
            for (int j = 0; j < word.size(); ++j) {
                string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                ump[pattern].push_back(word);
            }
        }

        queue<string> q;
        unordered_set<string> visit{beginWord};
        q.push(beginWord);
        int res = 1;

        while(!q.empty()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return res;
                }
                for (int j = 0; j < word.size(); ++j) {
                    string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                    for (const string& neiWord : ump[pattern]) {
                        if (visit.find(neiWord) == visit.end()) {
                            visit.insert(neiWord);
                            q.push(neiWord);
                        }
                    }
                }
            }
            res++;
        }
        return 0;


    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord || find(wordList.begin(),wordList.end(),endWord) == wordList.end()) {
            return 0;
        }

        wordList.push_back(beginWord);

        unordered_set<string> ust(wordList.begin(), wordList.end());

        unordered_map<string,vector<string>> ump;

        for(auto word:wordList) {
            for(int i=0;i<word.size();i++) {
                for(char c='a';c<='z';c++) {
                    string new_word = word.substr(0,i)+c+word.substr(i+1);
                    if(ust.find(new_word) != ust.end()) {
                        ump[word].push_back(new_word);
                    }
                }
            }
        }

        queue<string> q;
        q.push(beginWord);
        int res = 1;

        while(!q.empty()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                string data = q.front();
                q.pop();

                if(data == endWord) {
                    return res;
                }

                ust.erase(data);

                for(auto nei:ump[data]) {
                    if(ust.find(nei) != ust.end()) {
                        q.push(nei);
                    }
                }
            }
            res++;
        }
        return 0;


    }
};

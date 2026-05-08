class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> qmax;
        if(a) qmax.push({a, 'a'}); 
        if(b) qmax.push({b, 'b'});
        if(c) qmax.push({c, 'c'});
        if(qmax.empty()) return "";
        string res = "";
        
        int cnt = qmax.top().first-1;
        char character = qmax.top().second;
        qmax.pop();
        res += character;
        if(cnt) qmax.push({cnt, character});

        while(!qmax.empty()) {
            int cnt = qmax.top().first-1;
            char character = qmax.top().second;
            qmax.pop();
            if(res[res.length()-1] == character) {
                res += character;
                if(qmax.empty()) return res;
                int newcnt = qmax.top().first-1;
                char newcharacter = qmax.top().second;
                qmax.pop();

                res += newcharacter;
                if(newcnt) qmax.push({newcnt, newcharacter});
                if(cnt) qmax.push({cnt, character});            
            } else {
                res += character;
                if(cnt) qmax.push({cnt, character}); 
            }
        }
        return res;
    }
};
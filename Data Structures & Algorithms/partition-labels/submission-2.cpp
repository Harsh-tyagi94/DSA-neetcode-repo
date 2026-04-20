class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<int> character_last_occurance_index(26,-1);

        for(int i=0;i<s.length();i++) {
            character_last_occurance_index[s[i]-'a'] = i;
        }

        int start_index = -1;
        int curr_index = 0;
        for(int i=0;i<s.length();i++) {
            curr_index = max(curr_index,character_last_occurance_index[s[i]-'a']);
            if(curr_index == i) {
                res.push_back(curr_index - start_index);
                start_index = i;
            }
        }

        return res;
    }
};

/*
map {
    v: 0,
    h: 1,
    a: 9,
    g: 5,
    b: 6,
    q: 10,
    k: 8
}

res = [1, 1, 8]
start_index = 1;
curr_index = 10;
s = vhaagbqkaq
      ^


s = "ababcbacadefegdehijhklij"
     ^

res {
    a: 8,
    b: 5,
    c: 7,
    d: 14,
    e: 15,
    f: 11,
    g: 13,
    h: 19,
    i: 22,
    j: 23,
    k: 20,
    l: 21
}

s = "ababcbacadefegdehijhklij"
             ^

i = 1;
index = 8;

*/
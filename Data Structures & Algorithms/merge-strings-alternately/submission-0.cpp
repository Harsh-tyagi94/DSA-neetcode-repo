class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(),n2 = word2.size();
        string merged_word;
        int l1 = 0,l2 = 0;
        while(l1<n1 && l2 < n2) {
            if(l1 == l2) {
                merged_word += word1[l1];
                l1++;
            } else {
                merged_word += word2[l2];
                l2++;
            }
        }
        while(l1<n1) {
            merged_word += word1[l1];
            l1++;
        }
        while(l2<n2) {
            merged_word += word2[l2];
            l2++;
        }
        return merged_word;
    }
};
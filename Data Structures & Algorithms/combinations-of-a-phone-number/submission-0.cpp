class Solution {
private:
    void back_track(vector<string>& vec,string& digits,string& s,string mapping[],int idx){
        if(idx>=digits.length()){
            vec.push_back(s);
            return;
        }
        int num=digits[idx]-'0';
        string val=mapping[num];
        for(int i=0;i<val.length();i++){
            s.push_back(val[i]);
            back_track(vec,digits,s,mapping,idx+1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vec;
        if(digits.length()<=0)
        return vec;
        string s;
        string mapp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        back_track(vec,digits,s,mapp,0);
        return vec;
    }
};
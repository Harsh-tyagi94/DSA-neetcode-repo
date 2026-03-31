class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> ump;
        for(auto i:nums){
            ump[i]=true;
        }
        for(auto i:nums){
            if(ump.count(i-1)>0){
                ump[i]=false;
            }
        }
        int maxlen=0;
        for(auto i:nums){
            if(ump[i]==true){
                int j=0,count=0;
                while(ump.count(i+j)>0){
                    j++;
                    count++;
                }
                if(count>maxlen){
                    maxlen=count;
                }
            }
        }
        return maxlen;
    }
};
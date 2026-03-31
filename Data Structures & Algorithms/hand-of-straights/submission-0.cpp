class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0){
            return false;
        }
        map<int,int> mp;
        for(auto i:hand){
            mp[i]++;
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            // If this card is part of a group (i.e., its count is not zero)
            if (it->second > 0) {
                int count = it->second;
                // Check the next groupSize - 1 cards
                for (int i = 0; i < groupSize; ++i) {
                    if (mp[it->first + i] < count) {
                        return false;
                    }
                    mp[it->first + i] -= count;
                }
            }
        }

        return true;
    }
};
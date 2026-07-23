class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size()-1;

        int boats = 0;
        while(l <= r) {
            if(l!=r && people[l] + people[r] <= limit) l += 1;
            r -= 1;
            boats += 1;
        }
        return boats;
    }
};
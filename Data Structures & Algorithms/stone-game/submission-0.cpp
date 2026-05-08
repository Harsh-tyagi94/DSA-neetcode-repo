class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int alice_points = 0, bob_points = 0;
        int l = 0, r = piles.size()-1;
        while(l <= r) {
            if(piles[l] >= piles[r]) {
                alice_points += piles[l];
                l += 1;
            } else {
                alice_points += piles[r];
                r -= 1;
            }

            if(l > r) break;

            if(piles[l] >= piles[r]) {
                bob_points += piles[r];
                r -= 1;
            } else {
                bob_points += piles[l];
                l += 1;
            }
        }

        return alice_points > bob_points ? true : false;
    }
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1) return 1;
        vector<int> preCandies(n, 1), suffCandies(n, 1);
        for(int i=0;i<n-1;i++) {
            //prefix
            if(ratings[i+1] > ratings[i]) preCandies[i+1] += preCandies[i];
        }
        for(int i=n-2;i>=0;i--) {
            //suffix
            if(ratings[i] > ratings[i+1]) suffCandies[i] += suffCandies[i+1];
        }
        int sum = 0;
        for(int i=0;i<n;i++) {
            cout<<preCandies[i]<<" "<<suffCandies[i]<<endl;
            sum += max(preCandies[i], suffCandies[i]);
        }
        return sum;
    }
};

/*
[4,3,4,5,6,1,1,2,0,1]
                   ^

[1 1 2 3 4 1 1 2 1 2]
[2 1 1 1 2 1 1 2 1 1]


[1,0,2,1,1,5,4,3,4]


[1 1 2 1 1 2 1 1 1 2]
[2 1 2 1 1 4 3 2 1 1]
*/
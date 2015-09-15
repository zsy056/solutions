/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 0);
        for (int i=0; i<n; ++i) {
            if ((i == 0 || ratings[i] <= ratings[i-1]) && (i == n-1 || ratings[i] <= ratings[i+1])) {
                candies[i] = 1;
                for (int j=i+1; j<n; ++j) {
                    if (ratings[j-1] < ratings[j]) {
                        candies[j] = max(candies[j], (ratings[j-1] == ratings[j] ? 0 : 1) + candies[j-1]);
                    } else {
                        break;
                    }
                }
                for (int j=i-1; j>=0; --j) {
                    if (ratings[j+1] < ratings[j]) {
                        candies[j] = max(candies[j], (ratings[j+1] == ratings[j] ? 0 : 1) + candies[j+1]);
                    } else {
                        break;
                    }
                }
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

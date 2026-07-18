class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());

        while (mini) {
            int rem = maxi % mini;
            maxi = mini;
            mini = rem;
        }

        return maxi;
    }
};
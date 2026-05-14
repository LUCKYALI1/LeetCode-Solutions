class Solution {
public:
    bool isGood(vector<int>& nums) {

        int mx = *max_element(nums.begin(), nums.end());

        // Size must be mx + 1
        if(nums.size() != mx + 1)
            return false;

        vector<int> freq(mx + 1, 0);

        for(int x : nums) {

            // invalid number
            if(x > mx || x < 1)
                return false;

            freq[x]++;
        }

        // max element should appear twice
        if(freq[mx] != 2)
            return false;

        // 1 to mx-1 should appear exactly once
        for(int i = 1; i < mx; i++) {
            if(freq[i] != 1)
                return false;
        }

        return true;
    }
};

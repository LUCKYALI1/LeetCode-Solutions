class Solution {
public:
    
    bool isNonDecreasing(vector<long long> &nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        vector<long long> arr(nums.begin(), nums.end());
        int operations = 0;

        while (!isNonDecreasing(arr)) {
            int n = arr.size();
            long long minSum = LLONG_MAX;
            int idx = 0;

            // 1. Find minimum sum adjacent pair
            for (int i = 0; i < n - 1; i++) {
                long long s = arr[i] + arr[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            // 2. Merge arr[idx] and arr[idx+1]
            vector<long long> newArr;
            for (int i = 0; i < idx; i++)
                newArr.push_back(arr[i]);

            newArr.push_back(minSum);

            for (int i = idx + 2; i < n; i++)
                newArr.push_back(arr[i]);

            arr = newArr;
            operations++;
        }

        return operations;
    }
};

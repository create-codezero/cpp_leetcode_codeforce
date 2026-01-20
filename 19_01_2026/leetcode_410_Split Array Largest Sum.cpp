class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = 0, high = 0;
        for (int x : nums) {
            low = max(low, (long long)x);
            high += x;
        }
        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long curr = 0;
            int parts = 1;
            for (int x : nums) {
                if (curr + x > mid) {
                    parts++;
                    curr = x;
                } else {
                    curr += x;
                }
            }
            if (parts > k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
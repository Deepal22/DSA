class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 1;
        for (auto& [key, val] : freq) {
            int low = key - k;
            int high = key + k;
            int left = lower_bound(nums.begin(), nums.end(), low) - nums.begin();
            int right = upper_bound(nums.begin(), nums.end(), high) - nums.begin();
            int in_range = right - left;
            int visited = in_range - val;
            int min_loop = min(visited, numOperations);
            ans = max(ans, val + min_loop);
        }

        int l = 0;
        for (int r = 0; r < n; r++) {
            while (l <= r && nums[r] - nums[l] > 2 * k) {
                l++;
            }
            int w = r - l + 1;
            ans = max(ans, min(w, numOperations));
        }

        return ans;
    }
};
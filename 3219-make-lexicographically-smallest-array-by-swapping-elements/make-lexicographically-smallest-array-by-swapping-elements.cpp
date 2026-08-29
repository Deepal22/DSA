#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums[i], i};
        }

        // 1. Sort contiguous pairs for optimal cache performance
        sort(pairs.begin(), pairs.end());

        vector<int> group_indices;
        group_indices.reserve(n);

        // 2. Process each component in contiguous blocks
        for (int l = 0; l < n; ) {
            int r = l + 1;
            while (r < n && pairs[r].first - pairs[r - 1].first <= limit) {
                ++r;
            }

            // Collect and sort original indices for component block [l, r)
            group_indices.clear();
            for (int i = l; i < r; ++i) {
                group_indices.push_back(pairs[i].second);
            }
            sort(group_indices.begin(), group_indices.end());

            // 3. Write back directly in-place
            for (int i = 0; i < group_indices.size(); ++i) {
                nums[group_indices[i]] = pairs[l + i].first;
            }

            l = r;
        }

        return nums;
    }
};
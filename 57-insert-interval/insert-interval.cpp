class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }

        int n = intervals.size();
        int target = newInterval[0];
        int left = 0, right = n - 1;

        //binary search
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (intervals[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        //insert newInterval at the location
        intervals.insert(intervals.begin() + left, newInterval);

        vector<vector<int>> res;

        for (const auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};